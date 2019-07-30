#include "liquorSystem.h"

int input_order();
int check_order(int i);
ticket shipment(liquor *stock);
void arrive(liquor *stock);
void stockdisp(liquor *stock);
void recorddisp(ticket *ticketList);

void order(liquor *stock, ticket *ticketList, int numberOfTicket){
  // 入力画面
  int inputOrder = input_order();

  if(inputOrder == 1){
    // 出荷依頼処理
    ticket ticket;
    do{
      ticket = shipment(stock);
    } while(ticket.consumerName == NULL);
    ticketList[numberOfTicket] = ticket;
    return;
  }
  else if(inputOrder == 2){
    // 入荷依頼処理
    arrive(stock);
    return;
  }
  else if(inputOrder == 3){
    // 在庫表示処理
    stockdisp(stock);
    return;
  }
  else if(inputOrder == 4){
    // 出荷実績表示処理
    recorddisp(ticketList);
    return;
  }
}

int input_order(void){
  int i;
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
