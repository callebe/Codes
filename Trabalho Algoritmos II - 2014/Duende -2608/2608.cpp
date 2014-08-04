#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
 
int M[101][101];
 
typedef struct no_{
  int x; 
  int y;
}no;
 
int guloso (no doende, int qtdLinhas, int qtdColunas){
  
  no fila[(qtdLinhas*qtdColunas)+1];
  int inicioFila=0, fimFila=0, cont, conte;
  no aux;
  
  
  fila[fimFila].x=doende.x;
  fila[fimFila++].y=doende.y;
  
  while(inicioFila!=fimFila){
    
    aux.x=fila[inicioFila].x;
    aux.y=fila[inicioFila++].y;
    
    
       
    if(aux.y!=1 && M[aux.y-1][aux.x]<1){
      if(M[aux.y-1][aux.x]==-1) return M[aux.y][aux.x]+1;
      M[aux.y-1][aux.x]=M[aux.y][aux.x]+1;
      fila[fimFila].y=aux.y-1;
      fila[fimFila++].x=aux.x;
    }
    if(aux.x!=qtdColunas && M[aux.y][aux.x+1]<1){
      if(M[aux.y][aux.x+1]==-1) return M[aux.y][aux.x]+1;
      M[aux.y][aux.x+1]=M[aux.y][aux.x]+1;
      fila[fimFila].y=aux.y;
      fila[fimFila++].x=aux.x+1;
    }
    if(aux.y!=qtdLinhas && M[aux.y+1][aux.x]<1){
      if(M[aux.y+1][aux.x]==-1) return M[aux.y][aux.x]+1;
      M[aux.y+1][aux.x]=M[aux.y][aux.x]+1;
      fila[fimFila].y=aux.y+1;
      fila[fimFila++].x=aux.x;
    }
    if(aux.x!=1 && M[aux.y][aux.x-1]<1){
      if(M[aux.y][aux.x-1]==-1) return M[aux.y][aux.x]+1;
      M[aux.y][aux.x-1]=M[aux.y][aux.x]+1;
      fila[fimFila].y=aux.y;
      fila[fimFila++].x=aux.x-1;
    }
  }
  
  return -1;
  
}
 
int main(){
  
    int qtdLinhas, qtdColunas,cont,conte, a;
    no doende;
    
  
    scanf("%d %d", &qtdLinhas, &qtdColunas);
    
    
    for(cont=1; cont<(qtdLinhas+1); cont++){
	for (conte=1; conte<(qtdColunas+1); conte++){
	  scanf("%d", &a);
	  if(a==3){
	    doende.x=conte;
	    doende.y=cont;
	    M[cont][conte]=0;
	  }
	  if(a==1){
	    M[cont][conte]=0;
	  }
	  if(a==2){
	    M[cont][conte]=1;
	  }
	  if(a==0){
	    M[cont][conte]=-1;
	  }
	}
    }
    
   printf("%d\n", guloso(doende, qtdLinhas, qtdColunas));
   
         
   return 0;
} 