#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	printf("Only main() %d\n",getpid());

	pid_t pid0 = fork();

	printf("main() and fork(): %d of %d\n",getpid(),getppid());

	if(pid0==0){
		printf("Only fork(): %d of parent %d\n",getpid(),getppid());
	}
	if(pid0>0){
		printf("main() again %d of %d\n",getpid(),getppid());
	}

	return 0;
}