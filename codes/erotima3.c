#include <stdio.h>
#include <stdlib.h>

int main()
{
	int metritis;
	int pids;

	printf("A 5 parent child chain is created: \n \n");

	for(metritis=0;metritis<5;metritis++){
	pids=fork();

	if(pids>0)
	{
			printf("My PID: %d \n My Parent's PID: %d \n", getpid(),	getppid());
			wait(NULL); //wait for a child to terminate.
			break;
	}

}
return 0;
}
