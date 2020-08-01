#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

//dhmiourgia ths nothing()
void nothing()
{
 int x;
 x=0;
 x=x+1;
 
}

int main()
{
 int i;
 pid_t pid;
 time_t start;
 time_t end;
 
 //ektypwsh twn deyteroleptwn
 start = time(NULL);
 printf("Starting value of seconds:%d\n",start);

 //dhmioyrgia twn 100 diergasiwn
 i=0;
 while(i<100)
 {
  pid=fork();
  if(pid==0)
  {
   printf("My id:%d, parent's id:%d\n",getpid(),getppid());
   exit(0);
  }
  i++;
 }

 //copy-paste
 for(int i=0;i<100;i++)
 {
  wait(NULL); 
 }

 //ektelesh ths waitpid()
 int status, wait;
 for(int i=0;i<100;i++)
 {
  wait = waitpid(pid,&status,0);
  if(wait==0){
   printf("Wait for the process %d to finish\n",getpid());	   
  }
  i++;  
 } 
 
 //ektelesh ths time(), end-start,(end-start)/100
 end=time(NULL);
 printf("Final value of seconds:%d\n",end);
 printf("Total seconds of all process:%d\n",(end-start));
 printf("Seconds per process:%d\n",(end-start)/100);

 return(0);
}
