#include <stdio.h>
#include <stdlib.h>

#define qtdPassos 10

typedef struct coordenadas_{
	int x;
	int y;
}coordenadas;

int tabuleiro[qtdPassos][9][9];


int moverInimigos (int passoAtual,coordenadas *naviosInimigos, coordenadas *retroNavios, coordenadas meuNavio, int qtdNavios){
    
    int cont, x, y,proximo;
    
    proximo=passoAtual+1;
    
    for(cont=0; cont<qtdNavios; cont++){
      if(meuNavio.x<naviosInimigos[cont].x) x=naviosInimigos[cont].x-1;
      else if(meuNavio.x>naviosInimigos[cont].x) x=naviosInimigos[cont].x+1;
      else x=naviosInimigos[cont].x;

      if(meuNavio.y<naviosInimigos[cont].y) y=naviosInimigos[cont].y-1;
      else if(meuNavio.y>naviosInimigos[cont].y) y=naviosInimigos[cont].y+1;
      else y=naviosInimigos[cont].y;

      if(x==meuNavio.x && y==meuNavio.y) break;
      if(tabuleiro[proximo][x][y]==0) tabuleiro[proximo][x][y]=1;
      else if(tabuleiro[proximo][x][y]==1) tabuleiro[proximo][x][y]=2;
      retroNavios[cont].x=x;
      retroNavios[cont].y=y;
      
    }
    
    return cont;
  
}

int desfazerMover (int k,coordenadas *naviosInimigos, coordenadas *retroNavios, int passoAtual){
    
    int cont,proximo;
    
    proximo=passoAtual+1;
    
    for(cont=0; cont<k; cont++){
      tabuleiro[proximo][naviosInimigos[cont].x][naviosInimigos[cont].y]=0;
      tabuleiro[proximo][retroNavios[cont].x][retroNavios[cont].y]=tabuleiro[passoAtual][retroNavios[cont].x][retroNavios[cont].y];
      if(tabuleiro[proximo][retroNavios[cont].x][retroNavios[cont].y]==1){
	tabuleiro[proximo][retroNavios[cont].x][retroNavios[cont].y]=0;
      }
    }
}

int buscaProfundidade (int passoAtual, coordenadas meuNavio){
    
    int qtdNavios, proximo, cont, conte,controle;
    
    coordenadas proximoPasso;
    
    if(passoAtual>9) return 0;
    
    coordenadas *retroNavios=(coordenadas*)malloc(sizeof(coordenadas)*10);
    coordenadas *naviosInimigos=(coordenadas*)malloc(sizeof(coordenadas)*10);
    
    proximo=passoAtual+1; 
    qtdNavios=0;
    
    for(cont=0; cont<9; cont++){
      for(conte=0; conte<8; conte++){
	tabuleiro[proximo][cont][conte]=tabuleiro[passoAtual][cont][conte];
	if(tabuleiro[passoAtual][cont][conte]==1){ 
	  tabuleiro[proximo][cont][conte]=0; 
	  naviosInimigos[qtdNavios].x=cont; 
	  naviosInimigos[qtdNavios].y=conte; 
	  qtdNavios++;
	} 
      }  
    }
    
    if(qtdNavios==0) return 1;
    
    int possibilidadesx[8]={ 1,1,1, 0, 0,-1,-1,-1};
    int possibilidadesy[8]={-1,1,0,-1, 1,-1, 1, 0};
    
    for(cont=0; cont<8; cont++){
      
      proximoPasso.x=meuNavio.x+possibilidadesx[cont]; 
      proximoPasso.y=meuNavio.y+possibilidadesy[cont];
      
      if(proximoPasso.x>-1 && proximoPasso.x<9 && proximoPasso.y>-1 && proximoPasso.y<8)
	if(tabuleiro[passoAtual][proximoPasso.x][proximoPasso.y]==0){
	  controle=moverInimigos (passoAtual,naviosInimigos,retroNavios,proximoPasso,qtdNavios);
	  if(controle==qtdNavios){
	    if(buscaProfundidade(proximo,proximoPasso)) return 1;
	  } 
	  desfazerMover (controle,naviosInimigos, retroNavios, passoAtual);
	}
    }

    return 0;
}

int main()
{
    int qtdCenarios,cont, conte, xp, yp,controle;
    char aux;
    coordenadas meuNavio;


    scanf("%d",&qtdCenarios);
    
    for(controle=0; controle<qtdCenarios; controle++){
      
      for(cont=0; cont<9; cont++){	
	
	for(conte=0; conte<8; conte++){
	  scanf(" %c",&aux);
	  if(aux=='S'){
	    meuNavio.x=cont; 
	    meuNavio.y=conte;
	    tabuleiro[0][cont][conte]=0;
	  }
	  else if(aux=='E'){
	    tabuleiro[0][cont][conte]=1;
	  }
	  else if(aux=='#'){
	    tabuleiro[0][cont][conte]=2;
	  }
	  else tabuleiro[0][cont][conte]=0;
	}
      }

      if(buscaProfundidade(0,meuNavio)==1){ 
	printf("I'm the king of the Seven Seas!\n");
      }
      else printf("Oh no! I'm a dead man!\n");
    }

    return 0;
}