#include <stdio.h>

#define ticketDataFile "ayo"
#define stockDataFile "hey"

typedef struct{
  char consumerName[10];
  char liquorName[10];
  int  numberOfLiquor;
}shipmentOrder;

typedef struct{
  char consumerName[10];
  char liquorName[10];
  int  numberOfLiquor;
  int  orderNumber;
}ticket;

typedef struct{
  char liquorName[1000];
  int  numberOfLiquor;
}arriveOrder;
