#include<fstream>
#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
  int amigos, randomico[2], n_relacoes, limite;
  
  
  cin >> amigos >> n_relacoes >> limite;
  cout << amigos << " " << n_relacoes << " " << limite << endl;
  //relacoes = new int[amigos][amigos];
  
  int **relacoes = (int**) malloc(amigos * sizeof(int*));
  for(int i = 0; i < amigos; i ++){
    relacoes[i] = (int*)malloc(amigos*sizeof(int));
    for(int j = 0 ; j < amigos; j ++){
      relacoes[i][j] = 0;
    }
  }
  srand(time(NULL));
  
  for(int i = 0; i < n_relacoes; ){
    randomico[0] = rand() % amigos;
    randomico[1] = rand() % amigos;
    if(relacoes[randomico[0]][randomico[1]] == 0){
      cout << randomico[0] << " -- " << randomico[1] << "; ";
      relacoes[randomico[0]][randomico[1]] = 1;
      relacoes[randomico[1]][randomico[0]] = 1;
      i++;
    }
  }
 
}