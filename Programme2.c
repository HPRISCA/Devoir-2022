#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc , char *argv[]){
  pid_t pid = fork();
  if(pid < 0){
    /* Arrêt du programme en cas d'erreur*/
    fprintf(stderr, "Erreur de création du processus (%d) (%d)\n", pid, errno);
    return 1;
  }
  if(pid == 0){
     /* Processus fils*/
     printf("je suis le fils (%d), mon père est(%d)\n ",getpid(), getppid());
  }else{
int h;
pid_t pid2=wait(&h);
   /*Processus père*/
    printf("Je suis le père (%d) ,mon fils que je viens de créer est (%d)\n", getpid(),pid);
  }
  
  return 0;
}
