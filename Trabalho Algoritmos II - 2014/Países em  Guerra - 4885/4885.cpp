#include <stdio.h>
 
#define INFINITO 1000000
 
int M[501][501];
 
int dijkstra(int pontoDePartida, int destino, int qtdLocais) {
        
	int Atual, minimo,cont;
	int custo[qtdLocais+1], visitados[qtdLocais+1];
	
        for (cont = 1; cont <(qtdLocais+1); cont++){
                visitados[cont] = 0;
		custo[cont] = INFINITO;
	}
	
	custo[pontoDePartida] = 0;
        Atual = pontoDePartida;
        
	while (Atual != destino) {
	  
		visitados[Atual] = 1;
		
                for (cont = 1; cont <(qtdLocais+1); cont++){
                     if (M[Atual][cont]!= -1 && custo[Atual] + M[Atual][cont] < custo[cont]){
			custo[cont] = custo[Atual] + M[Atual][cont];
		     }
		}
		
		minimo = INFINITO;
		
                for (cont = 1; cont <(qtdLocais+1); cont++)
                        if (visitados[cont]==0 &&  minimo > custo[cont]){
                                minimo = custo[cont];
				Atual = cont;
			}
                if (minimo >= INFINITO) return -1;
        }
        return custo[destino];
}
 
 
 
int main(){
  
    int qtdLocais, qtdRuas,cont,conte, a, b, c, inicio, destino,min,qtdTestes;
  
    while (scanf("%d %d", &qtdLocais, &qtdRuas)!=0 && qtdLocais!=0 ){
	
 
	for(cont=1; cont<(qtdLocais+1); cont++){
	  for(conte=1; conte<(qtdLocais+1); conte++){
	    M[cont][conte]=-1;
	   }
	}
	
		 	
	for (cont=0; cont<qtdRuas; cont++){
	  scanf("%d %d %d", &a, &b, &c);
	  M[a][b]=c;
	  if (M[b][a] != -1) M[a][b] = M[b][a] = 0;
	}
	
	scanf("%d", &qtdTestes);
	
	for(cont=0; cont<qtdTestes; cont++){
	  scanf("%d %d", &inicio, &destino);
	  min=dijkstra(inicio, destino,  qtdLocais);
	  if((min==-1)||(min>=INFINITO)) printf("Nao e possivel entregar a carta\n");
	  else printf("%d\n", min);
	}
	
	printf("\n");
	
	
    }
    return 0;
}  
