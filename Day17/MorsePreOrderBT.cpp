#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void addNode(int val, TreeNode *node)
{
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(node);

    while (!nodeQueue.empty())
    {
        TreeNode *frontNode = nodeQueue.front();
        nodeQueue.pop();

        if (frontNode->left == NULL)
        {
            frontNode->left = new TreeNode(val);
            break;
        }
        else
        {
            nodeQueue.push(frontNode->left);
        }

        if (frontNode->right == NULL)
        {
            frontNode->right = new TreeNode(val);
            break;
        }
        else
        {
            nodeQueue.push(frontNode->right);
        }
    }
}

vector<int> preorderTraversal(TreeNode *root)
{
    //INOREDER DEPECT - LEFT DATA RIGHT
    vector<int> result;
   TreeNode *current = root;
   while( current != NULL )
   {    
       if( current->left == NULL)   //check for the leaf left node for curretn Node
       {
           result.push_back(current->val);// print the current Node
           current = current->right;// Move to  right
       }
       else
       {
            TreeNode *predecessor = current->left;  //Move to current LEFT
            while(predecessor->right != NULL && predecessor->right != current) // Find the RIGHT leaf for the curent left Node
            predecessor = predecessor->right;

            if( predecessor->right == NULL) //set the thread to current root node 
            {
                predecessor->right = current; //set the thread
                result.push_back(current->val);//print the Node
                current = current->left; //set current to left node
            }
            else
            {
                predecessor->right = NULL; //Remove the thread;
                if( current->right != NULL ) //Move to right node
                    current = current->right;
            }
            
       }
       

   }
    return result;
}


//PRINT TREE
#define COUNT 5
void print2DUtil(TreeNode *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->val;

    // Process left child
    print2DUtil(root->left, space);
}
int main(void)
{
    TreeNode *bTree = new TreeNode(3);
    addNode(1, bTree);
    addNode(2, bTree);
    addNode(3, bTree);
    addNode(4, bTree);
    addNode(5, bTree);
    addNode(6, bTree);
    print2DUtil(bTree, 0);
    vector<int> res = preorderTraversal(bTree);
    cout<<endl;
    for (auto val : res)
    {
        cout << val << " , ";
    }
    cout << "END" << endl;
    return 0;
}