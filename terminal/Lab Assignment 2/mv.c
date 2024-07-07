/*#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>*/
#include "myheader.h"


//int mv(char* source,char*destination);

/*int main(){
  	char source[100];
  	char destination[100];
	printf("Enter a source file: ");
	scanf("%s",source);
	printf("Enter a destination file: ");
	scanf("%s",destination);
	mv(source,destination);
	return 0;
	}*/
int mv(char* source,char* destination)
	
{	//printf("mv2\n");
       // printf("source is %s\n",source);
        //printf("destination is %s\n",destination);
        struct stat my_stat;
	
	if(stat(destination, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	        if(stat(source, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	               if (rename(source, destination) != 0) {
            			printf("Error in moving directory\n");
            			return 0;
            			}  
	        }
	        else{
	        char* file_source=strrchr(source,'/');
	        if(file_source ==NULL){
	             file_source=source;
	        }
	        else{
	             file_source++;
	        }
	        char source_newpath[1024];
	        snprintf(source_newpath,sizeof(source_newpath),"%s/%s",destination,file_source);
	        if(rename(source,source_newpath)!=0){
	            printf("Error in moving file\n");
	            return 0;
	        }
	       // printf("new path is %s\n",source_newpath);
	        }
	}
	
	else{
	       if (rename(source, destination) != 0) {
            			printf("Error in moving file\n");
            			return 0;
            			}  
               //printf("destination is %s",destination); 
	}
	
}
int mv_m(char* source,char* destination){
	struct stat my_stat;
	if(stat(destination, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){ 
	        
	        
	        char* file_source=strrchr(source,'/');
	        if(file_source ==NULL){
	             file_source=source;
	        }
	        else{
	             file_source++;
	        }
	        char source_newpath[1024];
	        snprintf(source_newpath,sizeof(source_newpath),"%s/%s",destination,file_source);
	        if(rename(source,source_newpath)!=0){
	            printf("Error in moving file\n");
	            return 0;
	        }
	        }
	else{
	         printf("mv: target '%s' is not a directory\n",destination);
	         return 0;
	}
	     
}
int mv_i(char* source,char* destination){
        // printf("mv-i2\n");
         struct stat my_stat;
	
	if(stat(destination, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	        if(stat(source, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	               if (rename(source, destination) != 0) {
            			printf("Error in moving directory\n");
            			return 0;
            			}  
	        }
	        else{
	        FILE *file_check;
	        char input;
	        char* file_source=strrchr(source,'/');
	        if(file_source ==NULL){
	             file_source=source;
	        }
	        else{
	             file_source++;
	        }
	        char source_newpath[1024];
	        snprintf(source_newpath,sizeof(source_newpath),"%s/%s",destination,file_source);
	        file_check=fopen(source_newpath,"r");
	        if(file_check!=NULL){
	             printf("mv: overwrite '%s'? ",source_newpath);
	             scanf("%s",&input);
	             if((input=='y')||(input=='Y')){
	                 if(rename(source,source_newpath)!=0){
	                      printf("Error in moving file\n");
	                      return 0;
	                 }   
	             }
	             else{
	                 return 0;
	             }
	        }
	        else{
	        if(rename(source,source_newpath)!=0){
	            printf("Error in moving file\n");
	            return 0;
	        }}
	       
	        }
	}
	
	else{
	        
	       if(access(destination,F_OK)==0){
	             char input;
	             printf("mv: overwrite '%s'? ",destination);
	             scanf("%s",&input);
	             if((input=='y')||(input=='Y')){
	                 if(rename(source,destination)!=0){
	                      printf("Error in moving file\n");
	                      return 0;
	                 }   
	             }
	             else{
	                 return 0;
	             }
	       }
	       
	       else{
	       if (rename(source, destination) != 0) {
            			printf("Error in moving file\n");
            			return 0;
            			}  
               }
               //printf("destination is %s",destination); 
	}
	
}

int mv_v(char* source,char* destination)
	
{	
       // printf("mv-v2\n");
        struct stat my_stat;
	
	if(stat(destination, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	        if(stat(source, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	               if (rename(source, destination) != 0) {
            			printf("Error in moving directory\n");
            			return 0;
            			}
            	       printf("renamed '%s' -> '%s/%s'\n",source,destination,source);  
	        }
	        else{
	        char* file_source=strrchr(source,'/');
	        if(file_source ==NULL){
	             file_source=source;
	        }
	        else{
	             file_source++;
	        }
	        char source_newpath[1024];
	        snprintf(source_newpath,sizeof(source_newpath),"%s/%s",destination,file_source);
	        if(rename(source,source_newpath)!=0){
	            printf("Error in moving file\n");
	            return 0;
	        }
	        printf("renamed '%s' -> '%s'\n",source,source_newpath);
	       // printf("new path is %s\n",source_newpath);
	        }
	}
	
	else{
	       if (rename(source, destination) != 0) {
            			printf("Error in moving file\n");
            			return 0;
            			}  
               printf("renamed '%s' -> '%s'\n",source,destination);
               //printf("destination is %s",destination); 
	}
	
}

int mv_iv(char* source,char* destination){
        // printf("mv-i2\n");
        struct stat my_stat;
	
	if(stat(destination, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	        if(stat(source, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	               if (rename(source, destination) != 0) {
            			printf("Error in moving directory\n");
            			return 0;
            			} 
            	        printf("renamed '%s' -> '%s/%s'\n",source,destination,source);  
	        }
	        else{
	        FILE *file_check;
	        char input;
	        char* file_source=strrchr(source,'/');
	        if(file_source ==NULL){
	             file_source=source;
	        }
	        else{
	             file_source++;
	        }
	        char source_newpath[1024];
	        snprintf(source_newpath,sizeof(source_newpath),"%s/%s",destination,file_source);
	        file_check=fopen(source_newpath,"r");
	        if(file_check!=NULL){
	             printf("mv: overwrite '%s'? ",source_newpath);
	             scanf("%s",&input);
	             if((input=='y')||(input=='Y')){
	                 if(rename(source,source_newpath)!=0){
	                      printf("Error in moving file\n");
	                      return 0;
	                 }
	                 printf("renamed '%s' -> '%s'\n",source,source_newpath);   
	             }
	             else{
	                 return 0;
	             }
	        }
	        else{
	        if(rename(source,source_newpath)!=0){
	            printf("Error in moving file\n");
	            return 0;
	        }
	        printf("renamed '%s' -> '%s'\n",source,source_newpath);
	        }
	       
	        }
	}
	
	else{
	        
	       if(access(destination,F_OK)==0){
	             char input;
	             printf("mv: overwrite '%s'? ",destination);
	             scanf("%s",&input);
	             if((input=='y')||(input=='Y')){
	                 if(rename(source,destination)!=0){
	                      printf("Error in moving file\n");
	                      return 0;
	                 } 
	                 printf("renamed '%s' -> '%s'\n",source,destination);  
	             }
	             else{
	                 return 0;
	             }
	       }
	       
	       else{
	       if (rename(source, destination) != 0) {
            			printf("Error in moving file\n");
            			return 0;
            			} 
              printf("renamed '%s' -> '%s'\n",source,destination); 
               }
               //printf("destination is %s",destination); 
	}
	
}
int mv_n(char* source,char* destination){
        
         struct stat my_stat;
	
	if(stat(destination, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	        if(stat(source, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	               if (rename(source, destination) != 0) {
            			printf("Error in moving directory\n");
            			return 0;
            			}  
	        }
	        else{
	        FILE *file_check;
	        char input;
	        char* file_source=strrchr(source,'/');
	        if(file_source ==NULL){
	             file_source=source;
	        }
	        else{
	             file_source++;
	        }
	        char source_newpath[1024];
	        snprintf(source_newpath,sizeof(source_newpath),"%s/%s",destination,file_source);
	        file_check=fopen(source_newpath,"r");
	        if(file_check!=NULL){
	             return 0;
	        }
	        else{
	        if(rename(source,source_newpath)!=0){
	            printf("Error in moving file\n");
	            return 0;
	        }}
	       
	        }
	}
	
	else{
	        
	       if(access(destination,F_OK)==0){
	             return 0;
	       }
	       
	       else{
	       if (rename(source, destination) != 0) {
            			printf("Error in moving file\n");
            			return 0;
            			}  
               }
               //printf("destination is %s",destination); 
	}
	
}


int cp(char* source,char* destination)
	
{	
        struct stat my_stat;
	
	if(stat(destination, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	        if(stat(source, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	               printf("cp: -r not specified; omitting directory '%s'\n",source);
	        }
	        else{
	        FILE *source_f=fopen(source,"r");
	        
	        char ch;
	        char* file_source=strrchr(source,'/'); 
	        
	        if(file_source ==NULL){
	             file_source=source;
	        }
	        else{
	             file_source++;
	        }
	        
	        char source_newpath[1024];
	        snprintf(source_newpath,sizeof(source_newpath),"%s/%s",destination,file_source);
	        FILE *destination_f=fopen(source_newpath,"r");
	        
	        if(destination_f==NULL){
	                char ch;
	                destination_f=fopen(source_newpath,"w");
	                if(destination_f==NULL){
	                      printf("file could not be created\n");
	                      return 0;
	                }
	                else{
	                      //copy from source to new file
	                      while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	                      }
	                }
	                fclose(destination_f);
	                
	        }
	        else{
	              //copy from source to existing file
	             fclose(destination_f);
	             destination_f=fopen(source_newpath,"w");
	             while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	             }
	             fclose(destination_f);
	        }
	        fclose(source_f);
	        }
	}
	
	else{
	    //if both the given arguments are files copy and paste 
	    FILE *source_f=fopen(source,"r");
	    char ch;
	    if(source_f==NULL){
	             printf("source file doesnot exist\n");
	             return 0;
	    }
	    FILE *destination_f=fopen(destination,"r");
	    if(destination_f==NULL){
	             destination_f=fopen(destination,"w");
	             if(destination_f==NULL){
	                   printf("file could not be created\n");
	                   return 0;
	             }
	             else{
	                   while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	                   }
	             }
	             fclose(destination_f);
	    }
	    else{
	             fclose(destination_f);
	             destination_f=fopen(destination,"w");
	             while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	             }
	             fclose(destination_f);
	    }  
	    fclose(source_f);
	}
	
}

int cp_v(char* source,char* destination)
	
{	
        struct stat my_stat;
	
	if(stat(destination, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	        if(stat(source, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	               printf("cp: -r not specified; omitting directory '%s'\n",source);
	        }
	        else{
	        FILE *source_f=fopen(source,"r");
	        
	        char ch;
	        char* file_source=strrchr(source,'/'); 
	        
	        if(file_source ==NULL){
	             file_source=source;
	        }
	        else{
	             file_source++;
	        }
	        
	        char source_newpath[1024];
	        snprintf(source_newpath,sizeof(source_newpath),"%s/%s",destination,file_source);
	        FILE *destination_f=fopen(source_newpath,"r");
	        
	        if(destination_f==NULL){
	                char ch;
	                destination_f=fopen(source_newpath,"w");
	                if(destination_f==NULL){
	                      printf("file could not be created\n");
	                      return 0;
	                }
	                else{
	                      //copy from source to new file
	                      while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	                      }
	                      printf("'%s' -> '%s'\n",source,destination);
	                }
	                fclose(destination_f);
	                
	        }
	        else{
	              //copy from source to existing file
	             fclose(destination_f);
	             destination_f=fopen(source_newpath,"w");
	             while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	             }
	             printf("'%s' -> '%s'\n",source,destination);
	             fclose(destination_f);
	        }
	        fclose(source_f);
	        }
	}
	
	else{
	    //if both the given arguments are files copy and paste 
	    FILE *source_f=fopen(source,"r");
	    char ch;
	    if(source_f==NULL){
	             printf("source file doesnot exist\n");
	             return 0;
	    }
	    FILE *destination_f=fopen(destination,"r");
	    if(destination_f==NULL){
	             destination_f=fopen(destination,"w");
	             if(destination_f==NULL){
	                   printf("file could not be created\n");
	                   return 0;
	             }
	             else{
	                   while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	                   }
	                   printf("'%s' -> '%s'\n",source,destination);
	             }
	             fclose(destination_f);
	    }
	    else{
	             fclose(destination_f);
	             destination_f=fopen(destination,"w");
	             while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	             }
	             printf("'%s' -> '%s'\n",source,destination);
	             fclose(destination_f);
	    }  
	    fclose(source_f);
	}
	
}

int cp_i(char* source,char* destination)
	
{	
        struct stat my_stat;
	
	if(stat(destination, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	        if(stat(source, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	               printf("cp: -r not specified; omitting directory '%s'\n",source);
	        }
	        else{
	        FILE *source_f=fopen(source,"r");
	        
	        char ch;
	        char* file_source=strrchr(source,'/'); 
	        
	        if(file_source ==NULL){
	             file_source=source;
	        }
	        else{
	             file_source++;
	        }
	        
	        char source_newpath[1024];
	        snprintf(source_newpath,sizeof(source_newpath),"%s/%s",destination,file_source);
	        FILE *destination_f=fopen(source_newpath,"r");
	        
	        if(destination_f==NULL){
	                char ch;
	                destination_f=fopen(source_newpath,"w");
	                if(destination_f==NULL){
	                      printf("file could not be created\n");
	                      return 0;
	                }
	                else{
	                      //copy from source to new file
	                      while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	                      }
	                }
	                fclose(destination_f);
	                
	        }
	        else{
	              //copy from source to existing file
	             fclose(destination_f);
	             char input;
	             printf("cp: overwrite '%s'? ",source_newpath);
	             scanf("%s",&input);
	             if((input=='y')||(input=='Y')){
	                  destination_f=fopen(source_newpath,"w");
	                  while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	                  }
	                  fclose(destination_f);
	                  return 0;
	             }
	             else{
	                  return 0;
	             }
	        }
	        fclose(source_f);
	        }
	}
	
	else{
	    //if both the given arguments are files copy and paste 
	    FILE *source_f=fopen(source,"r");
	    char ch;
	    if(source_f==NULL){
	             printf("source file doesnot exist\n");
	             return 0;
	    }
	    FILE *destination_f=fopen(destination,"r");
	    if(destination_f==NULL){
	             destination_f=fopen(destination,"w");
	             if(destination_f==NULL){
	                   printf("file could not be created\n");
	                   return 0;
	             }
	             else{
	                   while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	                   }
	             }
	             fclose(destination_f);
	    }
	    else{
	             fclose(destination_f);
	             char input;
	             printf("cp: overwrite '%s'? ",destination);
	             scanf("%s",&input);
	             if((input=='y')||(input=='Y')){
	             		destination_f=fopen(destination,"w");
	             		while((ch=fgetc(source_f))!=EOF){
	                          	fputc(ch,destination_f);
	             		}
	             		fclose(destination_f);
	             		return 0;
	             }
	             else{
	             		return 0;
	             }
	    }  
	    fclose(source_f);
	}
	
}

int cp_iv(char* source,char* destination)
	
{	
        struct stat my_stat;
	
	if(stat(destination, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	        if(stat(source, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	               printf("cp: -r not specified; omitting directory '%s'\n",source);
	        }
	        else{
	        FILE *source_f=fopen(source,"r");
	        
	        char ch;
	        char* file_source=strrchr(source,'/'); 
	        
	        if(file_source ==NULL){
	             file_source=source;
	        }
	        else{
	             file_source++;
	        }
	        
	        char source_newpath[1024];
	        snprintf(source_newpath,sizeof(source_newpath),"%s/%s",destination,file_source);
	        FILE *destination_f=fopen(source_newpath,"r");
	        
	        if(destination_f==NULL){
	                char ch;
	                destination_f=fopen(source_newpath,"w");
	                if(destination_f==NULL){
	                      printf("file could not be created\n");
	                      return 0;
	                }
	                else{
	                      //copy from source to new file
	                      while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	                      }
	                      printf("'%s' -> '%s'\n",source,destination);
	                }
	                fclose(destination_f);
	                
	        }
	        else{
	              //copy from source to existing file
	             fclose(destination_f);
	             char input;
	             printf("cp: overwrite '%s'? ",source_newpath);
	             scanf("%s",&input);
	             if((input=='y')||(input=='Y')){
	                  destination_f=fopen(source_newpath,"w");
	                  while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	                  }
	                  printf("'%s' -> '%s'\n",source,destination);
	                  fclose(destination_f);
	                  return 0;
	             }
	             else{
	                  return 0;
	             }
	        }
	        fclose(source_f);
	        }
	}
	
	else{
	    //if both the given arguments are files copy and paste 
	    FILE *source_f=fopen(source,"r");
	    char ch;
	    if(source_f==NULL){
	             printf("source file doesnot exist\n");
	             return 0;
	    }
	    FILE *destination_f=fopen(destination,"r");
	    if(destination_f==NULL){
	             destination_f=fopen(destination,"w");
	             if(destination_f==NULL){
	                   printf("file could not be created\n");
	                   return 0;
	             }
	             else{
	                   while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	                   }
	                   printf("'%s' -> '%s'\n",source,destination);
	             }
	             fclose(destination_f);
	    }
	    else{
	             fclose(destination_f);
	             char input;
	             printf("cp: overwrite '%s'? ",destination);
	             scanf("%s",&input);
	             if((input=='y')||(input=='Y')){
	             		destination_f=fopen(destination,"w");
	             		while((ch=fgetc(source_f))!=EOF){
	                          	fputc(ch,destination_f);
	             		}
	             		printf("'%s' -> '%s'\n",source,destination);
	             		fclose(destination_f);
	             		return 0;
	             }
	             else{
	             		return 0;
	             }
	    }  
	    fclose(source_f);
	}
	
}

int cp_n(char* source,char* destination)
	
{	
        struct stat my_stat;
	
	if(stat(destination, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	        if(stat(source, &my_stat) == 0 && S_ISDIR(my_stat.st_mode)){
	               printf("cp: -r not specified; omitting directory '%s'\n",source);
	        }
	        else{
	        FILE *source_f=fopen(source,"r");
	        
	        char ch;
	        char* file_source=strrchr(source,'/'); 
	        
	        if(file_source ==NULL){
	             file_source=source;
	        }
	        else{
	             file_source++;
	        }
	        
	        char source_newpath[1024];
	        snprintf(source_newpath,sizeof(source_newpath),"%s/%s",destination,file_source);
	        FILE *destination_f=fopen(source_newpath,"r");
	        
	        if(destination_f==NULL){
	                char ch;
	                destination_f=fopen(source_newpath,"w");
	                if(destination_f==NULL){
	                      printf("file could not be created\n");
	                      return 0;
	                }
	                else{
	                      //copy from source to new file
	                      while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	                      }
	                }
	                fclose(destination_f);
	                
	        }
	        else{
	              //copy from source to existing file
	             fclose(destination_f);
	             return 0;
	        }
	        fclose(source_f);
	        }
	}
	
	else{
	    //if both the given arguments are files copy and paste 
	    FILE *source_f=fopen(source,"r");
	    char ch;
	    if(source_f==NULL){
	             printf("source file doesnot exist\n");
	             return 0;
	    }
	    FILE *destination_f=fopen(destination,"r");
	    if(destination_f==NULL){
	             destination_f=fopen(destination,"w");
	             if(destination_f==NULL){
	                   printf("file could not be created\n");
	                   return 0;
	             }
	             else{
	                   while((ch=fgetc(source_f))!=EOF){
	                          fputc(ch,destination_f);
	                   }
	             }
	             fclose(destination_f);
	    }
	    else{
	             fclose(destination_f);
	             return 0;
	    }  
	    fclose(source_f);
	}
	
}

