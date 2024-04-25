#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
int main(){

  node* root = createNode(10);
  insert(root, 5);
  insert(root, 15);
  insert(root, 1);

  printTree(root);
  printf("%d", root->right->content);

  printf("Total height of the tree is %d\n", height(root));

  destroyTree(root);
  return 1;
}
