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

pair<int,int> diameterOfBinaryTreeHelper(TreeNode *root)
{
    if( root == NULL)
        return pair<int,int>(0,0);
    
    pair<int,int>lNode = diameterOfBinaryTreeHelper(root->left);
    pair<int,int>rNode = diameterOfBinaryTreeHelper(root->right);

    int height = 1+max(lNode.first,rNode.first);
    int diameter = max((lNode.first+rNode.first),max(lNode.second,rNode.second));
    return pair<int,int>(height,diameter);
}

int diameterOfBinaryTree(TreeNode *root)
{
    return diameterOfBinaryTreeHelper(root).second;
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