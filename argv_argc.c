#include <stdio.h>

int main(int argc,char *argv[]){
 int i;
 for (i=1;i<argc;i++)
  printf("%s %d\n",argv[i],i);
 printf("\n");
 return 0;
}

