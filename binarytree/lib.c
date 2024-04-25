#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
 * Allocates the necessary memory and pointers
 */
node* createNode(int x){
  node* newNode = (node*) malloc(sizeof(node));
  newNode->content = x;
  newNode->right = NULL;
  newNode->left = NULL;  
  return newNode;
}

/*
 * Destroys the entire tree
 */
void destroyTree(node* root){
  if (root){
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
  }
}

/*
 * Finds the height of the given binary tree "root"
 */ 
unsigned int height(node* root){
  int hl, hr; 

  if (root == NULL){
    return 0;
  } else {
    hl = height(root->left);
    hr = height(root->right);

    if (hr > hl) 
      return hr + 1; 
    else 
      return hl + 1;
  }
} 
/* 
 * Finds the total number of node's of the given binary tree "root" 
 */ 
unsigned int totalOfNodes(node* root){ int ql, qr; if (root == NULL){
    return 0;
  }
  
  ql = totalOfNodes(root->left);
  qr = totalOfNodes(root->right);

  return 1 + ql + qr;
}

node* insert(node* root, int x){

  if (root == NULL){
    root = createNode(x);
    return root;
  }
  
  if (root->content > x){
    root->left = insert(root->left, x);
  }

  if (root->content < x){ 
    root->right = insert(root->right, x);
  }

  return root;
}

/*
 * Prints the tree in the order as firstly root,
 * then left node, then right node
 */
void printTree(node* root){
  if (root){
    printTree(root->left);
    printf("%d\n", root->content);
    printTree(root->right);
  }
}

