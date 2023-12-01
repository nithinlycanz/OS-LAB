#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
int w1,wstatus;
pid_t p;
printf("before fork\n");
p=fork();
if(p==0)
{
sleep(3);
printf("i am child having id%d\n",getpid());
printf("my parent's id id %d\n",getpid());
}
else{
w1=wait(&wstatus);
printf("status = %d\n",WIFEXITED(wstatus));
printf("status=%d\n",w1);
wait(NULL);
printf("I AM PARENT HAVING ID %d\n",getpid());

}
printf("common\n");


}
