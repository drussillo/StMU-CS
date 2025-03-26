/* C program by Dave Russillo. Made on for CS1311. */
#include <stdio.h>
#include <stdlib.h>


struct Node {
  int value;
  struct Node *left;
  struct Node *right;
};

void init_tree(struct Node *root) {
  void init_tree_helper(struct Node *current, int current_depth) {
    // initalize child nodes
    current->left = malloc(sizeof(struct Node));
    current->right = malloc(sizeof(struct Node));
    // keep initializing nodes until depth 3;
    // iterate only until depth 2 because children are initalized
    if(current_depth < 2) {
      init_tree_helper(current->left, current_depth + 1);
      init_tree_helper(current->right, current_depth + 1);
    }
  }
  init_tree_helper(root, 0);

  // add last row (depth 4)
  root->left->left->left->left = malloc(sizeof(struct Node));
  root->left->right->right->right= malloc(sizeof(struct Node));
  root->right->left->left->left = malloc(sizeof(struct Node));
  root->right->right->right->right= malloc(sizeof(struct Node));
  /* 
   * Result:
   *                0
   *              /   \
   *           /         \ 
   *         /             \
   *        0               0
   *       / \             / \
   *      /   \           /   \
   *     0     0         0     0
   *    / \   / \       / \   / \
   *   0   0 0   0     0   0 0   0
   *  /           \   /           \
   * 0             0 0             0
   *
   */
}


void populate_tree(struct Node *root) {
  void populate_tree_helper(struct Node *current, int difference, int set_value) {
    current->value = set_value;
    // set next difference to half of current
    difference = difference / 2;
    // minimum difference must be 1
    if(difference == 0) {
      difference = 1;
    }
    if(current->left != NULL) {
      // subtract difference on left
      populate_tree_helper(current->left, difference, set_value - difference);
    }
    if(current->right != NULL) {
      // add difference on right
      populate_tree_helper(current->right, difference, set_value + difference);
    }
  }
  populate_tree_helper(root, 10, 10);
}


void print_inorder(struct Node *current) {
  // iterate on left node
  if(current->left != NULL) {
    print_inorder(current->left);
  }

  // print current value
  printf("%d ", current->value);

  // iterate on right node
  if(current->right!= NULL) {
    print_inorder(current->right);
  }
}


int main(void) {
  struct Node *root = malloc(sizeof(struct Node));
  init_tree(root);
  populate_tree(root);
  print_inorder(root);
  printf("\n");

  return 0;
}
