#include<stdio.h>

#define naoVisitado 1
#define visitado 2
#define confirmado 3


 
int M[1001][1001];
int MInvertido[1001][1001];
int tubos[1001][4];
int grafo[1001];
int max, maxTimer;


 
int buscaProfundidade (int posicaoAtual,int capitais, int time){
    
    int cont;
    
    tubos[posicaoAtual][0] = visitado;
    tubos[posicaoAtual][2] = ++time;

    for(cont=0; cont<capitais; cont++){
      
      if(M[posicaoAtual][cont] == 1 && tubos[cont][0] == naoVisitado){
	M[cont][posicaoAtual] = MInvertido[posicaoAtual][cont] = 0;
	tubos[cont][1] = posicaoAtual;
	time=buscaProfundidade(cont,capitais,time);
      }
    }

    tubos[posicaoAtual][0] = confirmado;
    tubos[posicaoAtual][3] = ++time;
    
    if(tubos[posicaoAtual][3] > maxTimer){
      maxTimer = tubos[posicaoAtual][3];
      max = posicaoAtual;
    }
    return time;
    
}
 
int verificarConectividade (int capitais){
  
    int cont, time=0;
    
    for(cont=0; cont<capitais; cont++){
      tubos[cont][0] = naoVisitado;
      tubos[cont][1] = -1; 
    }
    
    maxTimer=0;
    for(cont=0; cont<capitais; cont++)
    {
      if(tubos[cont][0]==naoVisitado) buscaProfundidade(cont,capitais,time);
    }
    
    return 0;
    
}

 
int buscaProfundidadeInvertido (int posicaoAtual,int capitais, int posicaoArvore, int time){
    
    int cont;
    
    grafo[posicaoAtual] = posicaoArvore;
    tubos[posicaoAtual][0] = visitado;
    tubos[posicaoAtual][2] = ++time;

    for(cont=0; cont<capitais; cont++)
    {
      if(MInvertido[posicaoAtual][cont] == 1 && tubos[cont][0] == naoVisitado){
	
	tubos[cont][1] = posicaoAtual;
	time=buscaProfundidadeInvertido(cont,capitais,posicaoArvore,time);
      }
    }
    
    tubos[posicaoAtual][0] = confirmado;
    tubos[posicaoAtual][3] = ++time;
    
    return time;
    
}
 
int  verificarConectividadeInvertida (int capitais){
  
    int cont, time=0, posicaoArvore = 1;
    
    for(cont=0; cont<capitais; cont++){
      tubos[cont][0] = naoVisitado;
      tubos[cont][1] = -1;
    }
        
    grafo[max] = posicaoArvore;
    buscaProfundidadeInvertido(max,capitais, posicaoArvore,time);
    
    for(cont=0; cont<capitais; cont++){
      if(tubos[cont][0] == naoVisitado){
	posicaoArvore++;
	buscaProfundidadeInvertido(cont,capitais,posicaoArvore,time);
      }
    }
    return posicaoArvore;
    
}
 
 
 
int main(void){
    
    int capitais,ramos, x, y,cont,conte;

    while(scanf("%d %d",&capitais, &ramos)!=0 && capitais!=0 && ramos!=0){
	
	for(cont=0; cont<capitais; cont++){
	  for(conte=0; conte<capitais; conte++){
	    M[cont][conte] = 0;
	    MInvertido[cont][conte] = 0;
	  }
	}
	
	for(cont=0; cont<ramos; cont++){
	  scanf("%d %d",&x, &y);
	  M[x-1][y-1]=M[y-1][x-1]=MInvertido[x-1][y-1]=MInvertido[y-1][x-1]=1;
	}
	
	 verificarConectividade(capitais);
	
	if(verificarConectividadeInvertida(capitais) == 1) printf("S\n");
	else printf("N\n");

      
    }

    return 0;
    
}