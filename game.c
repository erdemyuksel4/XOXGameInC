#include  <stdio.h>

// player 1 = 1 - X
// player 2 = 2 - O
int cells[9];
void printTheTable();
void printTheTable(){
    int c =0;
    do{
        for(int i = 0;i<3;i++){
            char playerSymbol;
            if(cells[3*c+i]==1){
                printf(" %s ","X");
            }else if (cells[3*c+i]==2){
                printf(" %s ","O");
            }else{
                printf(" %d ",(3*c+i+1));
            }

            if(i!=2){
                printf("|");
            }
        }
        if(c!=2){
            printf("\n---|---|---\n");
        }
        c++;
    }while (c !=3);
}
int findAndChangeCell(int cell,int player){

    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){

            if (3*i+j+1==cell){
                if(cells[3*i+j]==0){
                    cells[3*i+j]= player;
                    return 1;
                }else{
                    return 0;
                }
            }
        }
    }
}
int CrossCheck(){

    int r = 0;


    if(!((cells[9]!=0&&cells[0]!=0&&cells[4]!=0&& cells[4]==cells[0]&&cells[4]==cells[9])||(((cells[6]!=0&&cells[4]!=0&&cells[2]!=0&& cells[4]==cells[2]&&cells[4]==cells[6]))))){

        return 0;
    }

    return 1;
}
int RowCheck(){

    for(int i=0;i<3;i++){
        if(cells[i+3]!=0&&cells[i+6]!=0&&cells[i]!=0&&cells[i+3]==cells[i]&&cells[i+3]==cells[i+3]){
            return 1;
        }
    }
    return 0;
}
int ColumnCheck(){

    for(int i=0;i<3;i++){
        if(cells[3*i+1]!=0&&cells[3*i+2]!=0&&cells[3*i]!=0&&cells[3*i]==cells[3*i+1]&&cells[3*i+1]==cells[3*i+2]){
            return 1;
        }
    }
    return 0;
}
int WinnerCheck(){
    if(1==CrossCheck()){

            return 1;

    }
    if(1==RowCheck()){

            return 1;

    }
    if(1==ColumnCheck()){

            return 1;


    }
    return 0;
}
int AllCellTaken(){
    for (int i = 0; i<9;i++){

        if(cells[i]==0){
            return 0;
        }

    }
    return 1;
}
void main(){
    int choosenCell;
    int currPlayer =1;
    int winner = 0;

    while (winner ==0){
        printf("\nChoose a cell(Player %d - %s)\n",currPlayer,currPlayer==1?"X":"O");
        printTheTable();
        printf("\n");
        scanf("%d",&choosenCell);
        int resultPlay = findAndChangeCell(choosenCell,currPlayer);
        winner = (WinnerCheck()==1)?currPlayer:0;
        if(resultPlay==1){
            currPlayer= currPlayer==1?2:1;
        }else{
            printf("This cell is full. Please try again!");
        }
        if (AllCellTaken()==1&&winner ==0){
            printf("No possible move");
            return NULL;
        }
    }
    printTheTable();
    printf("\nWinner - Player %d Congrats!",winner);
}
