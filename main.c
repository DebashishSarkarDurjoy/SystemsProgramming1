#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#include "priComp.h"

typedef struct iorb {
  int base_pri;
  struct iorb *link;
  char filler[100];
} IORB;

#include "sortListAlgo.h"

void buildList(IORB **head, int size) {
  int values[] = {48, 36, 29, 96, 14, 25, 25, 81, 26, 97};
  IORB *firstNode = malloc(sizeof(IORB));
  firstNode->link = NULL;
  firstNode->base_pri = values[0];

  firstNode->filler[0] = 0 + '0';

  *head = firstNode;

  IORB *current = firstNode;
  for (int i = 1; i < size; i++) {
    IORB *newNode = malloc(sizeof(IORB));
    newNode->base_pri = values[i];
    newNode->filler[0] = i + '0';
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
    printf("\nBlock description: this is i/o request %c, ", current->filler[0]);
    printf("Base Priority: %d ", current->base_pri);
    printf(" Priority: %d\n", priComp(current->base_pri));
    current = current->link;
  }
}

int main(int argc, char* argv[]) {

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
