/**
 * Given a binary tree, you need to compute the length of the diameter of the tree. The diameter 
 * of a binary tree is the length of the longest path between any two nodes in a tree. 
 * This path may or may not pass through the root.
 * 
 * Definition for a binary tree node.
 */
#include <iostream>
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
int calculateHeight(TreeNode *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(calculateHeight(node->left), calculateHeight(node->right));
}

int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int option1 = calculateHeight(root->left) + calculateHeight(root->right);
    int option2 = diameterOfBinaryTree(root->left);
    int option3 = diameterOfBinaryTree(root->right);
    return max(option1, max(option2, option3));
}

int main(void)
{
    TreeNode *bTree = new TreeNode(3);
    addNode(1, bTree);
    addNode(2, bTree);
    addNode(4, bTree);
    addNode(5, bTree);
    cout << "\n Diameter: " << diameterOfBinaryTree(bTree) << endl;
}