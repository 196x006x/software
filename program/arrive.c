#include "liquorSystem.h"

arriveOrder arrive_input(arriveOrder arriveOrder){
  // arriveOrder arriveOrder;
  printf("入荷を受け付けます。お酒の銘柄、本数を入力してください。\n");
  printf("[お酒の銘柄:]");
  scanf("%c", arriveOrder.liquorName);
  printf("[お酒の本数:]");
  scanf("%d", &arriveOrder.numberOfLiquor);
  printf("入荷が完了しました\n");
  return arriveOrder;
}
