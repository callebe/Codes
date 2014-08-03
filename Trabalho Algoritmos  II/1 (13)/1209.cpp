#include <stdio.h>
#include <cstring>


bool M[10001][10001];
int qtdAmigos[10001];

int removerConvidados (int tamMatriz, int tamVetor, int posicao, int requisito){
  
  int j;
  
  qtdAmigos[posicao]=0;
  
  for(j=1; j<(tamMatriz+1); j++){
    if(M[posicao][j]){
      M[j][posicao]=M[posicao][j]=0;
      qtdAmigos[j]--;
      if(qtdAmigos[j]>0 && qtdAmigos[j] < requisito){
	    removerConvidados(tamVetor, tamVetor,j, requisito);
	  }
    }
  }
  return 0;
}

int main (void){
    int qtdPessoas, qtdRelacoes, preRequisito;
    int cont, conte, v1=0, v2=0;
    bool impresso;
    
    while(scanf("%d %d %d", &qtdPessoas, &qtdRelacoes, &preRequisito)!=EOF){
      
      for(cont=1; cont<(qtdPessoas+1); cont++)
	for(conte=1; conte<(qtdPessoas+1); conte++) M[cont][conte]=0;
      
      for(conte=1; conte<(qtdPessoas+1); conte++) qtdAmigos[conte]=0;
    
      for(cont=0; cont<qtdRelacoes; cont++){
	scanf("%d %d", &v1, &v2);
	M[v1][v2]=M[v2][v1]=1;
	qtdAmigos[v1]++;
	qtdAmigos[v2]++;
      }
      
      if(preRequisito==0){
	
	printf("1");
	for(cont=1; cont<qtdPessoas; cont++){
	  printf(" %d", cont+1);
	}
	printf("\n");
      }
      
      
      
      else{
	
	for(cont=1; cont<(qtdPessoas+1); cont++){
	  if(qtdAmigos[cont]>0 && qtdAmigos[cont]<preRequisito){
	    removerConvidados(qtdPessoas, qtdPessoas,cont, preRequisito);
	  }
	}
	
	impresso=true;
	for(cont=1; cont<(qtdPessoas+1); cont++){
	  if(qtdAmigos[cont]>0){
	    if(impresso){
	      printf("%d", cont);
	      impresso=false;
	    }
	    else printf(" %d", cont);
	  }
	}
	
	if(impresso) printf("0\n");
	else printf("\n");
      }
    }
    return 0;
    
}

