#include "liquorSystem.h"

void stockdisp(liquor *stock){
  printf("在庫の表示を行います。\n");
  printf("--------\n");
  int i = 0;
  while(stock[i].liquorName != NULL){
    printf("・%s  ", stock[i].liquorName);
    printf("%d本\n", stock[i].numberOfLiquor);
    i++;
  }
  printf("--------\n");
  return;
}
