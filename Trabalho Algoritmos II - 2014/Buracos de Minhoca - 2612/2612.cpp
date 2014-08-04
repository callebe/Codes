#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int planeta[3001]; 
int pre[3001];
int minimos[3001];
int pilha[3001];
int M[3001][3001];
int vizinhos[3001];
int controle, comparacao,fimPilha;


void buscaTarjan(int posicao, int qtdPlanetas) {
  
  int cont, atual=0, minimoAtual=0;
  
  pre[posicao] = controle;
  minimos[posicao] = controle;
  minimoAtual = controle++;
  
  pilha[fimPilha++] = posicao;
  
  for (cont = 0; cont < vizinhos[posicao]; cont++) {
    atual = M[posicao][cont];
    if (pre[atual] == -1) buscaTarjan(atual,qtdPlanetas);
    if (minimos[atual] < minimoAtual) minimoAtual = minimos[atual];
  }
  
  if (minimoAtual < minimos[posicao]) {
    minimos[posicao] = minimoAtual;
    return;
  }

  while(cont != posicao) {
    
    cont=pilha[--fimPilha];
    planeta[cont] = comparacao;
    minimos[cont] = qtdPlanetas;
   
  } 
  comparacao++;
  
}


int tarjan (int qtdPlanetas){
  
  int cont;
  
  comparacao=0;
  controle=0;
  fimPilha=0;
  
  for (cont = qtdPlanetas - 1; cont >= 0; cont--){
    if (pre[cont] == -1) buscaTarjan(cont,qtdPlanetas);
  }
  
  if(comparacao==1) return 1;
  
  return 0;
  
}



int main() {

  int qtdPlanetas, qtdBuracos, cont, Teste=1, a,b;

  while (scanf("%d %d", &qtdPlanetas, &qtdBuracos)!=0 && qtdPlanetas!=0) {

    for (cont = 0; cont < qtdPlanetas; cont++) {
      planeta[cont] = -1;
      minimos[cont] = -1;
      pre[cont] = -1;
      vizinhos[cont]=0;
    }

    
    for(cont=0; cont<qtdBuracos; cont++){

      scanf("%d %d", &a, &b);
      M[(a-1)][vizinhos[(a-1)]++] = (b-1);
    }
    

    printf("Teste %d\n", Teste++);

    if (tarjan(qtdPlanetas) == 1) printf("S");
    else printf("N");

    printf("\n\n");
  }
  return 0;
}