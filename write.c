#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
int main()
{
key_t key = ftok("shmfile",66); //generate unique key
int shmid = shmget(key,1024,0666|IPC_CREAT);// shmget returns an identifier in shmid
char *str = (char*) shmat(shmid,(void*)0,0); // shmat to attach to shared memory
printf("Write Data : ");
gets(str);
printf("Data written in memory: %s\n",str);
shmdt(str); //detach from shared memory 
return 0;
}
