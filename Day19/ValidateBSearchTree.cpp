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
#define COUNT 5
void print2DUtil(TreeNode *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    if( root->right !=  NULL)
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->val;

    // Process left child
    if( root->left !=  NULL)
    print2DUtil(root->left, space);
}

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

void swapData(int &lVal, int&rVal)
{
    lVal += rVal;
    rVal = lVal - rVal;
    lVal -= rVal;
}

bool helperBST(TreeNode* current, long long lowerLimit = -1000000000, long long upperLimit = 1000000000)
{
    if( current == NULL )return true;
    bool left = helperBST(current->left, lowerLimit, current->val);
    bool right = helperBST(current->right, current->val, upperLimit);
    cout<<left<<" : "<<right<<" : "<< (current->val > lowerLimit)<<" : "<< (current->val < upperLimit)<<endl;
    if( left && right && (current->val > lowerLimit) && (current->val < upperLimit) ) return true;    
    else return false;
}

 bool isValidBST(TreeNode* root) {
    return helperBST(root);
}

int main(void)
{
    TreeNode *bTree = new TreeNode(2147483647);
    // addNode(3, bTree);
    // addNode(7, bTree);
    // addNode(1, bTree);
    // addNode(4, bTree);
    // addNode(6, bTree);
    // print2DUtil(bTree,COUNT);
    cout <<"\n Valid BST: "<<isValidBST(bTree)<<endl;
   
    
    return 0;
    
}