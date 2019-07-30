#include "liquorSystem.h"

//入力を受け付ける
void inputShipmentOrder(shipmentOrder *order);
//注文番号を取得
int         getOrderNumber();
//在庫を確認し出荷を行う 返り値は1or0 条件判定に用いる 1 = error
int         doShipment(liquor *stock,shipmentOrder order);
//出荷伝票を発行する
ticket      printTicket(char *cName,char *lName,int nOfL,int oN);

ticket shipment(liquor *stock){
  shipmentOrder *thisOrder;
  int           thisOrderNumber;
  ticket        thisTicket;

  thisOrder = (shipmentOrder *)malloc(sizeof(shipmentOrder));
  inputShipmentOrder(thisOrder);

  thisOrderNumber  = getOrderNumber();

  if(doShipment(stock,*thisOrder)){
    //出荷処理に失敗した場合は空の出荷伝票を作成する
    thisTicket = printTicket(NULL,NULL,0,0);
    return thisTicket;
  }

  thisTicket = printTicket(thisOrder->consumerName,thisOrder->liquorName,thisOrder->numberOfLiquor,thisOrderNumber);

  return thisTicket;

}

void inputShipmentOrder(shipmentOrder *order){
  //本数
  int number;
  //index
  int i,j;
  //入力のための文字配列
  char str[1000];

  printf("・出荷依頼を行います.お客様の名前、欲しいお酒の銘柄、本数を入力してください.\n");

  //お客様の名前の入力
  printf("[名前:]");
  scanf("%s",str);

  //入力の文字数を調べる
  i = 0;
  while(str[i] != '\0'){
    i++;
  }

  order->consumerName = (char *)malloc(i * sizeof(char));

  //値の代入
  for(j = 0;j <= i;j++){
    order->consumerName[j] = str[j];
  }

  //銘柄の入力
  printf("[お酒の銘柄:]");
  scanf("%s",str);

  //入力の文字数を調べる
  i = 0;
  while(str[i] != '\0'){
    i++;
  }

  order->liquorName = (char *)malloc(i * sizeof(char));

  //値の代入
  for(j = 0;j <= i;j++){
    order->liquorName[j] = str[j];
  }

  printf("[本数:]");
  scanf("%d",&number);

  order->numberOfLiquor = number;

  return;

}

int getOrderNumber(){
  //注文番号
  orderNumberBase++;

  return orderNumberBase;
}

int doShipment(liquor *stock,shipmentOrder order){
  int i = 0;
  char *name;

  while(stock[i].liquorName != NULL){
    //printf("%s\n%s\n",stock[i].liquorName,order.liquorName);
    if(strcmp(stock[i].liquorName,order.liquorName) == 0){
      //名前がある場合
      if(stock[i].numberOfLiquor >= order.numberOfLiquor){
        //在庫が十分な場合
        printf("在庫が確認できました。出荷を行います。\n");
        stock[i].numberOfLiquor -= order.numberOfLiquor;
	return 0;
      }
    }
    i++;
  }

  printf("在庫が確認できませんでした.お手数ですがもう一度初めからやり直してください。\n");
  return 1;
}

ticket printTicket(char *cName,char *lName,int nOfL,int oN){
  ticket thisTicket = {cName,lName,nOfL,oN};

  if(nOfL > 0){
    printf("--出荷伝票--\n");
    printf("[注文番号]%d\n",oN);
    printf("[名前]%s\n",cName);
    printf("[お酒の銘柄]%s\n",lName);
    printf("[本数]%d本\n",nOfL);
    printf("------\n");
    printf("出荷が完了しました。\n");
  }

  return thisTicket;

}
