#include <signal.h>
#include <stdio.h>
#ifndef NDEBUG
#include <sanitizer/lsan_interface.h>
#endif

// signal(SIGCONT, handlerCont); // kill -CONT <pid>
void handlerCont(int signum) {
  printf("SIGCONT %d\n", signum);
#ifndef NDEBUG
  __lsan_do_recoverable_leak_check();
#endif
}

#include <assert.h>
#include "foo.h"

int main() {
  signal(SIGCONT, handlerCont); // kill -CONT <pid>
  printf("main\n");
  foo();

  int a[1024];
  int n = 10240;
  // a[n] = 1; // asan
  // assert(0); // -DNDEBUG
}
