#include "liquorSystem.h"

void inputArriveOrder(arriveOrder *order);
void addOrderToStock(liquor *stock, arriveOrder arriveOrder);

void arrive(liquor *stock){
  arriveOrder *thisOrder;
  int thisOrderNumber;

  thisOrder = (arriveOrder *)malloc(sizeof(arriveOrder));
  inputArriveOrder(thisOrder);
  addOrderToStock(stock, *thisOrder);

  printf("入荷が完了しました\n");
}

void inputArriveOrder(arriveOrder *order){
  // 本数
  int number;
  // index
  int i,j;
  // 入力用文字配列
  char str[1000];

  printf("入荷を受け付けます。お酒の銘柄、本数を入力してください。\n");

  // 酒銘柄・本数入力部
  printf("[お酒の銘柄:]");
  scanf("%s", str);

  //入力の文字数を調べる
  i = 0;
  while(str[i] != '\0'){
    i++;
  }

  order->liquorName = (char *)malloc(i * sizeof(char));

  //値の代入
  for(j = 0;j <= i;j++){
    order->liquorName[j] = str[j];
  }

  printf("[お酒の本数:]");
  scanf("%d", &number);

  order->numberOfLiquor = number;

  return;
}

void addOrderToStock(liquor *stock, arriveOrder order){
  int i=0;
  while(stock[i].liquorName!=NULL){
    if(strcmp(stock[i].liquorName, order.liquorName) == 0){
      stock[i].numberOfLiquor += 1;
    }
    i++;
  }
  stock[i+1].liquorName = order.liquorName;
  stock[i+1].numberOfLiquor = order.numberOfLiquor;
}
