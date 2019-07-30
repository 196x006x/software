#include "liquorSystem.h"

void recorddisp(ticket *ticketList){
  ticket ticket;
  // char *inputName = input_name(ticketList);
  char inputName[1000];
  printf("出荷実績を表示します。");
  printf("顧客名を入力してください。\n");
  scanf("%s", inputName);

  int i = 0;
  while(ticketList[i].consumerName!=NULL){
    if(ticketList[i].consumerName == inputName){
      printf("--出荷伝票--\n");
      printf("[注文番号]%d\n", ticketList[i].orderNumber);
      printf("[名前]%s\n", ticketList[i].consumerName);
      printf("[お酒の銘柄]%s\n", ticketList[i].liquorName);
      printf("[本数]%d本\n", ticketList[i].numberOfLiquor);
    }
    i++;
  }
}
