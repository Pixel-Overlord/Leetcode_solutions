/* 
This program is for understandings the basics of Binary tree.

A Binary tree is a tree where each node have exactly two nodes(child nodes) except for the child nodes.

Q. What are Leaf nodes?
A. Leaf nodes are those nodes which does not have any further child nodes.

Q. What are child nodes?
A. The subnodes of a node.

Q. What are branches?
A. The either side of nodes are connected to the main node(root) via branches. Each node have a left branch and a right branch except the leaf node.

There are three types of traversal in the Binary tree:
    - Depth-first traversal : Pre-order, in-order & post-order.
    - Breadth-first traversal : level-order.

    Pre-order => root-> left-> right;
    In-order => left-> root-> right;
    post-order => left-> right-> root;
    level-order => traversal on each level


Consider a binary tree:
    preorder : {1,2,-1,-1,3,4,-1,-1,5,-1,-1};   // -1 are basically NULL or end-points.

        We form Binary-tree in order : ROOT -> LEFT branch until NULL/-1 -> RIGHT branch until NULL/-1

                    1
                  /  \  
                 2    3
                    /  \
                   4    5
 */

 #include <iostream>
 #include <vector>
 #include <queue>
 using namespace std;
 
 class Node{
 public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
 };

  // root -> left -> right
 void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }   

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
 }

 // left -> root -> right
 void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
 }

 // left -> right -> root
 void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    
    postOrder(root->right);
    postOrder(root->left);
    cout << root->data << " ";
 }

  void levelOrder(Node* root) {
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while (q.size() > 0) {
        Node* curr = q.front();
        q.pop();
        
        if (curr == NULL)   // means either the level has been traversed OR the entire tree has been traversed.
        {
            if (!q.empty()) {   // the childs are already added in queue by now.
                cout << endl;
                q.push(NULL);   // for next occurance of next line/ end of tree.
                continue;
            }
            else{
                break;
            }
        }

        cout << curr->data << " ";

        if (curr->left != NULL)
            q.push(curr->left);

        if (curr->right != NULL)
            q.push(curr->right);
    }

    cout << endl;
 }

 // Build a binary tree using pre-order sequence.
 static int idx = -1;
 Node* buildTree(vector<int>& preorder) {
    idx++;

    if (preorder[idx] == -1) {
        return NULL;
    } 

    Node* root = new Node(preorder[idx]);   // created a root node in first occurance.

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
 }

 int main() {
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preorder);

    // DFS traversal
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;

    // BFS Traversal
    levelOrder(root);
 }