typedef struct node { 
  int content;
  struct node* right;
  struct node* left;
} node;

/*
 * Creates a new node, mallocs its needed space and pointers
 */
node* createNode(int x);

/*
 * Destroys the entire tree
 */
void destroyTree(node* root);

/*
 * Finds the height of the given binary tree "t"
 */ 
unsigned int height(node* root);

/*
 * Finds the total number of node's of the given binary tree "t"
 */
unsigned int totalOfNodes(node* root); 

/*
 * Inserts the node in its right place in the binary tree and returns it;
 */
node* insert(node* root, int x);

/*
 * Prints the tree in the order its inserted, as firstly root,
 * then left node, then right node
 */
void printTree(node* root);
