/* C program by Dave Russillo. Made on 03/04/2025 for CS1311. */
#include <stdio.h>
#include <stdlib.h>

struct Guess7 {
  int num;
  struct Guess7 *left;
  struct Guess7 *right;
};

void init_tree(struct Guess7 *root, int depth) {
  void init_tree_helper(struct Guess7 *current, int depth, int current_depth) {
    current->left = malloc(sizeof(struct Guess7));
    current->right = malloc(sizeof(struct Guess7));
    if(current_depth < depth) {
      init_tree_helper(current->left, depth, current_depth+1);
      init_tree_helper(current->right, depth, current_depth+1);
    }
  }
  init_tree_helper(root, depth, 0);
}

void populate_tree(struct Guess7 *root, int depth) {
  void populate_tree_helper(struct Guess7 *current, int depth, int current_depth, int set_num) {
    current->num = set_num;
    if(current->left != NULL && current->right != NULL) {
      populate_tree_helper(current->left, depth, current_depth+1, set_num - (1 << (depth-1 - current_depth)));
      populate_tree_helper(current->right, depth, current_depth+1, set_num + (1 << (depth-1 - current_depth)));
    }
  }
  // use bitwise shifting for pow(2, depth)
  // 1 shifted four times becomes 10000 which is 16 or pow(2, 4)
  int root_value = 1 << depth;
  populate_tree_helper(root, depth, 0, root_value);
}

void print_tree_inorder(struct Guess7 *current) {
  if(current->left != NULL && current->right != NULL) {
    print_tree_inorder(current->left);
    printf("%d ", current->num);
    print_tree_inorder(current->right);
  }
}

void guess_number(void);

int main(void) {
  // initialize tree
  struct Guess7 *root = malloc(sizeof(struct Guess7));
  int depth = 5;
  init_tree(root, depth);
  populate_tree(root, depth);
  print_tree_inorder(root);
  printf("\n\n");

  printf("Input number between 1 and 7. Program will try to guess it.\n");

  return 0;
}
