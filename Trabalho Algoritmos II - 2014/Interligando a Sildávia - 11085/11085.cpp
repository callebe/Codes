#include <stdio.h>
#include <string.h>
#include <math.h>

#define INFINITO 10000000 

int M[1010][1010];
int visitar[1010];
double localizacao [1010][2];

void buscaProfundidade (int posicao, int qtdCidades) {

    int cont;

    visitar[posicao] = 1;
    
    for(cont = 0; cont < qtdCidades; cont++) {
	if(M[posicao][cont] == 1 && visitar[cont]==0) {
	    buscaProfundidade(cont, qtdCidades);
	}
    }
}



int main(void) {

    int qtdCidades, cont, conte, x, naoVisitados;
    double minimo, media, maximo;

    while(scanf("%d", &qtdCidades)!=0 && qtdCidades!=0) {

      for(cont=0; cont<qtdCidades; cont++) {
	scanf("%lf %lf", &localizacao[cont][0], &localizacao[cont][1]);
      }

      //variaveis de verificacao
      minimo=0.0;
      maximo=INFINITO;
      media=0.0;

      //tentativa e erro
      for(cont = 0; cont <= 50; cont++) {
	
	memset(visitar, 0, sizeof(visitar));
	
	naoVisitados=0;

	media = minimo + (maximo - minimo) / 2;
	
	for(conte = 0; conte < qtdCidades; conte++) {
	  for(x =(conte+1); x< qtdCidades; x++) {
	    
	    if(hypot(localizacao[conte][0] - localizacao[x][0], localizacao[conte][1] - localizacao[x][1]) < media) {
	      M[conte][x]=M[x][conte]=1;
	    } 
	    
	    else {
	      M[conte][x]=M[x][conte]=0;
	    }
	  }
	}
	
	buscaProfundidade (0, qtdCidades);
	
	for(conte=0; conte<qtdCidades; conte++) if(visitar[conte]==0) naoVisitados++;
	
	if(naoVisitados>0) {
	  minimo = media;
	} 
	
	else {
	  maximo = media;
	}
      }
      
      printf("%.4f\n", minimo);
    }
    return 0;
}