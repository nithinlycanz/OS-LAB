#include<stdio.h>
#include<unistd.h>
int main()
{
printf("in execv/n");
printf("pid execv.c = %d\n", getpid());
char * args[]={"/bin/ls","-l",NULL};
execv(args[0],args);
perror("return");
printf("back");
}
