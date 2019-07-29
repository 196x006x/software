#include "liquorSystem.h"

void arrive_input(liquor *stock);
void addOrderToStock(arriveOrder arriveOrder, liquor *stock);

void arrive_input(liquor *stock){
  arriveOrder arriveOrder;

  printf("入荷を受け付けます。お酒の銘柄、本数を入力してください。\n");

  // 酒銘柄・本数入力部
  printf("[お酒の銘柄:]");
  scanf("%c", arriveOrder.liquorName);
  printf("[お酒の本数:]");
  scanf("%d", &arriveOrder.numberOfLiquor);

  addOrderToStock(arriveOrder, stock);

  printf("入荷が完了しました\n");
}

void addOrderToStock(arriveOrder arriveOrder, liquor *stock){
  int i=0;
  while(stock[i].liquorName!=NULL){
    if(stock[i].liquorName == arriveOrder.liquorName){
      stock[i].numberOfLiquor += 1;
    }
    i++;
  }
  stock[i+1].liquorName = arriveOrder.liquorName;
  stock[i+1].numberOfLiquor = arriveOrder.numberOfLiquor;
}
