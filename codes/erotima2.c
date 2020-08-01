#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
  int i,tmp; 
  pid_t pid[4];
  
  for(i=0;i<4;i++)
  {
    pid[i]=fork();

    if(pid[i]==0)
    {
     break;
    }
   }

    if(pid[0]!=0 && pid[1]!=0 && pid[2]!=0 && pid[3]!=0)
    {
     printf("I'm the father, pid:%d, parentid:%d\n",getpid(),getppid());
     for(i=0;i<4;i++)
     {
      wait(&tmp);
     }
    }

    else
    {
     printf("I'm a childer, pid:%d, parentid:%d\n",getpid(),getppid());
    }
  
  return (0);
}
