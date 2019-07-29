#include "liquorSystem.h"

void liquorSystem();
void readStock(liquor *stock);
void readTicketList(ticket *ticketList);
void writeStock(liquor *stock);
void writeTicketList(ticket *ticketList);

void liquorSystem(){
  liquor *stock;
  ticket *ticketList;

  readStock(stock);

  readTicketList(ticketList);

  order(stock,ticketList);

  writeStock(stock);

  writeTicketList(ticketList);

}
