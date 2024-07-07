#include "myheader.h"
/*#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<readline/readline.h>
#include<readline/history.h>*/

int mv(char* ,char* );
int mv_m(char* ,char* );
int mv_i(char* ,char* );
int mv_v(char* ,char* );
int mv_iv(char* ,char* );
int mv_n(char* ,char* );
int cp(char* ,char* );
int cp_v(char* ,char* );
int cp_i(char* ,char* );
int cp_iv(char* ,char* );
int cp_n(char* ,char* );
int grep(char* ,char* );
int grep_m(char* ,char* );
int grep_l(char* ,char* );
int grep_c(char* ,char* ); 
int ls_l();
int ls_t();
int ls_S();
int ls_U();
int ls();
int ps();
int ps_T();
int ps_e();
int ps_eT();


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
  
                command2=readline(command);
                if(strlen(command2)>0){ add_history(command2);}
                //printf("%s\n",command2);
                
                if(strncmp(command2,"mv -iv",6)==0){
                    
                     char source[100][100];
                      int i=0;
                      char* token=strtok(command2," ");
                      token=strtok(NULL," ");
                      while(token!=NULL){
                              token=strtok(NULL," ");
                              if(token!=NULL){
                              	      i++;
                                      strcpy(source[i],token);
                                      
                              }
                      }
                      if((i==0)||(i==1)){
                              printf("mv: missing file operand\n");
                              printf("Try 'mv --help' for more information.\n");
                      }
                      else if(i==2){
                              mv_iv(source[1],source[2]);
                      }
                }
                
                else if(strncmp(command2,"mv -n",5)==0){
                    
                      char source[100][100];
                      int i=0;
                      char* token=strtok(command2," ");
                      token=strtok(NULL," ");
                      while(token!=NULL){
                              token=strtok(NULL," ");
                              if(token!=NULL){
                              	      i++;
                                      strcpy(source[i],token);
                                      
                              }
                      }
                      if((i==0)||(i==1)){
                              printf("mv: missing file operand\n");
                              printf("Try 'mv --help' for more information.\n");
                      }
                      else if(i==2){
                              mv_n(source[1],source[2]);
                      }
                }
                
                else if(strncmp(command2,"mv -i",5)==0){
                      //printf("mv-i1\n");
                      char source[100][100];
                      int i=0;
                      char* token=strtok(command2," ");
                      token=strtok(NULL," ");
                      while(token!=NULL){
                              token=strtok(NULL," ");
                              if(token!=NULL){
                              	      i++;
                                      strcpy(source[i],token);
                                      
                              }
                      }
                      if((i==0)||(i==1)){
                              printf("mv: missing file operand\n");
                              printf("Try 'mv --help' for more information.\n");
                      }
                      else if(i==2){
                              mv_i(source[1],source[2]);
                      }
                 }
                
                 else if(strncmp(command2,"mv -v",5)==0){
                    // printf("mv-v1\n");
                     char source[100][100];
                      int i=0;
                      char* token=strtok(command2," ");
                      token=strtok(NULL," ");
                      while(token!=NULL){
                              token=strtok(NULL," ");
                              if(token!=NULL){
                              	      i++;
                                      strcpy(source[i],token);
                                      
                              }
                      }
                      if((i==0)||(i==1)){
                              printf("mv: missing file operand\n");
                              printf("Try 'mv --help' for more information.\n");
                      }
                      else if(i==2){
                              mv_v(source[1],source[2]);
                      }
                }
                
                
                else if (strncmp(command2,"mv",2)==0){
                     // printf("mv1\n");
                      char source[100][100];
                      int i=0;
                      char* token=strtok(command2," ");
                      while(token!=NULL){
                              token=strtok(NULL," ");
                              if(token!=NULL){
                              	      i++;
                                      strcpy(source[i],token);
                                      
                              }
                      }
                      if((i==0)||(i==1)){
                              printf("mv: missing file operand\n");
                              printf("Try 'mv --help' for more information.\n");
                      }
                      else if(i==2){
                              mv(source[1],source[2]);
                      }
                      else{
                              for(int y=1;y<i;y++){
                                   if(  mv_m(source[y],source[i])==0){ break;};
                              }   
                      }
                }
               
               else if(strncmp(command2,"cp -iv",6)==0){
                    
                      char source[100][100];
                      int i=0;
                      char* token=strtok(command2," ");
                      token=strtok(NULL," ");
                      while(token!=NULL){
                              token=strtok(NULL," ");
                              if(token!=NULL){
                              	      i++;
                                      strcpy(source[i],token);
                                      
                              }
                      }
                      if((i==0)||(i==1)){
                              printf("cp: missing file operand\n");
                              printf("Try 'cp --help' for more information.\n");
                      }
                      else if(i==2){
                              cp_iv(source[1],source[2]);
                      }
              }
               
              else if(strncmp(command2,"cp -v",5)==0){
                    
                      char source[100][100];
                      int i=0;
                      char* token=strtok(command2," ");
                      token=strtok(NULL," ");
                      while(token!=NULL){
                              token=strtok(NULL," ");
                              if(token!=NULL){
                              	      i++;
                                      strcpy(source[i],token);
                                      
                              }
                      }
                      if((i==0)||(i==1)){
                              printf("cp: missing file operand\n");
                              printf("Try 'cp --help' for more information.\n");
                      }
                      else if(i==2){
                              cp_v(source[1],source[2]);
                      }
              }
              
              else if(strncmp(command2,"cp -n",5)==0){
                    
                      char source[100][100];
                      int i=0;
                      char* token=strtok(command2," ");
                      token=strtok(NULL," ");
                      while(token!=NULL){
                              token=strtok(NULL," ");
                              if(token!=NULL){
                              	      i++;
                                      strcpy(source[i],token);
                                      
                              }
                      }
                      if((i==0)||(i==1)){
                              printf("cp: missing file operand\n");
                              printf("Try 'cp --help' for more information.\n");
                      }
                      else if(i==2){
                              cp_n(source[1],source[2]);
                      }
              }
              
              
              
              else if(strncmp(command2,"cp -i",5)==0){
                    
                      char source[100][100];
                      int i=0;
                      char* token=strtok(command2," ");
                      token=strtok(NULL," ");
                      while(token!=NULL){
                              token=strtok(NULL," ");
                              if(token!=NULL){
                              	      i++;
                                      strcpy(source[i],token);
                                      
                              }
                      }
                      if((i==0)||(i==1)){
                              printf("cp: missing file operand\n");
                              printf("Try 'cp --help' for more information.\n");
                      }
                      else if(i==2){
                              cp_i(source[1],source[2]);
                      }
              }  
                
              else if(strncmp(command2,"cp",2)==0){
                    
                     char source[100][100];
                      int i=0;
                      char* token=strtok(command2," ");
                      
                      while(token!=NULL){
                              token=strtok(NULL," ");
                              if(token!=NULL){
                              	      i++;
                                      strcpy(source[i],token);
                                      
                              }
                      }
                      if((i==0)||(i==1)){
                              printf("cp: missing file operand\n");
                              printf("Try 'cp --help' for more information.\n");
                      }
                      else if(i==2){
                              cp(source[1],source[2]);
                      }
                }
                
                
             else if(strncmp(command2,"grep -l",7)==0){
                       char source[100][100];
                       int count=0;
                       char *string=strchr(command2,'"');
                      
                       if(string != NULL){
                              string++;
                              char *close=strchr(string,'"');
                              if(close !=NULL){
                                      char *files=close;
                                      long x=files-string;
                                      strncpy(source[1],string,x);
                                      int i=1;
                                      char* token=strtok(files," ");
                                      
                                      while(token!=NULL){
                              			token=strtok(NULL," ");
                              			if(token!=NULL){
                              	      			i++;
                                      			strcpy(source[i],token);
                              			}
                      		     }
                      		     count=i;
                                      
                              }
                              else{
                                      continue;
                              }
                       }
                       else{
                              int i=0;
                              char *token=strtok(command2," ");
                              token=strtok(NULL," ");
                              while(token!=NULL){
                              			token=strtok(NULL," ");
                              			if(token!=NULL){
                              	      			i++;
                                      			strcpy(source[i],token);
                                      
                              			}
                      	     }
                      	     count=i;
                              
                      }
                      
                      
                      if((count==1)||(count==0)){
                                 printf("Usage: grep [OPTION]... PATTERNS [FILE]...\n");
                                 printf("Try 'grep --help' for more information.\n");
                      }
                      
                      else{
                      for(int y=2;y<=count;y++){
                               grep_l(source[1],source[y]);
                      }
                      } 
                       
             }
             
             else if(strncmp(command2,"grep -c",7)==0){
                       char source[100][100];
                       int count=0;
                       char *string=strchr(command2,'"');
                      
                       if(string != NULL){
                              string++;
                              char *close=strchr(string,'"');
                              if(close !=NULL){
                                      char *files=close;
                                      long x=files-string;
                                      strncpy(source[1],string,x);
                                      int i=1;
                                      char* token=strtok(files," ");
                                      
                                      while(token!=NULL){
                              			token=strtok(NULL," ");
                              			if(token!=NULL){
                              	      			i++;
                                      			strcpy(source[i],token);
                              			}
                      		     }
                      		     count=i;
                                      
                              }
                              else{
                                      continue;
                              }
                       }
                       else{
                              int i=0;
                              char *token=strtok(command2," ");
                              token=strtok(NULL," ");
                              while(token!=NULL){
                              			token=strtok(NULL," ");
                              			if(token!=NULL){
                              	      			i++;
                                      			strcpy(source[i],token);
                                      
                              			}
                      	     }
                      	     count=i;
                              
                      }
                      
                      
                      if((count==1)||(count==0)){
                                 printf("Usage: grep [OPTION]... PATTERNS [FILE]...\n");
                                 printf("Try 'grep --help' for more information.\n");
                      }
                      
                      else{
                      for(int y=2;y<=count;y++){
                               grep_c(source[1],source[y]);
                      }
                      } 
                       
             }
             
             else if(strncmp(command2,"grep -h",7)==0){
                       char source[100][100];
                       int count=0;
                       char *string=strchr(command2,'"');
                      
                       if(string != NULL){
                              string++;
                              char *close=strchr(string,'"');
                              if(close !=NULL){
                                      char *files=close;
                                      long x=files-string;
                                      strncpy(source[1],string,x);
                                      int i=1;
                                      char* token=strtok(files," ");
                                      
                                      while(token!=NULL){
                              			token=strtok(NULL," ");
                              			if(token!=NULL){
                              	      			i++;
                                      			strcpy(source[i],token);
                              			}
                      		     }
                      		     count=i;
                                      
                              }
                              else{
                                      continue;
                              }
                       }
                       else{
                              int i=0;
                              char *token=strtok(command2," ");
                              token=strtok(NULL," ");
                              while(token!=NULL){
                              			token=strtok(NULL," ");
                              			if(token!=NULL){
                              	      			i++;
                                      			strcpy(source[i],token);
                                      
                              			}
                      	     }
                      	     count=i;
                              
                      }
                      
                      
                      if((count==1)||(count==0)){
                                 printf("Usage: grep [OPTION]... PATTERNS [FILE]...\n");
                                 printf("Try 'grep --help' for more information.\n");
                      }
                      
                      else{
                      for(int y=2;y<=count;y++){
                               grep(source[1],source[y]);
                      }
                      } 
                       
             }
             
             else if(strncmp(command2,"grep",4)==0){
                       char source[100][100];
                       int count=0;
                       char *string=strchr(command2,'"');
                      
                       if(string != NULL){
                              string++;
                              char *close=strchr(string,'"');
                              if(close !=NULL){
                                      char *files=close;
                                      long x=files-string;
                                      strncpy(source[1],string,x);
                                      int i=1;
                                      char* token=strtok(files," ");
                                      
                                      while(token!=NULL){
                              			token=strtok(NULL," ");
                              			if(token!=NULL){
                              	      			i++;
                                      			strcpy(source[i],token);
                              			}
                      		     }
                      		     count=i;
                                      
                              }
                              else{
                                      continue;
                              }
                       }
                       else{
                              int i=0;
                              char *token=strtok(command2," ");
                              while(token!=NULL){
                              			token=strtok(NULL," ");
                              			if(token!=NULL){
                              	      			i++;
                                      			strcpy(source[i],token);
                                      
                              			}
                      	     }
                      	     count=i;
                              
                      }
                      
                      
                      if((count==1)||(count==0)){
                                 printf("Usage: grep [OPTION]... PATTERNS [FILE]...\n");
                                 printf("Try 'grep --help' for more information.\n");
                      }
                      else if(count==2){
                               grep(source[1],source[2]);
                      }
                      else{
                      for(int y=2;y<=count;y++){
                               grep_m(source[1],source[y]);
                      }
                      } 
                       
             }
             
             else if(strcmp(command2,"ls -l")==0){
                      ls_l();
             }
             else if(strcmp(command2,"ls -t")==0){
                      ls_t();
             }
             else if(strcmp(command2,"ls -S")==0){
                      ls_S();
             }
             else if(strcmp(command2,"ls -U")==0){
                      ls_U();
             }
             else if(strcmp(command2,"ls")==0){
                      ls();
             }
             else if(strcmp(command2,"ps")==0){
                      ps();    
             }
             else if(strcmp(command2,"ps -T")==0){
                      ps_T();
             }
             else if(strcmp(command2,"ps -e")==0){
                      ps_e();
             }
             else if(strcmp(command2,"ps -eT")==0){
                      ps_eT();
             }
             else if(strcmp(command2,"ps -Te")==0){
                      ps_eT();
             }
             
             
             
             
            }
            
            
 }
