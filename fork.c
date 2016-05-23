#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
 
int main(){
  pid_t pid;
  pid_t ppid;
  printf("PID do programa %d \n ",getpid());
  pid = fork();
  if(pid==0){
     ppid = fork();
     if(ppid == 0){
        printf("Neto \n");
        printf("meu pid %d, retorno fork %d , pid meu pai %d \n",getpid(),ppid,getppid());
     }else{
        wait(NULL);
        printf("Pai \n");
        printf("meu pid %d, retorno fork %d , pid meu pai %d, pid meu filho %d \n",getpid(),ppid,getppid(),ppid);
     }	
  }else{
	wait(NULL);
        printf("Avo \n");
        printf("meu pid %d, retorno fork %d, pid meu filho %d \n",getpid(),pid,pid);
  }

  return 0;
}
