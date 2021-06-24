#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int Random(int min, int max);
void set_pares(int m1[20][50], int **m2, int linha, int coluna);
int main(void) {
  srand(time(NULL));
  int m1[20][50];
  int linha;
  int coluna;
  linha = Random(2,8);
  coluna = Random(1,5);
  printf("Linha: %d\nColuna: %d\n",linha,coluna);
  int **m2 = (int**)malloc(linha*sizeof(int*));
  for(int i=0;i<linha;i++){
    m2[i] = (int*) malloc(coluna*sizeof(int));
  }
  for (int i=0; i < 20; i++)
  {
    for (int y=0; y < 50; y++)
    {
      m1[i][y] = Random(0,0);
    }
  }
    set_pares(m1, m2, linha, coluna);
    printf("\ndepois:\n");
    for (int i=0; i < linha; i++)
    {
      printf("\n");
      for (int y=0; y < coluna; y++)
      {
        printf(" [%d] ", m2[i][y]);
      }
   }
  return 0;
}

int Random(int min, int max){
  if(min!=0 && max!= 0){
    int valor = min+(rand()% max);
    if(valor>max){valor=valor-1;}
    return valor;
  }
  return (rand() % 100);
}

void set_pares(int m1[20][50], int **m2, int linha, int coluna){
  int valor;
  int i;
  int y;
  for (int i=0; i < linha; i++)
  {
    for (int y=0; y < coluna; y++)
    {
      m2[i][y] = 0;
    }
  }
    
    for (int z=0; z < 20; z++)
    {
      for (int h=0; h < 50; h++)
      {
        valor = m1[z][h];
        if((valor%2)==0){
          m2[i][y] = valor;
          if(y==coluna){
            i += 1;
            y=-1;
          }
          if(i==linha){
            break;
          }
          y += 1;
        }
      }
      if(i==linha){
        break;
      }
    }
}