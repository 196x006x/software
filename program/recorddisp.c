#include "liquorSystem.h"

void recorddisp(ticket *ticketList){
  do{
    char *inputName;
    ticket ticket;
    printf("出荷実績を表示します。");
    printf("顧客名を入力してください。\n");
    scanf("%c", consumerName);
  }while(出荷伝票一覧に入力された顧客名が存在しない場合);

  if(ticketList.consumerName == inputName){
    printf("--出荷伝票--\n");
    printf("[注文番号]%d\n", ticket.orderNumber);
    printf("[名前]%c\n", ticket.consumerName);
    printf("[お酒の銘柄]%c\n", ticket.liquorName);
    printf("[本数]%d本\n", ticket.numberOfLiquor);
  }
}
