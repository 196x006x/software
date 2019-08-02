#include "liquorSystem.h"

void recorddisp(ticket *ticketList){
  char inputName[1000];
  printf("出荷実績を表示します。");
  printf("顧客名を入力してください。\n");
  scanf("%s", inputName);

  // ticketList内確認用
  int i = 0;
  // 存在しない場合の確認用
  int n = 0;

  do{
    if(strcmp(ticketList[i].consumerName, inputName) == 0){
      printf("--出荷伝票--\n");
      printf("[注文番号]%d\n", ticketList[i].orderNumber);
      printf("[名前]%s\n", ticketList[i].consumerName);
      printf("[お酒の銘柄]%s\n", ticketList[i].liquorName);
      printf("[本数]%d本\n", ticketList[i].numberOfLiquor);
      printf("--------\n");
      n++;
    }
    i++;
  } while(ticketList[i].consumerName!=NULL);

  if(n==0){
    printf("!!この名前は存在しません。もう一度入力し直してください。!!\n\n");
    recorddisp(ticketList);
  }
  else{
    return;
  }
}
