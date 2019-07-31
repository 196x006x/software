#include "liquorSystem.h"

#define N 256

int getNumberOfStock(){
  FILE *fp;
  char stockFileName[] = stockDataFile;
  char str[N];
  int number = 0;

  fp = fopen(stockFileName,"r");

  if(fp == NULL){
    printf("file error\n");
    exit(1);
  }

  while(fgets(str,N,fp) != NULL){
    number++;
  }

  fclose(fp);

  return number;

}

int getNumberOfTicket(){
  FILE *fp;
  char ticketFileName[] = ticketDataFile;
  char *str;
  int number = 0;

  fp = fopen(ticketFileName,"r");

  if(fp == NULL){
    printf("file error\n");
    exit(1);
  }

  while(fgets(str,N,fp) != NULL){
    number++;
  }

  fclose(fp);

  return number;

}

void readStock(liquor *stock){
  FILE *fp;
  char stockFileName[] = stockDataFile;
  char str[30];
  char tmpString[20];
  int i,j;
  int indexStock = 0;
  int number = 0;
  liquor nullStock = {NULL,-1};

  fp = fopen(stockFileName,"r");

  if(fp == NULL){
    printf("file error\n");
    exit(1);
  }

  while(fgets(str,N,fp) != NULL){
    //データはスペースで分割されている
    i = 0;
    while(str[i] != ' '){
      i++;
    }

    sscanf(str,"%s %d",tmpString,&number);

    //領域を確保
    stock[indexStock].liquorName = (char *)malloc(i * sizeof(char));

    //名前を読み込み
    for(j = 0;j < i;j++){
      stock[indexStock].liquorName[j] = tmpString[j];
    }

    //本数を読み込み
    stock[indexStock].numberOfLiquor = number;

    //次のデータのインデックスへ
    indexStock++;
  }

  //最後に今後の処理のためのNULLデータを挿入
  stock[indexStock] = nullStock;
  stock[indexStock+1] = nullStock;

  fclose(fp);
}

void readTicketList(ticket *ticketList){
  FILE *fp;
  char ticketFileName[] = ticketDataFile;
  char str[50];
  char tmpLiquor[20];
  char tmpConsumer[20];
  int i,j,k[2];
  int indexTicket = 0;
  int numberL = 0;
  int oN = 0;
  ticket nullTicket = {NULL,NULL,-1,-1};

  fp = fopen(ticketFileName,"r");

  if(fp == NULL){
    printf("file error\n");
    exit(1);
  }

  while(fgets(str,N,fp) != NULL){
    //データはスペースで分割されている
    //領域確保のため、各々の文字数をカウントする。
    for(i = 0;i < 2;i++){
      k[i] = 0;
      while(str[k[i]] != ' '){
        k[i]++;
      }
    }

    sscanf(str,"%s %s %d %d",tmpConsumer,tmpLiquor,&numberL,&oN);

    //領域を確保
    ticketList[indexTicket].consumerName = (char *)malloc(k[0] * sizeof(char));
    ticketList[indexTicket].liquorName = (char *)malloc(k[1] * sizeof(char));

    //名前を読み込み
    for(i = 0;i < k[0];i++){
      ticketList[indexTicket].consumerName[i] = tmpConsumer[i];
    }
    for(i = 0;i < k[1];i++){
      ticketList[indexTicket].liquorName[i] = tmpLiquor[i];
    }

    //本数を読み込み
    ticketList[indexTicket].numberOfLiquor = numberL;
    //注文番号を読み込み
    ticketList[indexTicket].orderNumber = oN;

    //次のデータのインデックスへ
    indexTicket++;
  }

  //最後に今後の処理のためのNULLデータを挿入
  ticketList[indexTicket] = nullTicket;
  ticketList[indexTicket+1] = nullTicket;

  fclose(fp);
}

void writeStock(liquor *stock){
  FILE *fp;
  char stockFileName[] = stockDataFile;

  fp = fopen(stockDataFile,"w");

  int i = 0;
  while(stock[i].liquorName != NULL){
      fprintf(fp,"%s %d\n",stock[i].liquorName,stock[i].numberOfLiquor);
    i++;
  }

  fclose(fp);

}

void writeTicketList(ticket *ticketList){
  FILE *fp;
  char ticketFileName[] = ticketDataFile;

  fp = fopen(ticketDataFile,"w");

  int i = 0;
  while(ticketList[i].consumerName != NULL){
    //printf("%s %s %d %d\n",ticketList[i].consumerName,ticketList[i].liquorName,ticketList[i].numberOfLiquor,ticketList[i].orderNumber);
    fprintf(fp,"%s %s %d %d\n",ticketList[i].consumerName,ticketList[i].liquorName,ticketList[i].numberOfLiquor,ticketList[i].orderNumber);
    i++;
  }

  fclose(fp);

}
