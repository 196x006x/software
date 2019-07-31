#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ticketDataFile "liquorTicketData.txt"
#define stockDataFile "liquorStockData.txt"

int orderNumberBase;

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
