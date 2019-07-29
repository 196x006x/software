#include "liquorSystem.h"

void order(liquor *stock, ticket *ticketList);
int input_order();
int check_order(int i);

void order(liquor *stock, ticket *ticketList){
  // 入力画面
  int input_order = input_order();

  if(input_order == 1){
    // 出荷依頼処理
    shipment(stock);
    return;
  }
  else if(input_order == 2){
    // 入荷依頼処理
    arrive_input(stock);
    return;
  }
  else if(input_order == 3){
    // 在庫表示処理
    stockdisp(stock);
    return;
  }
  else if(input_order == 4){
    // 出荷実績表示処理
    recorddisp(ticketList);
    return;
  }
}

int input_order(){
  do{
    printf("プラズマ酒店\n");
    printf("以下から行いたい項目を選び、1~4 のいずれかを入力してください。\n");
    printf("1 : 出荷依頼\n");
    printf("2 : 入荷依頼\n");
    printf("3 : 在庫表示\n");
    printf("4 : 出荷実績表示\n");
    printf("[入力してください：]");
    scanf("%d", &i);
  } while(check_order(i));
  return i;
}

int check_order(int i){
  if(i >= 1 & i <= 4){
    return 0;
  }
  else{
    return 1;
  }
}
