#include <stdio.h>
#include <stdlib.h>
#include "avl-tree.h"

/*
 * Allocates the necessary memory and pointers
 */
node* createNode(int x){
  node* newNode = (node*) malloc(sizeof(node));
  newNode->content = x;
  newNode->right = NULL;
  newNode->left = NULL;
  newNode->height = 1;
  newNode->balance = 0;

  return newNode;
}

/*
 * Destroys the entire tree
 */
node* destroyTree(node* root){
  node* temp;
  if (root){
    temp = root;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
  }
  return temp;
}

/*
 * returns the height of the given tree
 */
int getHeight(node* root){
  if (!root) 
    return 0;

  int hl = getHeight(root->left);
  int hr = getHeight(root->right);

  if (hl > hr)
    return hl + 1;
  return hr + 1;
} 

/*
 * Finds the balance of the given tree
 */
int getBalance(node* root){

  if (!root)
    return 0;

  int balance = (getHeight(root->left) - getHeight(root->right));
  return balance;
}

/* 
 * Finds the total number of node's of the given binary tree "root" 
 */ 
unsigned int getTotal(node* root){ 
  int ql, qr; 

  if (!root){
    return 0;
  }
  
  ql = getTotal(root->left);
  qr = getTotal(root->right);

  return 1 + ql + qr;
}

node* maxValueNode(node* root){

  node* current = root;

  while(current->right != NULL)
    current = current->right;

  return current;
}

/*
 * Rotates the tree to the right
 */
node* rightRotation(node* root){
  node *j, *k; 

  j = root->left;
  k = j->right;

  j->right = root;
  root->left = k;

  root->height = getHeight(root);
  j->height = getHeight(j); 
  return j;
}

/*
 * Rotates the tree to the left
 */
node* leftRotation(node* root){
  node *j, *k;

  j = root->right;
  k = j->left;
  
  j->left = root;
  root->right = k;
    
  root->height = getHeight(root);
  j->height = getHeight(j);

  return j;
}

node* insertNode(node* root, int x){
  // Conventional binary tree insertion
  if (!root){
    return createNode(x);
  }
  
  if (root->content > x)
    root->left = insertNode(root->left, x);
  else if (root->content < x)
    root->right = insertNode(root->right, x);
  else 
    return root;

  // Height & balance adjustment 
  root->height = getHeight(root);
  root->balance = getBalance(root);

  // 1. In case the unbalance is in the left side
  if (root->balance > 1){

    // a) In case the unbalance is in the left side of the left side of the tree
    if (getBalance(root->left) > 0)
      return rightRotation(root);

    // b) In case the unbalance is in the right side of the left side of the tree
    if (getBalance(root->left) < 0){
      root->left = leftRotation(root->left);
      return rightRotation(root);
    }
  }
 
  // 2. In case the unbalance is in the right side
  if (root->balance < -1){
    // a) In case the unbalance is in the right side of the right side of the tree
    if (getBalance(root->right) < 0)
      return leftRotation(root);

    // b) In case the unbalance is in the left side of the right side of the tree 
    if (getBalance(root->right) > 0){
      root->right = rightRotation(root->right);
      return leftRotation(root);
    }
  }
  return root;
}

/* 
 * Finds the node of a given "x" number in the AVL tree.
 */ 
int search(node* root, int x){
  if(!root){
    printf("\b");
    printf("\n");
    return 0;  
  }
  
  printf("%d", root->content);

  if(root->content == x){
    printf("\n");
    return 1;  
  } else {

    if (root->content > x){
      if(root->left) printf(",");
    
      return search(root->left, x);
    }

    if (root->content < x){
      if(root->right) printf(",");
     
      return search(root->right, x);
    }
  }
  return 0;
}

/*
 * Removes the node in which is found the content of "x".
 */
node* removeNode(node* root, int x){

 // Process to find the node that has x as its content 
  if(!root)
    return root;

  if(root->content > x)
    root->left = removeNode(root->left, x);

  if(root->content < x)
    root->right = removeNode(root->right, x);

  // 1. the node tha contains what will be removed is found
  else
    {
    // a) & b) in case the node does NOT have at least a child
    if( (root->left == NULL) || (root->right == NULL) ){
      node *temp = NULL;

      //Sets the temporary node to the child remaining
      if(root->left) 
        temp = root->left;
      temp = root->right;
      
      //Case that it does not have a single child
      if (temp == NULL){
        temp = root;
        root = NULL;
      }
      //if it does, it gives the childs value to the
      //node that has the content that is going to be removed
      else
      *root = *temp; 
      free(temp);
      }
      else{
        //c) in case the node has both its children
        node* temp = maxValueNode(root->left);
 
        // finds the biggest content smaller than the one to be removed
        // and inserts it in the node in which the content to be removed was found
        root->content = temp->content;
 
        // Delete the node of the smallest content before the node
        // of the content to be found
        root->left = removeNode(root->left, temp->content);
      }
    }

  if(!root)
    return root;

  // Updating height and balance 
  root->height = getHeight(root);
  root->balance = getBalance(root);
 
  // 1. In case the unbalance is in the left side
  if (root->balance > 1){

    // a) In case the unbalance is in the left side of the left side of the tree
    if (getBalance(root->left) > 0)
      return rightRotation(root);

    // b) In case the unbalance is in the right side of the left side of the tree
    if (getBalance(root->left) < 0){
      root->left = leftRotation(root->left);
      return rightRotation(root);
    }
  }
 
  // 2. In case the unbalance is in the right side
  if (root->balance < -1){
    // a) In case the unbalance is in the right side of the right side of the tree
    if (getBalance(root->right) < 0)
      return leftRotation(root);

    // b) In case the unbalance is in the left side of the right side of the tree
    if (getBalance(root->right) > 0){
      root->right = rightRotation(root->right);
      return leftRotation(root);
    }
  }
  return root;
}

/*
 * Prints the tree in the order as firstly root, then left node, then right node 
 */
void printTree(node* root) {
    if (root == NULL) {
        printf("()");
        return;
    }

    printf("(%d", root->content);
    printf(",");
    printTree(root->left);
    printf(",");
    printTree(root->right);
    printf(")");
}
