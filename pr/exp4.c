#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t pid;

	printf("parent process started\n");
	printf("Parent PID: %d\n",getpid());
	pid=fork();
	if(pid<0){
		printf("process creation failed");
		}
	else if(pid==0){
		printf("\nChild Process\n");
		printf("\nChild process\n");
		printf("child pid:%d\n",getpid());
		printf("Parent pid:%d\n",getppid());
		execl("/bin/ls","ls","-l",NULL);
		printf("Exec failed/n");
		}
	else{
		wait(NULL);
		printf("\nChild Process Completed\n");
		printf("parent process exiting\n");
		}
		return 0;
		}



