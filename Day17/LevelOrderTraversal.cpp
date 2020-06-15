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

vector<int> levelorderTraversal(TreeNode *current)
{
    vector<int> result;
    queue<TreeNode *> nodeQueue;
    if (current != NULL)
    {
        nodeQueue.push(current);
        while (!nodeQueue.empty())
        {
            current = nodeQueue.front();
            nodeQueue.pop();

            if (current->left != NULL)
                nodeQueue.push(current->left);
            if (current->left != NULL)
                nodeQueue.push(current->right);

            result.push_back(current->val);
        }
    }
    return result;
}

int GetHeight(TreeNode *root)
{
    if( root == NULL ) return 0;
    return 1+max(GetHeight(root->left),GetHeight(root->right));
}

// Function to print all nodes of a given level from left to right
bool printLevel(TreeNode *root, int level)
{
    if (root == nullptr)
        return false;

    if (level == 1)
    {
        cout << root->val << " ";

        // return true if at-least one node is present at given level
        return true;
    }

    bool left = printLevel(root->left, level - 1);
    bool right = printLevel(root->right, level - 1);

    return left || right;
}

vector<vector<int>> levelorderTraversalS(TreeNode *current)
{
    vector<vector<int>> result;
    vector<int> temp;
    queue<TreeNode *> nodeQueue;
    if (current != NULL)
    {
        nodeQueue.push(current);
        nodeQueue.push(NULL);

        while (!nodeQueue.empty())
        {
            current = nodeQueue.front();
            nodeQueue.pop();
            if (current == NULL)
            {
                result.push_back(temp);
                temp.clear();
                if(!nodeQueue.empty())
                    nodeQueue.push(NULL);
            }
            else
            {
                temp.push_back(current->val);
                if (current->left != NULL)
                    nodeQueue.push(current->left);
                if (current->left != NULL)
                    nodeQueue.push(current->right);
            }
        }
    }
    return result;
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
    vector<int> res = levelorderTraversal(bTree);
    cout << endl;
    for (auto val : res)
    {
        cout << val << " , ";
    }
    cout << "END" << GetHeight(bTree)<<endl;
    vector<vector<int>>res1 = levelorderTraversalS(bTree);
    cout << endl;
    for (auto val : res1)
    {
         for (auto va : val)
            cout << va << " , ";
        cout<<endl;    
    }
    
    return 0;
}