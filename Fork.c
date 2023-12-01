#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
 int main()
{
  Pid_t P;
  p=fork();
  if (p== -1){
    printf("error");
  }
  if (p==0){
    printf("%d",getpid()):
    printf("child\n");
  }
  else{
    printf("%d",getpid()):
    printf("parent\n");
    
    
  }
}
