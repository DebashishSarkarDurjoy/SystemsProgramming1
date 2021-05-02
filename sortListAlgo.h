#ifndef SORTING_ALGO
#define SORTING_ALGO

bool isSorted(IORB* head, int(*prio)(int)) {

  IORB* current = head;
  while(current->link != NULL) {
    if ( prio(current->base_pri) > prio(current->link->base_pri))
      return false;
    current = current->link;
  }

  return true;
}

void sortList(IORB** head, int(*prio)(int)) {
  while(!isSorted(*head, priComp)) {
    IORB *secondTemp;
    for ( IORB* i = *head; i->link != NULL; i = i->link ) {

      for ( IORB* j = i; j->link != NULL ; j = j->link ) {

        if ( prio(j->base_pri) > prio(j->link->base_pri) ) {
          if (*head == j) { // is misplacement at head

            IORB* firstTemp;
            firstTemp = j->link;
            j->link = j->link->link;
            firstTemp->link = j;
            *head = firstTemp;
          }
          if (j->link == NULL) { // if misplacement at the end
            IORB* firstTemp = *head;
            while (firstTemp->link != j) firstTemp = firstTemp->link;
            secondTemp = j;
            firstTemp->link = j->link;
            j->link = secondTemp;
            secondTemp->link = NULL;
          }
          if (j->link->link != NULL) { // if misplacement in the middle
            
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
