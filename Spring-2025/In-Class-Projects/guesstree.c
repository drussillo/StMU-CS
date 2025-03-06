/* C program by Dave Russillo. Made on 03/04/2025 for CS1311. */
#include <stdio.h>
#include <stdlib.h>

struct Guess {
  int num;
  struct Guess *left;
  struct Guess *right;
};

void init_tree(struct Guess *root, int depth) {
  void init_tree_helper(struct Guess *current, int depth, int current_depth) {
    current->left = malloc(sizeof(struct Guess));
    current->right = malloc(sizeof(struct Guess));
    if(current_depth < depth) {
      init_tree_helper(current->left, depth, current_depth+1);
      init_tree_helper(current->right, depth, current_depth+1);
    }
  }
  init_tree_helper(root, depth, 0);
}

void populate_tree(struct Guess *root, int depth) {
  void populate_tree_helper(struct Guess *current, int depth, int current_depth, int set_num) {
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

void print_tree_inorder(struct Guess *current) {
  if(current->left != NULL && current->right != NULL) {
    print_tree_inorder(current->left);
    printf("%d ", current->num);
    print_tree_inorder(current->right);
  }
}

void guess_number(struct Guess *root, int depth) {}


int main(void) {
  // initialize tree
  struct Guess *root = malloc(sizeof(struct Guess));
  int depth = 2;
  init_tree(root, depth);
  populate_tree(root, depth);
  print_tree_inorder(root);
  printf("\n\n");
  guess_number(root, depth);


  return 0;
}
