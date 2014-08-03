#include <stdio.h>
#include <cstring>
#include <stdlib.h>


int escolherVila (int **M, int qtdVilas){
  
  
  int posicaoAtual=0;
  int cont=0, inicio=0, fim=0;
  
  int fila [qtdVilas+1];
  
  memset(fila, 0, sizeof(fila));
  
  for(cont=1; cont<(qtdVilas+1); cont++){
      if(M[cont][0]==1) fila[fim++]=cont;
  }
  
  
  while(fim!=inicio){
    
    posicaoAtual = fila[inicio++];
    M[posicaoAtual][0]=0;
    
    for(cont=1; cont<(qtdVilas+1); cont++){
      if(M[posicaoAtual][cont]==1){
	M[posicaoAtual][cont]=0;
	M[cont][posicaoAtual]=0;
	M[cont][0]--;
	if(M[cont][0]==1) fila[fim++]=cont;
      }
      
    }
    
  }
   
  return posicaoAtual;
  
}

int main (void){
  
  int numeroVilas;
  int id1, id2,cont, Teste=1;
  int **M=NULL;
  bool controle;
  
  while(scanf("%d", &numeroVilas)!=EOF && numeroVilas!=0){
    
    if(numeroVilas==1){
      printf("Teste %d\n1\n\n", Teste);
      Teste++;
      continue;
    }
    
    controle=true;
    M=(int**)malloc(sizeof(int*)*(numeroVilas+1));
    for(cont=0; cont<(numeroVilas+1); cont++) M[cont]=(int*)malloc(sizeof(int)*(numeroVilas+1));
    
    memset(M, 0, sizeof(M));
    
    for(cont=1; cont<numeroVilas; cont++){
      scanf("%d %d", &id1, &id2);
      M[id1][id2]=M[id2][id1]=1;
      M[id1][0]++;
      M[id2][0]++;
    }
    
    printf("Teste %d\n%d\n\n", Teste++, escolherVila (M,numeroVilas));
    
  }   
  return 0;
}