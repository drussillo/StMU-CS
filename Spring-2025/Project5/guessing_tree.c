/* C program by Dave Russillo. Made on for CS1311. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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

  // add second to last row (depth 4)
  root->left->left->left->left = malloc(sizeof(struct Node));
  root->left->right->right->right= malloc(sizeof(struct Node));
  root->right->left->left->left = malloc(sizeof(struct Node));
  root->right->right->right->right= malloc(sizeof(struct Node));
  // add last row (depth 5)
  root->right->right->right->right->right = malloc(sizeof(struct Node));
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
   *                                \
   *                                 0
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
  /* 
   * Result:
   *               10
   *              /   \
   *           /         \ 
   *         /             \
   *        5              15 
   *       / \             / \
   *      /   \           /   \
   *     3     7         13    17 
   *    / \   / \       / \   / \
   *   2   4 6   8     12 14 16  18 
   *  /           \   /           \
   * 1             9 11            19 
   *                                \
   *                                20
   */
}


void print_preorder(struct Node *current) {
  // print current value
  printf("%d ", current->value);

  // iterate on left node
  if(current->left != NULL) {
    print_preorder(current->left);
  }

  // iterate on right node
  if(current->right!= NULL) {
    print_preorder(current->right);
  }
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


void print_postorder(struct Node *current) {
  // iterate on left node
  if(current->left != NULL) {
    print_postorder(current->left);
  }

  // iterate on right node
  if(current->right!= NULL) {
    print_postorder(current->right);
  }

  // print current value
  printf("%d ", current->value);
}


void take_user_input(struct Node *current) {
  char choice = ' ';
  bool valid_choice = false;

  printf(" _____________________________\n"
         "|                             |\n"
         "|  I think your number is %2d  |\n"
         "|_____________________________|\n"
         "|                             |\n"
         "|  Am I right?                |\n"
         "|=============================|\n"
         "|    a) Yes                   |\n"
         "|    b) My number is higher   |\n"
         "|    c) My number is lower    |\n"
         "|_____________________________|\n\n", current->value);
  while(!valid_choice) {
    printf("..? ");
    choice = getchar();
    valid_choice = choice == 'a' || choice == 'b' || choice == 'c';
    while(getchar() != '\n');
    if(!valid_choice) {
      printf("Invalid answer! Try again.\n");
    }
  }
  if(choice == 'c') {
    if(current->left != NULL) {
      take_user_input(current->left);
    } else {
      printf("Invalid number!\n");
    }
  } else if(choice == 'b') {
    if(current->right != NULL) {
      take_user_input(current->right);
    } else {
      printf("Invalid number!\n");
    }
  } else {
    printf("I guessed right! Your number is %d.\n\n", current->value);
  }
}


int main(void) {
  struct Node *root = malloc(sizeof(struct Node));
  init_tree(root);
  populate_tree(root);

  print_preorder(root);
  printf("\n");
  print_inorder(root);
  printf("\n");
  print_postorder(root);
  printf("\n\n");

  printf("Think of a number between 1 and 20 and I will try to guess it.\n"
         "Press enter to start ...");
  while(getchar() != '\n');
  printf("\n\n");

  take_user_input(root);

  return 0;
}
