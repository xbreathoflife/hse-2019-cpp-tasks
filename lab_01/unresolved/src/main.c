#include "algorithm.h"
#include "io.h"
#include "util.h"

int main(void) {
  int a = doComputation(5, 7.0);
  int b = 5;

  max(a, b);
  logDebug('!');

  return 0;
}
