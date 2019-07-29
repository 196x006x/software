#include "liquorSystem.h"

void stockdisp(liquor *stock);

void stockdisp(liquor *stock){
  printf("在庫の表示を行います。\n");
  printf("--------\n");
  int i = 0;
  while(stock[i].liquorName != NULL){
    printf("・%c  ", stock[i].liquorName);
    printf("%d本", stock[i].numberOfLiquor);
    i++;
  }
  printf("--------\n");
  printf("システムを終了します。");
}
