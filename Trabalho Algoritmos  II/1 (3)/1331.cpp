#include <stdio.h>
#include <string.h>

int M[7][7]; 
int visitados[7];
int grauVertice[7];


int buscaProfundidade (int posicao){	
      
      int cont;
      
      if(grauVertice[posicao]!=0){
	  
	  visitados[posicao] = 1;
	  
	  for(cont=0; cont< 7; cont++){
	      if(M[posicao][cont] && visitados[cont]==0){
		buscaProfundidade(cont);
	      }
	  }
      } 
      
      else if (posicao<7) buscaProfundidade(posicao+1);
      
      return 0;
}

int main(void){
  
    int x, y, qtdDominos, teste=1, cont, qtdVisitados, qtdImpares;

    while(scanf("%d",&qtdDominos)!=0  && qtdDominos!=0){
	
	memset(M,0,sizeof(M));
	memset(visitados,0,sizeof(visitados));
	memset(grauVertice,0,sizeof(grauVertice));

	for(cont=0; cont<qtdDominos; cont++){
	    scanf("%d%d",&x,&y);
	    M[x][y]=M[y][x]=1;
	    grauVertice[x]++;
	    grauVertice[y]++;
	}
	
	buscaProfundidade(0);
	
	qtdVisitados=0;
	qtdImpares=0;
	
	for(cont=0; cont<7; cont++){
	    
	    if(grauVertice[cont]%2!=0) qtdImpares++;
	    if( visitados[cont] || grauVertice[cont]==0) qtdVisitados++;
	}
	
	printf("Teste %d\n", teste++);
	
	if (qtdImpares > 2 || qtdVisitados != 7) printf("nao");
	else printf("sim");
	
	printf("\n\n");
    }

    return 0;

}
