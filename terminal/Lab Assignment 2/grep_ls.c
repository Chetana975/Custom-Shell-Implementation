#include"myheader.h"
int grep(char *string,char *file_name){
          FILE *file=fopen(file_name,"r");
          if(file==NULL){
                 printf("grep: %s: No such file or directory\n",file_name);
                 return 0;
          }
          char line[1024];
          while(fgets(line,1024,file)!=NULL){
             if(strstr(line,string)!=NULL){
                    printf("%s",line);
             }    
          }
          fclose(file);
          return 0;
}
int grep_m(char *string,char *file_name){
          FILE *file=fopen(file_name,"r");
          if(file==NULL){
                 printf("grep: %s: No such file or directory\n",file_name);
                 return 0;
          }
          char line[1024];
          while(fgets(line,1024,file)!=NULL){
             if(strstr(line,string)!=NULL){
                    printf("%s:%s",file_name,line);
             }    
          }
          fclose(file);
          return 0;
}
int grep_l(char *string,char *file_name){
          FILE *file=fopen(file_name,"r");
          if(file==NULL){
                 printf("grep: %s: No such file or directory\n",file_name);
                 return 0;
          }
          char line[1024];
          while(fgets(line,1024,file)!=NULL){
             if(strstr(line,string)!=NULL){
                    printf("%s\n",file_name);
                    return 0;
             }    
          }
          fclose(file);
          
}
int grep_c(char *string,char *file_name){
          FILE *file=fopen(file_name,"r");
          if(file==NULL){
                 printf("grep: %s: No such file or directory\n",file_name);
                 return 0;
          }
          char line[1024];
          int i=0;
          while(fgets(line,1024,file)!=NULL){
             if(strstr(line,string)!=NULL){
                    i++;
             }    
          }
          printf("%s:%d\n",file_name,i);
          fclose(file);
          return 0;
}

struct Fileprop{
             struct stat my_stat;
             char filename[1024];
              
             };
             
int comparefilenames(const void* a, const void* b) {
    struct Fileprop* a_Fileprop = (struct Fileprop*) a;
    struct Fileprop* b_Fileprop = (struct Fileprop*) b;
    return strcasecmp(a_Fileprop->filename,b_Fileprop->filename);
}
     
int comparemod_time(const void* a, const void* b){
    struct Fileprop* a_Fileprop = (struct Fileprop*) a;
    struct Fileprop* b_Fileprop = (struct Fileprop*) b;
    return  (b_Fileprop->my_stat.st_mtime)-(a_Fileprop->my_stat.st_mtime);
}

int comparesize(const void* a, const void* b){
    struct Fileprop* a_Fileprop = (struct Fileprop*) a;
    struct Fileprop* b_Fileprop = (struct Fileprop*) b;
    return (b_Fileprop->my_stat.st_size)-(a_Fileprop->my_stat.st_size);
}

int ls_l(){
     struct dirent *files;//contains d_name (char pointer) points to the names of files in current directory
     
     int count=0;
     char filename_path[1024];
     DIR *dir=opendir(".");//opens directory stream corresponding to directory name and returns pointer of DIR type 
     if(dir==NULL){//opendir function returns NULL if it couldn't open current directory
          printf("could not open current directory\n");
          return 0;
          }
     
     
    
     while((files=readdir(dir))!=NULL){
           if(files->d_name[0] != '.'){
           count++;
           }
     }  
     
     struct Fileprop my_Fileprop[count];
     int i=0;
     
     rewinddir(dir);
     while((files=readdir(dir))!=NULL){
           if(files->d_name[0] != '.'){
                strcpy(my_Fileprop[i].filename,files->d_name);
                sprintf(filename_path,"./%s",files->d_name);
                int x=stat(filename_path,&my_Fileprop[i].my_stat);
                if(x<0){
                    continue;
                }
                i++;
           }
     }
   
    
    qsort(my_Fileprop,count,sizeof(struct Fileprop),comparefilenames);
    
    
    for(int i=0;i<count;i++){
    
    time_t mod_time=my_Fileprop[i].my_stat.st_mtime;
    struct tm frmt_time;
    localtime_r(&mod_time,&frmt_time);
    char formatted_time[100];
    strftime(formatted_time,100,"%b %d %H:%M",&frmt_time);
    
                printf((S_ISDIR(my_Fileprop[i].my_stat.st_mode)) ? "d" : "-");
    		printf((my_Fileprop[i].my_stat.st_mode & S_IRUSR) ? "r" : "-");
     		printf((my_Fileprop[i].my_stat.st_mode & S_IWUSR) ? "w" : "-");
    		printf((my_Fileprop[i].my_stat.st_mode & S_IXUSR) ? "x" : "-");
    		printf((my_Fileprop[i].my_stat.st_mode & S_IRGRP) ? "r" : "-");
    		printf((my_Fileprop[i].my_stat.st_mode & S_IWGRP) ? "w" : "-");
    		printf((my_Fileprop[i].my_stat.st_mode & S_IXGRP) ? "x" : "-");
    		printf((my_Fileprop[i].my_stat.st_mode & S_IROTH) ? "r" : "-");
    		printf((my_Fileprop[i].my_stat.st_mode & S_IWOTH) ? "w" : "-");
    		printf((my_Fileprop[i].my_stat.st_mode & S_IXOTH) ? "x" : "-");
    		printf(" %ld",my_Fileprop[i].my_stat.st_nlink);
    		printf(" %s",getpwuid(my_Fileprop[i].my_stat.st_uid)->pw_name);
                printf(" %s",getgrgid(my_Fileprop[i].my_stat.st_gid)->gr_name);
                printf("\t%ld",my_Fileprop[i].my_stat.st_size);
                printf("\t%s",formatted_time);
                printf("\t%s",my_Fileprop[i].filename);
                printf("\n");

    }
    closedir(dir);
    return 0;
}

int ls_t(){
         struct dirent *files;//contains d_name (char pointer) points to the names of files in current directory
     
     int count=0;
     char filename_path[1024];
     DIR *dir=opendir(".");//opens directory stream corresponding to directory name and returns pointer of DIR type 
     if(dir==NULL){//opendir function returns NULL if it couldn't open current directory
          printf("could not open current directory\n");
          return 0;
          }
     
     
    
     while((files=readdir(dir))!=NULL){
           if(files->d_name[0] != '.'){
           count++;
           }
     }  
     
     struct Fileprop my_Fileprop[count];
     int i=0;
     
     rewinddir(dir);
     while((files=readdir(dir))!=NULL){
           if(files->d_name[0] != '.'){
                strcpy(my_Fileprop[i].filename,files->d_name);
                sprintf(filename_path,"./%s",files->d_name);
                int x=stat(filename_path,&my_Fileprop[i].my_stat);
                if(x<0){
                    continue;
                }
                i++;
           }
     }
     qsort(my_Fileprop,count,sizeof(struct Fileprop),comparemod_time);
    for(int i=0;i<count;i++){
    
                printf("%s",my_Fileprop[i].filename);
                printf("\n");

    }
    closedir(dir);
    return 0;
}

int ls_S(){
     struct dirent *files;//contains d_name (char pointer) points to the names of files in current directory
     
     int count=0;
     char filename_path[1024];
     DIR *dir=opendir(".");//opens directory stream corresponding to directory name and returns pointer of DIR type 
     if(dir==NULL){//opendir function returns NULL if it couldn't open current directory
          printf("could not open current directory\n");
          return 0;
          }
     
     
    
     while((files=readdir(dir))!=NULL){
           if(files->d_name[0] != '.'){
           count++;
           }
     }  
     
     struct Fileprop my_Fileprop[count];
     int i=0;
     
     rewinddir(dir);
     while((files=readdir(dir))!=NULL){
           if(files->d_name[0] != '.'){
                strcpy(my_Fileprop[i].filename,files->d_name);
                sprintf(filename_path,"./%s",files->d_name);
                int x=stat(filename_path,&my_Fileprop[i].my_stat);
                if(x<0){
                    continue;
                }
                i++;
           }
     }
     
     qsort(my_Fileprop,count,sizeof(struct Fileprop),comparesize);
    for(int i=0;i<count;i++){
  
                printf("%s",my_Fileprop[i].filename);
                printf("\n");

    }
    closedir(dir);
    return 0;
}

int ls_U(){
     struct dirent *files;//contains d_name (char pointer) points to the names of files in current directory
     
     int count=0;
     char filename_path[1024];
     DIR *dir=opendir(".");//opens directory stream corresponding to directory name and returns pointer of DIR type 
     if(dir==NULL){//opendir function returns NULL if it couldn't open current directory
          printf("could not open current directory\n");
          return 0;
          }
     
     
    
     while((files=readdir(dir))!=NULL){
           if(files->d_name[0] != '.'){
           count++;
           }
     }  
     
     struct Fileprop my_Fileprop[count];
     int i=0;
     
     rewinddir(dir);
     while((files=readdir(dir))!=NULL){
           if(files->d_name[0] != '.'){
                strcpy(my_Fileprop[i].filename,files->d_name);
                sprintf(filename_path,"./%s",files->d_name);
                int x=stat(filename_path,&my_Fileprop[i].my_stat);
                if(x<0){
                    continue;
                }
                i++;
           }
     }
     for(int i=0;i<count;i++){
  
                printf("%s",my_Fileprop[i].filename);
                printf("\n");

    }
    closedir(dir);
    return 0;
}
int ls(){
    struct dirent *files;//contains d_name (char pointer) points to the names of files in current directory
     
     int count=0;
     char filename_path[1024];
     DIR *dir=opendir(".");//opens directory stream corresponding to directory name and returns pointer of DIR type 
     if(dir==NULL){//opendir function returns NULL if it couldn't open current directory
          printf("could not open current directory\n");
          return 0;
          }
     
     
    
     while((files=readdir(dir))!=NULL){
           if(files->d_name[0] != '.'){
           count++;
           }
     }  
     
     struct Fileprop my_Fileprop[count];
     int i=0;
     
     rewinddir(dir);
     while((files=readdir(dir))!=NULL){
           if(files->d_name[0] != '.'){
                strcpy(my_Fileprop[i].filename,files->d_name);
                sprintf(filename_path,"./%s",files->d_name);
                int x=stat(filename_path,&my_Fileprop[i].my_stat);
                if(x<0){
                    continue;
                }
                i++;
           }
     }
     
     qsort(my_Fileprop,count,sizeof(struct Fileprop),comparefilenames);
    for(int i=0;i<count;i++){
  
                printf("%s",my_Fileprop[i].filename);
                printf("\n");

    }
    closedir(dir);
    return 0;
}
