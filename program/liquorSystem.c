#include "liquorSystem.h"

void liquorSystem();
void readStock(liquor *stock);
void readTicketList(ticket *ticketList);
void order(liquor *stock,ticket *ticketList,int numberOfTicket);
void writeStock(liquor *stock);
void writeTicketList(ticket *ticketList);
void testStockAndTicketList(liquor *stock,ticket *ticketList);

void liquorSystem(){
  orderNumberBase = 0;
  liquor *stock;
  ticket *ticketList;

  //readStock(stock);

  //readTicketList(ticketList);

  stock = (liquor *)malloc(2 * sizeof(liquor));
  ticketList = (ticket *)malloc(2 * sizeof(ticket));
  testStockAndTicketList(stock,ticketList);
  int numberOfTicket = 1;

  order(stock,ticketList,numberOfTicket);

  //writeStock(stock);

  //writeTicketList(ticketList);

}

void testStockAndTicketList(liquor *stock,ticket *ticketList){
  liquor testLiquor;
  liquor nullLiquor = {NULL,0};
  ticket testTicket;
  ticket nullTicket = {NULL,NULL,0,0};
  char testName[] = "test";
  int testNum   = 5;
  int i;

  testLiquor.liquorName = (char *)malloc(4 * sizeof(char));
  testLiquor.numberOfLiquor = testNum;
  for(i = 0;i < 4;i++){
    testLiquor.liquorName[i] = testName[i];
  }

  stock[0].liquorName = testLiquor.liquorName;
  stock[0].numberOfLiquor = testLiquor.numberOfLiquor;
  stock[1] = nullLiquor;

  testTicket.consumerName = (char *)malloc(4 * sizeof(char));
  testTicket.liquorName = (char *)malloc(4 * sizeof(char));
  testTicket.numberOfLiquor = 3;
  testTicket.orderNumber    = 441;
  
  for(i = 0;i < 4;i++){
    testTicket.consumerName[i] = testName[i];
    testTicket.liquorName[i] = testName[i];
  }

  ticketList[0] = testTicket;
  ticketList[1] = nullTicket;

}

/*int main(void){
  liquor *stock;
  ticket *ticketList;

  
  testStockAndTicketList(stock,ticketList);

  return 0;

  }*/
  
