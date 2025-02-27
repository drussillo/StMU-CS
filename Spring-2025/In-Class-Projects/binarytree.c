/* C program by Dave Russillo. Made on 02/27/2025 for CS1311. Binary tree. */
#include <stdio.h>

int a[7][7] = {0, 0, 0, 0, 0, 0, 0,
               0, 0, 1, 1, 0, 0, 0,
               0, 1, 0, 0, 1, 1, 0,
               0, 1, 0, 0, 0, 0, 1,
               0, 0, 1, 0, 0, 0, 0,
               0, 0, 1, 0, 0, 0, 0,
               0, 0, 0, 1, 0, 0, 0};
int reach[7] = {0};
int n = 6;


// depth frist search
void dfs(int v) {
  int i;

  reach[v] = 1;
  for(i = 1; i <= n; i++) {
    if(a[v][i] == 1 && reach[i] == 0) {
      printf("(from %d) visit %d\n", v, i);
      dfs(i);
    }
  }

  printf("After dfs call v=%d -> %d\n", v, i);
}


int main(void) {
  printf("Depth first serach of a 6 node tree, start visiting at 1 \n");
  dfs(1);

  return 0;
}
