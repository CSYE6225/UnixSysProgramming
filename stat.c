#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <inttypes.h>

int main(int argc, char **argv){
 struct stat stbuf;
 
 if(argc!=2){
  fprintf(stderr,"stat: stat requires one and only one file\n");
  return 1;
 } 
 if (stat(*argv,&stbuf)==-1){
  fprintf(stderr,"stat: could not open %s\n",*argv);
  return 1;
 }
 printf("%d\n",stbuf.st_mode);
 printf("%d\n",stbuf.st_uid);
 printf("%d\n",stbuf.st_gid);
 printf("%ji\n",(uintmax_t)stbuf.st_ino);
 return 0;
}

