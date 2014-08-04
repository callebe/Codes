#include <stdio.h>

int M[1001][1001];


int visitar (int totalAlunos, int posicao){
  
  int cont;
 
  
  for (cont=1; cont<(totalAlunos+1); cont++){
     if((M[posicao][cont]==1) && (M[cont][0]==0)){
       M[cont][0]=1;
       visitar (totalAlunos, cont);
     }
  }
  
  
  return 0;
}

int main(){
  
    int qtdAlunos, qtdLinhas,cont,conte, a, b, totalGrupos=0;
  
    scanf("%d %d", &qtdAlunos, &qtdLinhas);
    
    for(cont=0; cont<(qtdAlunos+1); cont++)
      for(conte=0; conte<(qtdAlunos+1); conte++) M[cont][conte]=0;
    
    for (cont=0; cont<qtdLinhas; cont++){
      scanf("%d %d", &a, &b);
      M[a][b]=1;
      M[b][a]=1;
    }
  
    for (cont=1; cont<(qtdAlunos+1); cont++){
      if (M[cont][0]==0){
	M[cont][0]=1;
	visitar(qtdAlunos, cont);
	totalGrupos++;
      }
    }
    
    printf("%d\n",totalGrupos);
    
    return 0;
}