#include "liquorSystem.h"

void order(){
  int input_order;
  printf("プラズマ酒店\n");
  printf("以下から行いたい項目を選び、1~4 のいずれかを入力してください。\n");
  printf("1 : 出荷依頼\n");
  printf("2 : 入荷依頼\n");
  printf("3 : 在庫表示\n");
  printf("4 : 出荷実績表示\n");
  printf("[入力してください：]");
  scanf("%d", *input_order);

  if (input_order == 1){
    // メソッド
  }
  else if(input_order == 2){
    arrive_input();
  }
  else if(input_order == 3){
    stockdisp();
  }
  else if(input_order == 4){
    recorddisp();
  }
}
