#include<stdio.h>

void printdata(int psize[],int alloc[],int pno){
  printf("process No\tprocess size\tblock no\n");
  for(int i=0;i<pno;i++){
    printf("\n%d\t\t%d",i+1,psize[i]);
    if(alloc[i]!=-1){
      printf("\t\t%d",alloc[i]+1);
    }
    else{
      printf("\t\tNot allocated\n");
    }
  }
}
int main(){
  int pno,psize[20],bno,bsize[20],alloc[20],temp[20],i,j;
  printf("Enter number of process:");
  scanf("%d",&pno);
  printf("Enter number of blocks:");
  scanf("%d",&bno);
  printf("Enter process size:");
  for(i=0;i<pno;i++){
    scanf("%d",&psize[i]);
  }
  printf("Enter block size:");
  for(i=0;i<bno;i++){
    scanf("%d",&bsize[i]);
  }
  for(i=0;i<bno;i++){
   temp[i]=bsize[i];
  }
  //firstFit
  
  for(i=0;i<pno;i++){
    alloc[i]=-1;
  }
  for(i=0;i<pno;i++){
    for(j=0;j<bno;j++){
      if(bsize[j]>=psize[i]){
        alloc[i]=j;
        bsize[j]-=psize[i];
        break;
      }
    }
  }
  printf("\nFirstfit\n");
  printdata(psize,alloc,pno);

//best fit
  for(i=0;i<bno;i++){
   bsize[i]=temp[i];
   alloc[i]=-1;
  }
  for(i=0;i<pno;i++){
    int bestblock=-1;
    for(j=0;j<bno;j++){
      if(bsize[j]>=psize[i]){
       if(bestblock==-1){
          bestblock=j;
        }
        else if(bsize[bestblock]>bsize[j]){
          bestblock=j;
        }
      }
      }
      if(bestblock!=-1){
        alloc[i]=bestblock;
        bsize[bestblock]-=psize[i];
      }
   }
  printf("\nBestfit\n");
  printdata(psize,alloc,pno);
  
  //worst fit
  for(i=0;i<bno;i++){
   bsize[i]=temp[i];
   alloc[i]=-1;
  }
  for(i=0;i<pno;i++){
    int bestblock=-1;
    for(j=0;j<bno;j++){
      if(bsize[j]>=psize[i]){
       if(bestblock==-1){
          bestblock=j;
        }
        else if(bsize[bestblock]<bsize[j]){
          bestblock=j;
        }
      }
      }
      if(bestblock!=-1){
        alloc[i]=bestblock;
        bsize[bestblock]-=psize[i];
      }
   }
  printf("\nworstfit\n");
  printdata(psize,alloc,pno);
}

