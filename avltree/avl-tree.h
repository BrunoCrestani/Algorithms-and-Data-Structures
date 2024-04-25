typedef struct node { 
  int content;
  struct node* right;
  struct node* left;
  int height;
  int balance;
} node;

/*
 * Creates a new node, mallocs its needed space and pointers
 */
node* createNode(int x);

/*
 * Destroys the entire tree
 */
node* destroyTree(node* root);

/*
 * Finds the height of the given AVL tree 
 */ 
int getHeight(node* tree);

/*
 * Finds the balance of the given tree
 */
int getBalance(node* root);

/*
 * Finds the total number of node's of the given AVL tree "root"
 */
unsigned int getTotal(node* root); 

/*
 * Finds the top right node from a root.
 */
node* maxValueNode(node* root);
  
/*
 * Rotates the tree to the right
 */
node* rightRotation(node* root);

/*
 * Rotates the tree to the left
 */
node* leftRotation(node* root);

/*
 * Inserts the node in its right place in the AVL tree and returns it
 */
node* insertNode(node* root, int x);

/*
 * Removes the node in which is found the content of "x".
 */
node* removeNode(node* root, int x);

/*
 * Finds the node of a given "x" number in the AVL tree.
 */
int search(node* root, int x);

/*
 * Prints the tree in the order its inserted, as firstly root,
 * then left node, then right node.
 */
void printTree(node* root);
