#include<stdlib.h>
#include<stdio.h>

int main(){
  int i, N, M, temp;
  fscanf(stdin, "%d %d\n", &N, &M);
  for(i=0; i<N+M; i++)
  {
    fscanf(stdin, "%d\n",&temp);
    printf(" %d",temp);  
  }
  return 0;
}
