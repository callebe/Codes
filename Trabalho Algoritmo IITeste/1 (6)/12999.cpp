#include <stdio.h>
#include <cstring>
#include <stdlib.h>

const int INFINITY = 1000000;

int M[1000][1000];
int MaisPerto[1000];
int Distancia[1000];

typedef struct no_ {
  int valor;
  int distancia;
  struct no_ *prox;
}no;


typedef struct fila_ {
  int qtd;
  struct no_ *primeiro;
  struct no_ *ultimo;
}fila;

int inserirFila (fila *Afila, int valor, int dist){
  
  no *novo=(no*)malloc(sizeof(no));
  novo->valor=valor;
  novo->distancia=dist;
  
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


fila* escolherCaminho (int qtdColonias){
  
  fila *result= (fila*)malloc(sizeof(fila));
  int inicio=0, cont, conte, atual=0, posicao=0;
  bool parada=true;
  
  
  for(cont=0; cont<qtdColonias && parada; cont++){
    for(conte=0; conte<qtdColonias && parada; conte++){
	if( M[cont][conte] < INFINITY){
	  parada=false; 
	  inicio=cont;
	}
    }
  }
  
  if(parada) return NULL;
  
  for(cont=inicio+1; cont<qtdColonias; cont++){
    MaisPerto[cont]=inicio;
    Distancia[cont]=M[cont][inicio];
  }
  
  
  for(cont=0; cont<qtdColonias; cont++){
    
    atual=INFINITY;
    
    for(conte=inicio+1; conte<qtdColonias; conte++){
      if(Distancia[conte]>-1 && Distancia[conte]<atual){
	 atual=Distancia[conte];
	 posicao=conte;
      }
    }
    
    if(atual==INFINITY){ return result;}    
    inserirFila (result,posicao, atual);
    Distancia[posicao]=-1;
    
    for(conte=inicio+1; conte<qtdColonias; conte++){
      if(M[posicao][conte] < Distancia[conte]){
	Distancia[conte]=M[posicao][conte];
	MaisPerto[conte]=posicao;
      } 
    }
    
  }
  return result;
  
}


int main (void){
  
  int numeroColonias=0, numeroEstradas=0;
  int id1, id2, id3, resultado=0, cont=0;
  
  scanf("%d %d", &numeroColonias, &numeroEstradas);
    
    memset(M, INFINITY, sizeof(M));
    memset(MaisPerto, -1, sizeof(MaisPerto));
    memset(Distancia, INFINITY, sizeof(Distancia));
    
    
    for(cont=0; cont<numeroEstradas; cont++){
      scanf("%d %d %d", &id1, &id2, &id3);
      M[id1][id2]=M[id2][id1]=id3;
    }    
    
    fila *result=escolherCaminho (numeroColonias);
   
    if(result!=NULL){
      no *aux= result->primeiro;
      while(aux!=NULL){
	resultado=resultado+aux->distancia;
	aux=aux->prox;
      }
    } 
    printf("%d\n", resultado);
    
     
  return 0;
}