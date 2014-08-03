#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std; 
 
int M[30][30];
int solucao[30];
int qtdDependentes[30];
int indice=0;

int escolherVila (int qtdVilas){
  
  
  int posicaoAtual=0;
  int cont=0, inicio=0, fim=0;
  
  int fila [qtdVilas+100];
  
  memset(fila, 0, sizeof(fila));
  
  for(cont=0; cont<qtdVilas; cont++){
      if(qtdDependentes[cont]==0) fila[fim++]=cont;
  }
  
  
  while(fim!=inicio){
    
    posicaoAtual = fila[inicio++];
    solucao[indice++]=posicaoAtual;
    qtdDependentes[posicaoAtual]=-1;
    
    for(cont=0; cont<qtdVilas; cont++){
      if(M[posicaoAtual][cont]==1){
	M[posicaoAtual][cont]=0;
	M[cont][posicaoAtual]=0;
	qtdDependentes[cont]--;
	if(qtdDependentes[cont]==0) fila[fim++]=cont;
      }
    }
    
    if (fim==inicio){
      for(cont=0; cont<qtdVilas; cont++){
	if(qtdDependentes[cont]==0) fila[fim++]=cont;
      }
    }
    
  }
   
  return posicaoAtual;
  
}


 
int main(){
  
    int qtdAmigos,cont,conte,i;
    char amigo[16], necessidade[16];
    int qtdRequisitos, posicaoAtual, teste=1;
    char Amigos[30][16];
  
    while(scanf("%d", &qtdAmigos)!=0 && qtdAmigos!=0){
      
      memset(M, 0, sizeof(M));
      
      for(cont=0; cont<qtdAmigos; cont++){
	scanf(" %s ", Amigos[cont]);
      }
      
      for(cont=0; cont<qtdAmigos; cont++){
	
	scanf(" %s", amigo);
	scanf(" %d",&qtdRequisitos);
	
	for(conte=0; (conte<qtdAmigos) && (strcmp(Amigos[conte], amigo)!=0); conte++){}
	
	posicaoAtual=conte;
	qtdDependentes[posicaoAtual]=qtdRequisitos;
	
	for(conte=0; conte<qtdRequisitos; conte++){
	  scanf(" %s", necessidade);
	  for(i=0; (i<qtdAmigos) && (strcmp(Amigos[i], necessidade)!=0); i++) {}
	  M[i][posicaoAtual]=1;
	}
	    
      }
  
      indice=0;
     
      escolherVila (qtdAmigos);
      printf("Teste %d\n", teste++);
      
      if(indice==qtdAmigos){
	for(cont=0; cont<indice; cont++){
	if (cont > 0) printf(" ");  
	printf("%s", Amigos[solucao[cont]]);
	}
      }
      else printf("impossivel");
      
      printf("\n\n");
    }
         
   return 0;
}