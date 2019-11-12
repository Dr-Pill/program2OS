#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int fib;

void* fibonacci(void *n){
  int a=0,b=1,j,i;
  if(atoi(n)==1){
    printf("The Fibonacci sequence is as follows: \n");
    printf("%d\n",a);
    exit(0);
  }
  else if(atoi(n)==2){
    printf("The Fibonacci sequence is as follows: \n");
    printf("%d\t%d",a,b);
    exit(0);
  }
  else{
    printf("The Fibonacci sequence is as follows: \n");
    printf("%d\t%d",a,b);
    for(i=0;i<atoi(n)-2;i++){
      j=a+b;
      printf("\t%d",j);
      a=b;
      b=j;
    }
    pthread_exit(0);
  }
}

int main(int argc,char* argv[]){
  pthread_t thrd;

  if(argc!=2){
    fprintf(stderr,"Syntax: ./a.out <integer value>");
    return -1;
  }
  if(atoi(argv[1])<0){
    fprintf(stderr,"Argument %d must be positive value\n",atoi(argv[1]));
    return -1;
  }

  pthread_create(&thrd,NULL,fibonacci,(void*)argv[1]);

  pthread_join(thrd,NULL);

  exit(0);
}