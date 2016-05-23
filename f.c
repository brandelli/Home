#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
 
int main(){
  pid_t pid;
  pid_t ppid;
  fork();
  fork();
  printf("Neto \n");
  printf("meu pid %d, pid do meu pai %d \n",getpid(),fork());  
  wait(NULL);

  return 0;
}
