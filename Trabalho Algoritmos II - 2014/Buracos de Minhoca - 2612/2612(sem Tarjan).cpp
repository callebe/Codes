#include <stdio.h>
 
int M[3001][3001]; 
int visitados [3001];
int javisitados;
int numeracao;
int ordemVisitados[3001];
int Mreverso[3001][3001];

 
int visitar (int estacoes, int posicao){
  
    int cont;
    visitados[posicao]=1;
    javisitados++;
    
    for(cont=1; cont<(estacoes+1); cont++){
      if(M[posicao][cont]==1 && visitados[cont]==0){
	M[posicao][cont]=0;
	visitar (estacoes,cont);
      }
    }
    
    numeracao++;
    ordemVisitados[posicao]=numeracao;
    return 0;
}
 
int visitarReverso (int estacoes, int posicao){
  
    int cont;
    visitados[posicao]=0;
    javisitados++;
    for(cont=1; cont<(estacoes+1); cont++){
      if(Mreverso[posicao][cont]==1 && visitados[cont]==1){
	Mreverso[posicao][cont]=0;
	visitarReverso(estacoes,cont);
      }
    }
    return 0;
}

int verificaConectividade (int estacoes){
  
  int cont, maxi=0, posicaoMaximo=0;
  
  javisitados=0;
  numeracao=0;
  
  visitar(estacoes,1);
  
  if(javisitados==(estacoes)){
    javisitados=0;
    for(cont=1; cont<estacoes; cont++){
      if(ordemVisitados[cont]>maxi){
	maxi=ordemVisitados[cont];
	posicaoMaximo=cont;
      }
    }
    visitarReverso(estacoes, posicaoMaximo);
    if(javisitados==estacoes){
      return 1;
    }
  }
  
  return 0;
  
}
 
 
  
 
int main(){
  
    int qtdEstacoes, qtdLinhas,cont,conte, a, b, Teste=1;
  
    while (scanf("%d %d", &qtdEstacoes, &qtdLinhas)!=0 && qtdEstacoes!=0 && qtdLinhas!=0 ){
	
	for(cont=1; cont<(qtdEstacoes+1); cont++){
	  for(conte=1; conte<(qtdEstacoes+1); conte++){
	    M[cont][conte]=0;
	    Mreverso[cont][conte]=0;
	  }
	  visitados[cont]=0;
	  ordemVisitados[cont]=0;
	}
	
		 	
	for (cont=0; cont<qtdLinhas; cont++){
	  scanf("%d %d", &a, &b);
	  M[a][b]=1;
	  Mreverso[b][a]=1;
	}
	
	
	printf("Teste %d\n", Teste++);
	
	if(verificaConectividade(qtdEstacoes)==1){
	  printf("S\n");
	}
	else{
	  printf("N\n");
	}
	
	printf("\n");
	
    }
    return 0;
} 