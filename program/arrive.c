#include "liquorSystem.h"


arriveOrder arrive_input(arriveOrder arriveOrder){
  printf("入荷を受け付けます。お酒の銘柄、本数を入力してください。\n");

  // 酒銘柄・本数入力部
  printf("[お酒の銘柄:]");
  scanf("%c", arriveOrder.liquorName);
  printf("[お酒の本数:]");
  scanf("%d", &arriveOrder.numberOfLiquor);

  // int i = arrive_check(arriveOrder.numberOfLiquor);
  // printf("%d", i);
  printf("入荷が完了しました\n");

  return arriveOrder;
}
