#include <stdio.h>
#include <string.h>

#define qtdCustos 3
#define qtdArestas 2000000
#define qtdVertices 1003

int M[qtdArestas][3];
int vertices[qtdVertices];
int proximoCustos[qtdCustos];
int subArvores[qtdVertices];


 
int buscaSubarvore(int posicao){
    if(posicao!=subArvores[posicao]) subArvores[posicao]=buscaSubarvore(subArvores[posicao]);
    return subArvores[posicao];
}
 

int juntar (int posicao) {
    
    int aux1, aux2;
    
    aux1=subArvores[M[posicao][0]];
    aux2=subArvores[M[posicao][1]];
    
    if(vertices[aux1]>vertices[aux2]) subArvores[aux2]=aux1;
    
    else{
      
	subArvores[aux1]=aux2;
	if(vertices[aux1]==vertices[aux2]) vertices[aux2]++;
    
    }
    return 0;
}

/* Funcao Kruskal abaixo só funciona com os pessoas já conhecidos, 
 * no vetor proximoCustos eu armaveno em cada vertice qual o proximo vertice 
 * que tem mesmo custo q ele, para assim economizar a procura por menores pesos, e
 * o vetor subArvores me dara a que sub-arvore cada vertice pertence. 
 * Quando implementei o Kruskal normal ele deu tempo de execução excedido, somente
 * deste modo a função funcionol. Encontrei esta solução de melhorar o Kruskal graças
 * ao comentario de um usuario no Spoj, no suporte Spoj, que deu a dica de usar os pesos 
 * para classificar os vertices.
 * Algoritmo Kruskal http://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/kruskal.html*/

int KruskalCasoPesoEspecifico (int qtdEstacoes){
  
    int cont,conte, result;
    int aux=proximoCustos[0]; 
    
    cont=0;
    result=0;
    conte=1;
    aux=proximoCustos[0];
    
    while(conte!=qtdEstacoes){
	    
	if(aux==-1){
	  if(cont==2) return result;
	  else{
	    cont++;
	    aux=proximoCustos[cont];
	  }
	}
	else{
	    if(buscaSubarvore(M[aux][0])!=buscaSubarvore(M[aux][1])){
		    
		juntar(aux);
		if(cont==0) result=result+1235;
		else if(cont==1) result=result+8977;
		  else result=result+10923;
		
		conte++;
	    }
	    
	    aux=M[aux][2];
	}
	    
    }

    
    return result;
  
}


int main(){
    
    int qtdCidades, qtdEstradas, cont, conte, valor, Teste=1;
    
    while(scanf("%d %d", &qtdCidades, &qtdEstradas)!=EOF){
	
	memset(proximoCustos, -1, sizeof(proximoCustos));
	memset(vertices, 0, sizeof(proximoCustos));
	
	for(conte=0; conte<(qtdCidades+1); conte++){
	    subArvores[conte]=conte;
	}
      
	for(cont=0; cont<qtdEstradas; cont++){
	
	    scanf("%d %d %d",&M[cont][0], &M[cont][1],&valor);
	    
	    if(valor==1235) conte=0;
	    else if(valor==8977) conte=1;
	      else conte=2;
	    
	    M[cont][2]=proximoCustos[conte];
	    proximoCustos[conte]=cont;	
	}
	
	printf("Instancia %d\n",Teste++);
	printf("%d\n\n",KruskalCasoPesoEspecifico(qtdCidades));
    }
    
    return 0;
}