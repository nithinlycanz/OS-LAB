#include<stdio.h>
int main(){
int n,m,i,j,k,y,max[30][30],alloc[30][30],avail[30],ind=0;
printf("Enter num of processes:");
scanf("%d",&n);
printf("Enter number of resorces:");
scanf("%d",&m);
printf("Enter max matrix\n");
for(i=0;i<n;i++){
	for(j=0;j<m;j++){
	scanf("%d",&max[i][j]);
	}
	}
printf("Enter allocation matrix\n");
for(i=0;i<n;i++){
	for(j=0;j<m;j++){
		scanf("%d",&alloc[i][j]);
		}
		}
printf("Enter available matrix\n");
for(i=0;i<m;i++){
	scanf("%d",&avail[i]);
	}
	
int need[n][m],work[m],finesh[n],safesequence[n];
for(i=0;i<n;i++){
	for(j=0;j<m;j++){
	need[i][j]=max[i][j]-alloc[i][j];
}
}
printf("Need matrix is:\n");
for(i=0;i<n;i++){
printf("\n");
for(j=0;j<m;j++){
	printf("%d",need[i][j]);
	}
	}
for(i=0;i<n;i++){
	work[i]=avail[i];
	}
for(i=0;i<n;i++){
	finesh[i]=0;
}
for(k=0;k<n;k++){
	for(i=0;i<n;i++){
		if(finesh[i]==0){
			int flag=0;
			for(j=0;j<m;j++){
			if(need[i][j]>work[j]){
			flag=1;
			break;
			}
			}
			if(flag==0){
			safesequence[ind++]=i;
			for(y=0;y<m;y++){
			work[y]+=alloc[i][y];
			}
			finesh[i]=1;
			}
			}
			}
			}
	int flg=1;
	for(i=0;i<n;i++){
	if(finesh[i]==0){
		flg=0;
		printf("following is not in safe sequence");
		break;
		}
		}
		if(flg==1){
		for(i=0;i<n;i++){
		if(finesh[i]==0){
			flg=0;
			printf("following is not a safe sequence");
			for(i=0;i<n;i++){
				printf("P%d->",safesequence[i]+1);
				}
				}
				}	
				}
				}	
		
		
	
