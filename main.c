#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct iorb {
  int base_pri;
  struct iorb *link;
  char filler[100];
} IORB;

void buildList(IORB **head, int size) {
  IORB *firstNode = malloc(sizeof(IORB));
  firstNode->link = NULL;
  firstNode->base_pri = 0;
  *head = firstNode;
  IORB *current = firstNode;

  for (int i = 1; i < size; i++) {
    IORB *newNode = malloc(sizeof(IORB));
    newNode->base_pri = i;
    current->link = newNode;
    current = newNode;
  }
  current->link = NULL;
}

void displayList(IORB *head) {
  IORB *current = head;
  while (current != NULL) {
    printf("%d\n", current->base_pri);
    current = current->link;
  }
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

int main(void) {

  IORB *head;
  int size = 10;

  while(1) {
    switch( displayMenu() ) {
      case 0: printf("Terminating..."); return 0;
      case 1: buildList(&head, size); break;
      case 2: printf("two chosen"); break;
      case 3: displayList(head); break;
    }
  }

  return 0;
}
