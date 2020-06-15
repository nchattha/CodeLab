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

int HeightOfTree(TreeNode *root)
{
    if( root == NULL ) return 0;
    return max(HeightOfTree(root->left),HeightOfTree(root->right))+1;
}

int main(void)
{
    TreeNode *bTree = new TreeNode(3);
    bTree->left = new TreeNode(1);
    bTree->right = new TreeNode(2);
    bTree->left->left = new TreeNode(4);
    bTree->left->right = new TreeNode(5);
    bTree->left->right->left = new TreeNode(6);
    bTree->left->right->right = new TreeNode(7);
    print2DUtil(bTree,0);

    cout<<"\nHeight OF Tree: " <<HeightOfTree(bTree)<<endl;
    return 0;
}