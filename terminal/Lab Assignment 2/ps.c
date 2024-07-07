#include "myheader.h"
int ps_T(){
       DIR *dir_proc;
       struct dirent *run_prcs;
       char cmd_file[1024];
       char stat_file[1024];
       char *tty_flnm=ttyname(STDIN_FILENO);
       char tty_nwnm[100];
       char path[1024];
       strcpy(tty_nwnm,"/dev/");
       strcat(tty_nwnm,&tty_flnm[5]);//tty_nwnm indicates in which terminal we are working
       
       
       //char *CMD;
       
       dir_proc = opendir("/proc");
       if(dir_proc!=NULL){
               printf("PID\tSPID\tTTY\tTIME\tCMD\n");
               while((run_prcs=readdir(dir_proc))!=NULL){
                      if(run_prcs->d_type == DT_DIR && isdigit(run_prcs->d_name[0])){
                                pid_t pid=atoi(run_prcs->d_name);
                                char ttypath[1024];
                                strcpy(ttypath,"/proc/");
                                strcat(ttypath,run_prcs->d_name);
                                strcat(ttypath,"/fd/0");
                                
                                char ter_path_prcs[1024];
                                int n=readlink(ttypath,ter_path_prcs,sizeof(ter_path_prcs)-1);
                                
                                if(n!= -1){
                                     ter_path_prcs[n]='\0';
                                }
                                if(strcmp(ter_path_prcs,tty_nwnm)==0){
                                
                                pid_t spid=getsid(pid);
                                sprintf(path,"/proc/%d/stat",pid);
                                FILE *file=fopen(path,"r");
                                if(file!=NULL){
                                       char line[256];
                                       if(fgets(line,256,file)!=NULL){
                                            char *pch;
            				   pch = strtok(line, " ");
            				   for (int i = 1; i < 13; i++) {
               					 pch = strtok(NULL, " ");
           			           }
           				unsigned long utime = strtol(pch, NULL, 10);
            				pch = strtok(NULL, " ");
            				unsigned long stime = strtol(pch, NULL, 10);
            				
            				double cpu_time = (utime + stime) / (double)sysconf(_SC_CLK_TCK);
                                         int H=(int)cpu_time/3600;

					int M=((int)cpu_time%3600)/60;

					int S=(((int)cpu_time%3600)%60);
					        //printf("aaaa\n");
                                        	printf("%d\t",pid);
                                         	printf("%d\t",spid);
                                         	printf("%s\t",&ter_path_prcs[5]);
						printf("%d:%d:%d\t",H,M,S);
                                        

                                       }
                                       
                                }
                                else{
                                       printf("Error in opening stat file.\n");
                                       return 0;
                                }
                                fclose(file);
                                
                                sprintf(cmd_file,"/proc/%d/cmdline", pid);
                                FILE *file1=fopen(cmd_file,"r");
                                if(file1!=NULL){
                                       char line[256];
                                       if(fgets(line,256,file1)!=NULL){
                                             char *cmd=strrchr(line,'/');
                                             if(cmd==NULL){
                                                 cmd=line;
                                                 //printf("error\n");
                                             }
                                             else{
                                                 cmd++;
                                             }
                                             
                                                  //printf("hallo\n");
                                                  printf("%s\n",cmd);
                                             
                                       }
                                      // printf("hi\n");

                                }
                                else{
                                       printf("Error in opening cmdline file.\n");
                                       return 0;
                                }
                                fclose(file1);
                                
                      }
                   }   
               }
       }
       return 0;
}

int ps(){
       DIR *dir_proc;
       struct dirent *run_prcs;
       char cmd_file[1024];
       char stat_file[1024];
       char *tty_flnm=ttyname(STDIN_FILENO);
       char tty_nwnm[100];
       char path[1024];
       strcpy(tty_nwnm,"/dev/");
       strcat(tty_nwnm,&tty_flnm[5]);//tty_nwnm indicates in which terminal we are working
       
       dir_proc = opendir("/proc");
       if(dir_proc!=NULL){
               printf("PID\tTTY\tTIME\tCMD\n");
               while((run_prcs=readdir(dir_proc))!=NULL){
                      if(run_prcs->d_type == DT_DIR && isdigit(run_prcs->d_name[0])){
                                pid_t pid=atoi(run_prcs->d_name);
                                char ttypath[1024];
                                strcpy(ttypath,"/proc/");
                                strcat(ttypath,run_prcs->d_name);
                                strcat(ttypath,"/fd/0");
                                
                                char ter_path_prcs[1024];
                                int n=readlink(ttypath,ter_path_prcs,sizeof(ter_path_prcs)-1);
                                
                                if(n!= -1){
                                     ter_path_prcs[n]='\0';
                                }
                                if(strcmp(ter_path_prcs,tty_nwnm)==0){
                                
                                sprintf(path,"/proc/%d/stat",pid);
                                FILE *file=fopen(path,"r");
                                if(file!=NULL){
                                       char line[256];
                                       if(fgets(line,256,file)!=NULL){
                                            char *pch;
            				   pch = strtok(line, " ");
            				   for (int i = 1; i < 13; i++) {
               					 pch = strtok(NULL, " ");
           			           }
           				unsigned long utime = strtol(pch, NULL, 10);
            				pch = strtok(NULL, " ");
            				unsigned long stime = strtol(pch, NULL, 10);
            				
            				double cpu_time = (utime + stime) / (double)sysconf(_SC_CLK_TCK);
                                         int H=(int)cpu_time/3600;

					int M=((int)cpu_time%3600)/60;

					int S=(((int)cpu_time%3600)%60);
					        
                                        	printf("%d\t",pid);
                                         	
                                         	printf("%s\t",&ter_path_prcs[5]);
						printf("%d:%d:%d\t",H,M,S);
                                        

                                       }
                                       
                                }
                                else{
                                       printf("Error in opening stat file.\n");
                                       return 0;
                                }
                                fclose(file);
                                
                                sprintf(cmd_file,"/proc/%d/cmdline", pid);
                                FILE *file1=fopen(cmd_file,"r");
                                if(file1!=NULL){
                                       char line[256];
                                       if(fgets(line,256,file1)!=NULL){
                                             char *cmd=strrchr(line,'/');
                                             if(cmd==NULL){
                                                 cmd=line;
                                                 
                                             }
                                             else{
                                                 cmd++;
                                             }
                                             
                                                  
                                                  printf("%s\n",cmd);
                                             
                                       }
                                      

                                }
                                else{
                                       printf("Error in opening cmdline file.\n");
                                       return 0;
                                }
                                fclose(file1);
                                
                      }
                   }   
               }
       }
       return 0;
}

int ps_e(){
       DIR *dir_proc;
       struct dirent *run_prcs;
       char cmd_file[1024];
       char stat_file[1024];
       char *tty_flnm=ttyname(STDIN_FILENO);
       char tty_nwnm[100];
       char path[1024];
       strcpy(tty_nwnm,"/dev/");
       strcat(tty_nwnm,&tty_flnm[5]);//tty_nwnm indicates in which terminal we are working
       
       dir_proc = opendir("/proc");
       if(dir_proc!=NULL){
               printf("PID\tTTY\tTIME\tCMD\n");
               while((run_prcs=readdir(dir_proc))!=NULL){
                      if(run_prcs->d_type == DT_DIR && isdigit(run_prcs->d_name[0])){
                                pid_t pid=atoi(run_prcs->d_name);
                                char ttypath[1024];
                                strcpy(ttypath,"/proc/");
                                strcat(ttypath,run_prcs->d_name);
                                strcat(ttypath,"/fd/0");
                                
                                char ter_path_prcs[1024];
                                int n=readlink(ttypath,ter_path_prcs,sizeof(ter_path_prcs)-1);
                                
                                if(n!= -1){
                                     ter_path_prcs[n]='\0';
                                }
                                
                                sprintf(path,"/proc/%d/stat",pid);
                                FILE *file=fopen(path,"r");
                                if(file!=NULL){
                                       char line[256];
                                       if(fgets(line,256,file)!=NULL){
                                            char *pch;
            				   pch = strtok(line, " ");
            				   for (int i = 1; i < 13; i++) {
               					 pch = strtok(NULL, " ");
           			           }
           				unsigned long utime = strtol(pch, NULL, 10);
            				pch = strtok(NULL, " ");
            				unsigned long stime = strtol(pch, NULL, 10);
            				
            				double cpu_time = (utime + stime) / (double)sysconf(_SC_CLK_TCK);
                                         int H=(int)cpu_time/3600;

					int M=((int)cpu_time%3600)/60;

					int S=(((int)cpu_time%3600)%60);
					        
                                        	printf("%d\t",pid);
                                         	if(ter_path_prcs!=NULL){
                                         	printf("%s\t",&ter_path_prcs[5]);}
                                         	else{printf("?\t");}
						printf("%d:%d:%d\t",H,M,S);
                                        

                                       }
                                       
                                }
                                else{
                                       printf("Error in opening stat file.\n");
                                       return 0;
                                }
                                fclose(file);
                                
                                sprintf(cmd_file,"/proc/%d/cmdline", pid);
                                FILE *file1=fopen(cmd_file,"r");
                                if(file1!=NULL){
                                       char line[256];
                                       if(fgets(line,256,file1)!=NULL){
                                             char *cmd=strrchr(line,'/');
                                             if(cmd==NULL){
                                                 cmd=line;
                                                 
                                             }
                                             else{
                                                 cmd++;
                                             }
                                             
                                                  
                                                  printf("%s\n",cmd);
                                             
                                       }
                                      

                                }
                                else{
                                       printf("Error in opening cmdline file.\n");
                                       return 0;
                                }
                                fclose(file1);
                                
                      
                   }   
               }
       }
       return 0;
}

int ps_eT(){
       DIR *dir_proc;
       struct dirent *run_prcs;
       char cmd_file[1024];
       char stat_file[1024];
       char *tty_flnm=ttyname(STDIN_FILENO);
       char tty_nwnm[100];
       char path[1024];
       strcpy(tty_nwnm,"/dev/");
       strcat(tty_nwnm,&tty_flnm[5]);//tty_nwnm indicates in which terminal we are working
       
       dir_proc = opendir("/proc");
       if(dir_proc!=NULL){
               printf("PID\tSPID\tTTY\tTIME\tCMD\n");
               while((run_prcs=readdir(dir_proc))!=NULL){
                      if(run_prcs->d_type == DT_DIR && isdigit(run_prcs->d_name[0])){
                                pid_t pid=atoi(run_prcs->d_name);
                                char ttypath[1024];
                                strcpy(ttypath,"/proc/");
                                strcat(ttypath,run_prcs->d_name);
                                strcat(ttypath,"/fd/0");
                                
                                char ter_path_prcs[1024];
                                int n=readlink(ttypath,ter_path_prcs,sizeof(ter_path_prcs)-1);
                                
                                if(n!= -1){
                                     ter_path_prcs[n]='\0';
                                }
                                pid_t spid=getsid(pid);
                                sprintf(path,"/proc/%d/stat",pid);
                                FILE *file=fopen(path,"r");
                                if(file!=NULL){
                                       char line[256];
                                       if(fgets(line,256,file)!=NULL){
                                            char *pch;
            				   pch = strtok(line, " ");
            				   for (int i = 1; i < 13; i++) {
               					 pch = strtok(NULL, " ");
           			           }
           				unsigned long utime = strtol(pch, NULL, 10);
            				pch = strtok(NULL, " ");
            				unsigned long stime = strtol(pch, NULL, 10);
            				
            				double cpu_time = (utime + stime) / (double)sysconf(_SC_CLK_TCK);
                                         int H=(int)cpu_time/3600;

					int M=((int)cpu_time%3600)/60;

					int S=(((int)cpu_time%3600)%60);
					        
                                        	printf("%d\t",pid);
                                         	printf("%d\t",spid);
                                         	if(ter_path_prcs!=NULL){
                                         	printf("%s\t",&ter_path_prcs[5]);}
                                         	else{printf("?\t");}
						printf("%d:%d:%d\t",H,M,S);
                                        

                                       }
                                       
                                }
                                else{
                                       printf("Error in opening stat file.\n");
                                       return 0;
                                }
                                fclose(file);
                                
                                sprintf(cmd_file,"/proc/%d/cmdline", pid);
                                FILE *file1=fopen(cmd_file,"r");
                                if(file1!=NULL){
                                       char line[256];
                                       if(fgets(line,256,file1)!=NULL){
                                             char *cmd=strrchr(line,'/');
                                             if(cmd==NULL){
                                                 cmd=line;
                                                 
                                             }
                                             else{
                                                 cmd++;
                                             }
                                             
                                                  
                                                  printf("%s\n",cmd);
                                             
                                       }
                                      

                                }
                                else{
                                       printf("Error in opening cmdline file.\n");
                                       return 0;
                                }
                                fclose(file1);
                                
                      
                   }   
               }
       }
       return 0;
}




