#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<readline/readline.h>
#include<readline/history.h>
  
int main(){
        char hostname[50];
        gethostname(hostname,50);
        char cwd[100];
        char command[200];
        char *command2;
        char *user;
        user=getlogin();
        getcwd(cwd,100);
        
        
        while(1){
                
               //sprintf(command,"%s@%s:~%s$ ",getlogin(),hostname,cwd);
                strcpy(command,user);
                strcat(command,"@");
                strcat(command,hostname);
                strcat(command,":~");
                strcat(command,cwd);
                strcat(command,"$ ");
                //printf("%s",command);
                
                
                command2=readline(command);
                if(strlen(command2)>0){ add_history(command2);}
                
                if(strcmp(command2,"help")==0){
                     system("bash -c help");
                }
                else if(strcmp(command2,"exit")==0){
                     break;
                }
                else if(system(command2)!=0){ printf("command not found\n");}
                
                
                }
       
        return 0;
}
