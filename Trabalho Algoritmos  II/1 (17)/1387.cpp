#include <stdio.h>
 
int M[101][101]; 
int visitados [101];
int javisitados;
 
int visitar (int estacoes, int posicao){
  
    int cont;
    visitados[posicao]=1;
    javisitados++;
    for(cont=1; cont<(estacoes+1); cont++){
      if(M[posicao][cont]!=0 && visitados[cont]==0){
	M[posicao][cont]=M[cont][posicao]=0;
	visitar (estacoes,cont);
      }
    }
    return 0;
}
 
 
int verificaConectividade (int estacoes){
  javisitados=0;
  visitar(estacoes,1);
  if(javisitados==estacoes) return 1;
  else return 0;
  
}
 
 
 
  
 
int main(){
  
    int qtdEstacoes, qtdLinhas,cont,conte, a, b, Teste=1;
  
    while (scanf("%d %d", &qtdEstacoes, &qtdLinhas)!=0 && qtdEstacoes!=0 && qtdLinhas!=0 ){
	
	for(cont=1; cont<(qtdEstacoes+1); cont++){
	  for(conte=1; conte<(qtdEstacoes+1); conte++) M[cont][conte]=0;
	  visitados[cont]=0;
	}
	
		 	
	for (cont=0; cont<qtdLinhas; cont++){
	  scanf("%d %d", &a, &b);
	  M[a][b]=1;
	  M[b][a]=1;
	}
	
	
	printf("Teste %d\n", Teste++);
	
	if(verificaConectividade(qtdEstacoes)==1){
	  printf("normal\n");
	}
	else{
	  printf("falha\n", javisitados);
	}
	
	printf("\n");
	
    }
    return 0;
} 