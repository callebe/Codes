#include <stdio.h>
#include <cstring>
#include <stdlib.h>

int M[51][51];
bool checkCidades[51];

typedef struct no_ {
  int valor;
  struct no_ *prox;
}no;


typedef struct fila_ {
  int qtd;
  struct no_ *primeiro;
  struct no_ *ultimo;
}fila;

int inserirFila (fila *Afila, int valor){
  
  no *novo=(no*)malloc(sizeof(no));
  novo->valor=valor;
  
  if(Afila->qtd==0){
    Afila->primeiro=novo;
    Afila->ultimo=novo;
  }
  else{
    Afila->ultimo->prox=novo;
    Afila->ultimo=novo;
  }
  novo->prox=NULL;
  Afila->qtd++;
  return 0;
} 



int removerFila (fila *Afila){
  
  no *tmp = Afila->primeiro;
  Afila->primeiro = Afila->primeiro->prox;
  Afila->qtd--;
  free(tmp);
  return 0;
}


int escolherCidades (int qtdCidades,int inicio,int maxPedagio){
  
  
  int distancia=0;
  fila *visitar=(fila*)malloc(sizeof(visitar));
  int posicaoAtual=0, distanciAtual=0;
  
  visitar->qtd=0;
  visitar->primeiro=NULL;
  visitar->ultimo=NULL;
  
  inserirFila(visitar,inicio);
  checkCidades[inicio]=1;
  
  for(int cont=1; visitar->qtd!=0; cont++){
     
    posicaoAtual = visitar->primeiro->valor;
    distanciAtual = M[posicaoAtual][0];
    
    removerFila(visitar);
    
    for(int conte=1; conte<=qtdCidades; conte++){
      if(M[posicaoAtual][conte]==1 && checkCidades[conte]==0){
	checkCidades[conte]=1;
	M[conte][0]=distanciAtual+1;
	inserirFila (visitar,conte);
      }
      
    }
    
  }
  
  
  return 0;
  
}


int main (void){
  
  int numeroCidades=0, numeroEstradas=0, posicaoInicial=0, maximoPedagios=0;
  int cont, id1, id2, testes=1;
  bool impresso=true;
  
  while(scanf("%d %d %d %d", &numeroCidades, &numeroEstradas, &posicaoInicial, &maximoPedagios )!=EOF && numeroCidades!=0 && numeroEstradas!=0 && posicaoInicial!=0 && maximoPedagios!=0) {
    
    memset(M, 0, sizeof(M));
    memset(checkCidades, 0, sizeof(checkCidades));
    
    for(cont=0; cont<numeroEstradas; cont++){
      scanf("%d %d", &id1, &id2);
      M[id1][id2]=M[id2][id1]=1;
    }
    
    escolherCidades (numeroCidades, posicaoInicial, maximoPedagios);
    printf("Teste %d\n", testes);
    testes++;
    
    impresso=true;
    
    for(cont=1; cont<=numeroCidades; cont++){
      if(M[cont][0]>0 && M[cont][0]<=maximoPedagios){
	if(impresso){
	  printf("%d", cont);
	  impresso=false;
	}
	else printf(" %d", cont);
      } 
     }
     printf("\n\n");
      
  }
  return 0;
}