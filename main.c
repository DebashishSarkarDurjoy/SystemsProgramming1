#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



typedef struct iorb {
  int base_pri;
  struct iorb *link;
  char filler[100];
} IORB;


int priComp(int num) {
  int result;
  result = (num % 10) + (num / 10);
  return result;
}

#include "sortListAlgo.h"

void buildList(IORB **head, int size) {
  IORB *firstNode = malloc(sizeof(IORB));
  firstNode->link = NULL;
  firstNode->base_pri = (rand() % 100) + 1;
  *head = firstNode;
  IORB *current = firstNode;

  for (int i = 1; i < size; i++) {
    IORB *newNode = malloc(sizeof(IORB));
    newNode->base_pri = (rand() % 100) + 1;
    current->link = newNode;
    current = newNode;
  }
  current->link = NULL;
}

int displayMenu(void) {
  printf("\n\nSelect an option:\n");
  printf("0. Exit.\n");
  printf("1. Build List.\n");
  printf("2. Sort List (ascending).\n");
  printf("3. Display List.\n");
  printf("Your Choice: \n>>");
  int input;
  scanf("%d", &input);
  return input;
}



void displayList(IORB *head) {
  IORB *current = head;
  while (current != NULL) {
    printf("\nbase_pri: %d   pri: %d", current->base_pri, priComp(current->base_pri));
    current = current->link;
  }
}

int main(void) {
  srand(21);

  IORB *head;
  int size = 10;

  while(1) {
    switch( displayMenu() ) {
      case 0: printf("Terminating..."); return 0;
      case 1: buildList(&head, size); break;
      case 2: sortList(&head, priComp); break;
      case 3: displayList(head); break;
    }
  }

  return 0;
}
