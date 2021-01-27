#include <future>

int doWork(int bound){
  auto ans(0);
  while(bound--)  ++ans;
  return ans;
}

int main(int argc, char *argv[])
{
  
  int in = atoi(argv[1]);
  auto fut = std::async(std::launch::async, doWork, in);
  printf("Get the Answer: %d\n", fut.get());
  return 0;
}
