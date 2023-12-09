int main(){
    char strBin[] = "1101001110001";

    int maxLength=0;

    int binVar[2];

    binVar[0]=-1;
    binVar[1]=-1;
    int start=0;
    for(int end=0;end<strlen(strBin);end++){

        if(binVar[strBin[end]]!=-1){
            start = binVar[strBin[end]]+1;
        }
        binVar[strBin[end]]=end;

        if(end-start+1>maxLength){
           maxLength = end-start+1;
        }
    }
    printf("%d",maxLength);
}
