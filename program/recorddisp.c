#include "liquorSystem.h"

void recorddisp(ticket *ticketList);
char input_name(ticket *ticketList);
int check_input_name(char *inputName, ticket *ticketList);

void recorddisp(ticket *ticketList){
  ticket ticket;
  char *inputName = input_name(ticketList);

  int i = 0;
  while(ticketList[i].consumerName!=NULL){
    if(ticketList[i].consumerName == inputName){
      printf("--出荷伝票--\n");
      printf("[注文番号]%d\n", ticketList[i].orderNumber);
      printf("[名前]%c\n", ticketList[i].consumerName);
      printf("[お酒の銘柄]%c\n", ticketList[i].liquorName);
      printf("[本数]%d本\n", ticketList[i].numberOfLiquor);
    }
    i++;
  }
}

char input_name(ticket *ticketList){
  char *inputName;
  do{
    printf("出荷実績を表示します。");
    printf("顧客名を入力してください。\n");
    scanf("%c", inputName);
  }while(check_input_name(inputName, ticketList));

  return *inputName;
}

int check_input_name(char *inputName, ticket *ticketList){
  int i=0;
  while(ticketList[i].consumerName != NULL){
    if(ticketList[i].consumerName == inputName){
      return 0;
    }
    else{
      return 1;
    }
    i++;
  }
}
