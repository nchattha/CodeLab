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
// void inorderTraversal(TreeNode *root, vector<int> &ans)
// {
//     if( root == NULL) return;
//     inorderTraversal(root->left, ans);
//     ans.push_back(root->val);
//     inorderTraversal(root->right, ans);
// }

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> result;
    //inorderTraversal(root,result);
    stack<TreeNode *> nodeStack;
    if (root != NULL)
    {
        nodeStack.push(root);
        while (!nodeStack.empty())
        {
            TreeNode *currNode = nodeStack.top();
            if (currNode->left != NULL)
            {
                nodeStack.push(currNode->left);
                currNode->left = NULL;
            }
            else
            {
                result.push_back(currNode->val);
                nodeStack.pop();
                if (currNode->right != NULL)
                    nodeStack.push(currNode->right);
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
    vector<int> res = inorderTraversal(bTree);
    cout<<endl;
    for (auto val : res)
    {
        cout << val << " , ";
    }
    cout << "END" << endl;
    return 0;
}