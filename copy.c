#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#define PERMS 0666 /*RW for owner, group and others*/
#define BUFSIZE 8192
int main(int argc, char *argv[]){
  int f1,f2,n;
  char buf[BUFSIZ];

  if (argc !=3)
    fprintf(stderr,"copy: copy from to\n");
  if ((f1 = open(argv[1],O_RDONLY,0))==-1)
    fprintf(stderr,"copy: can't open %s\n",argv[1]);
  if ((f2 = creat(argv[2],PERMS))==-1)
    fprintf(stderr,"copy: can't create %s\n",argv[2]);
  

  while ((n=read(f1,buf,BUFSIZE))>0)
   if (write(f2,buf,n) !=n)
     fprintf(stderr,"copy: write error on file %s",argv[2]);
  return 0; 
}

