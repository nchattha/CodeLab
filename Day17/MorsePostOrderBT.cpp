#include <iostream>
#include <vector>
#include <stack>
#include<queue>
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

vector<int> postorderTraversal(TreeNode *current)
{
    //POSTORDER - LEFT RIGHT DATA
   vector<int>result;
   stack<TreeNode*> nodeStack;
   nodeStack.push(current);
   while( !nodeStack.empty() )
   {   
       current = nodeStack.top();
       if( current->left != NULL)
       {
           nodeStack.push(current->left);
           current->left = NULL;
       }
       else
       {
            if( current->right != NULL) 
            {
                nodeStack.push(current->right);
                current->right = NULL;
            }
            else
            {   
                result.push_back(current->val);
                nodeStack.pop();
            }  
       }

   }
    return result;
}

vector<int> postorderTraversalMorse(TreeNode *current)
{
    //POSTORDER - LEFT RIGHT DATA
   vector<int>result;
   
   while( current != NULL )
   {   
       if( current->right == NULL)
       {
           result.insert(result.begin(),current->val);
           current = current->left;
       }
       else
       {
           TreeNode *predecessor = current->right;
           while(predecessor->left != NULL && predecessor->left != current)
            predecessor = predecessor->left;

            if( predecessor->left == NULL) 
            {
                result.insert(result.begin(),current->val);
                predecessor->left = current;
                current = current->right;
            }
            else
            {   
                predecessor->left = NULL;
                current = current->left;
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
    vector<int> res = postorderTraversalMorse(bTree);
    cout<<endl;
    for (auto val : res)
    {
        cout << val << " , ";
    }
    cout << "END" << endl;
    return 0;
}