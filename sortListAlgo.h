#ifndef SORTING_ALGO
#define SORTING_ALGO

bool isSorted(IORB* head, int(*prio)(int)) {
  for(IORB* current = head; current->link != NULL; current = current->link) {
    if ( prio(current->base_pri) > prio(current->link->base_pri) ) {
      return false;
    }
  }
  return true;
}

void sortList(IORB** head, int(*prio)(int)) {

  while(!isSorted(*head, priComp)) {
    IORB *secondTemp;
    for ( IORB* i = *head; i != NULL; i = i->link ) {
      for ( IORB* j = i; j->link != NULL ; j = j->link ) {

        if ( prio(j->base_pri) > prio(j->link->base_pri) ) {
          if (*head == j) {
            IORB* firstTemp;
            firstTemp = j->link;
            j->link = j->link->link;
            firstTemp->link = j;
            *head = firstTemp;
          }
          else if (j->link == NULL) {
            IORB* firstTemp = *head;
            while (firstTemp->link != j) firstTemp = firstTemp->link;
            secondTemp = j;
            firstTemp->link = j->link;
            j->link = secondTemp;
            secondTemp->link = NULL;

          }
          else {

            IORB* firstTemp = *head;
            while (firstTemp->link != j) firstTemp = firstTemp->link;
            secondTemp = j->link;
            j->link = j->link->link;
            firstTemp->link = secondTemp;
            secondTemp->link = j;
          }
        }
      }

    }
  }


}



#endif
