#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }
  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){ //hacer
  int a, b ;

  for (a = 0 ; a < 9 ; a++){ //recorrer filas
    int fila[10] = {0} ;
    for (b = 0 ; b < 9 ; b++){
      int valor = n->sudo[a][b] ;
      if (valor == 0) continue ;
      if (fila[valor] == 1) return 0 ;
      fila[valor] = 1 ;
    }
  }
  for (a = 0 ; a < 9 ; a++){ //recorrer columnas
    int col[10] = {0} ;
    for (b = 0 ; b < 9 ; b++){
      int valor = n->sudo[b][a] ;
      if (valor == 0) continue ;
      if (col[valor] == 1) return 0 ;
      col[valor] = 1 ;
    }
  }

  for(int k = 0; k < 9; k++){ //recorrer matriz 3x3
    int box[10] = {0};
    for(int p = 0; p < 9; p++){
      int i = 3*(k/3) + (p/3);
      int j = 3*(k%3) + (p%3);
      int valor = n->sudo[i][j];
      if(valor == 0) continue;
      if(box[valor]) return 0;
      box[valor] = 1;
    }
  }
  return 1;
}

List* get_adj_nodes(Node* n){ //LISTO (mirar si cambiar)
  List* list = createList() ;
  int fila = -1, col = -1 ;
  for (int a = 0 ; a < 9 && fila == -1 ; a++){
    for (int b = 0 ; b < 9 && col == -1 ; b++){
      if (n->sudo[a][b] == 0){
        fila = a ;
        col = b ;
        break ;
      }
    }
  }
  if (fila == -1 || col == -1) return list ;

  for (int k = 1 ; k <= 9 ; k++){
    Node* copia = copy(n) ;
    copia->sudo[fila][col] = k ; //se le asigna un numero a la posicion vacia
    pushBack(list, copia) ;
  }
  return list;
}

int is_final(Node* n){ //hacer
  for (int a = 0 ; a < 9 ; a++){
    for (int b = 0 ; b < 9 ; b++){
      int numerito = n->sudo[a][b] ;
      if (numerito == 0) return 0 ;
    }
  }
  return 1;
}

Node* DFS(Node* initial, int* cont){ //hacer
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/