#include "types.h"
#include "user.h"

int
main(void)
{
  char *page;
  int pid;

  page = sbrk(4096);
  if(page == (char*)-1){
    printf(1, "prottest: sbrk failed\n");
    exit();
  }
  page[0] = 'A';

  if(mprotect(page, 1) == 0)
    printf(1, "read-only page still reads %c\n", page[0]);
  else
    printf(1, "mprotect failed\n");

  pid = fork();
  if(pid == 0){
    page[0] = 'B';
    printf(1, "ERROR: protected write succeeded\n");
    exit();
  }
  if(pid > 0)
    wait();
  printf(1, "parent still reads %c\n", page[0]);

  if(munprotect(page, 1) == 0){
    page[0] = 'C';
    printf(1, "writable page now reads %c\n", page[0]);
  }

  printf(1, "unaligned mprotect: %d\n", mprotect(page + 1, 1));
  printf(1, "zero-length mprotect: %d\n", mprotect(page, 0));
  printf(1, "out-of-range mprotect: %d\n", mprotect(page + 4096, 1));
  exit();
}
