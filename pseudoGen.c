#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<limits.h>
int main(int argc, char* argv[]){
  if(argc>3){
    int i,N = atoi(argv[1]), M = atoi(argv[2]);
    FILE *fd = fopen(argv[3], "w");
    int max = (argc==5) ? atoi(argv[4]): INT_MAX;
    srand(time(NULL));
    if(fd!=NULL){
      fprintf(fd, "%d %d\n", N, M);
      for(i=0; i<N+M; i++) fprintf(fd, "%d\n", rand() % max);
      fclose(fd);  
  }
  }else
     printf("Use assim: %s N M arqsaida.txt [range], \n onde N e M são as quantidades e arqsaida.txt é o nome do arquivo de saida desejado. range eh um numero opcional que diz ateh onde os inteiros podem ser gerados. Ex. range=100, numeros ateh 99 serao gerados.", argv[0]);
  return 0;
}
