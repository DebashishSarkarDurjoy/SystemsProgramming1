#ifndef PRI_COMP
#define PRI_COMP

int priComp(int num) {
  int result;
  result = (num % 10) + (num / 10);
  return result;
}

#endif
