#include "types.h"
#include "user.h"

int
main(void)
{
  int i, pid;
  int priorities[3] = {5, 10, 15};
  volatile uint count;

  set_priority(getpid(), 1);
  for(i = 0; i < 3; i++){
    pid = fork();
    if(pid < 0){
      printf(1, "schedtest: fork failed\n");
      exit();
    }
    if(pid == 0){
      // Several timer ticks of CPU work; the volatile value keeps the loop.
      for(count = 0; count < 50000000U; count++)
        ;
      printf(1, "priority %d finished\n", priorities[i]);
      exit();
    }
    if(set_priority(pid, priorities[i]) < 0){
      printf(1, "schedtest: set_priority failed\n");
      exit();
    }
  }

  for(i = 0; i < 3; i++)
    wait();
  printf(1, "Done\n");
  exit();
}
