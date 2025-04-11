#include <stdlib.h>


int main(void) {
  system("ls");
  system("echo '\n'");
  system("ls *.exe");
  system("./macro.exe | grep macro");

  return 0;
}
