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

int MinimumDepth(TreeNode *current)
{
    queue<pair<TreeNode *, int>> nodeQueue;
    stack<int> tempData;
    int count = 0;
    bool reverse = false;
    if (current != NULL)
    {
        ++count;
        nodeQueue.push(pair<TreeNode *, int>(current, count));
        

        while (!nodeQueue.empty())
        {
            pair<TreeNode *, int> current = nodeQueue.front();
            nodeQueue.pop();

            if (current.first->left == NULL && current.first->right == NULL)
                return current.second;
            if (current.first->left != NULL)
                nodeQueue.push(pair<TreeNode *, int>(current.first->left, ++count));
            if (current.first->right != NULL)
                nodeQueue.push(pair<TreeNode *, int>(current.first->right, ++count));
        }
    }
    return count;
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

    
    cout <<"Minimum Depth: "<< MinimumDepth(bTree)<<endl;
    
    return 0;
}