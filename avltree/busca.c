#include <stdio.h>
#include <stdlib.h>
#include "avl-tree.h"

int main(){
  char action;
  int x;

  node* root = NULL;

  while(!feof(stdin)){
    scanf("%c %d", &action, &x);

    if(action == 'i'){
      root = insertNode(root, x);
      printf("%c %d\n", action, x);
      printTree(root);
      printf("\n");
    }

    if(action == 'r'){
      root = removeNode(root, x);
      printf("%c %d\n", action, x);
      printTree(root);
      printf("\n");
    }

    if(action == 'b'){
      printf("%c %d\n", action, x);
      search(root, x);
    }
  }

  destroyTree(root);
  return 1;
}
