#include<stdio.h>

int main(int argc, char *argv[]){
 FILE *fp;
 void filecopy(FILE *, FILE *);

 if (argc>1){
   printf("%s\n",*++argv);
   if ((fp = fopen(*argv,"r"))==NULL){
    fprintf(stderr, "cat: can't open %s\n",*argv);
    return 1;
   } else {
     filecopy(fp,stdout);
     fclose(fp); 
   }
 }
 return 0;
}

void filecopy(FILE *ifp, FILE *ofp){
 int c;
 while ((c=getc(ifp)) != EOF)
  putc(c,ofp);
}

