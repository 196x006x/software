#include <stdio.h>
#include <stdlib.h>

#define ticketDataFile "ayo"
#define stockDataFile "hey"

liquor *stock;
ticket *ticketList;

typedef struct{
  char *liquorName;
  int  numberOfLiquor;
}liquor;

typedef struct{
  char *consumerName;
  char *liquorName;
  int  numberOfLiquor;
}shipmentOrder;

typedef struct{
  char *consumerName;
  char *liquorName;
  int  numberOfLiquor;
  int  orderNumber;
}ticket;

typedef struct{
  char *liquorName;
  int  numberOfLiquor;
}arriveOrder;

