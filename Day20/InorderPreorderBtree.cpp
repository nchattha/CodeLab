#include <iostream>
#include <vector>

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
TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int start, int end, int &preIndex) {
    int searchIndex = 0;
    if( start > end) return NULL;
    TreeNode *node = new TreeNode(preorder[preIndex++]);

    for( int i = start; i <= end ; i++)
    {
        if( inorder[i]==node->val)
        {
            searchIndex = i;
            break;
        }
    }

    if( start == end) return node;

    node->left = buildTreeHelper(preorder, inorder, start,searchIndex-1,preIndex);
    node->right = buildTreeHelper(preorder, inorder,searchIndex+1,end,preIndex);
    return node;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int searchIndex = 0;
    if( preorder.size() == 0 || inorder.size() == 0 ) return NULL;
    return buildTreeHelper(preorder,inorder,0,inorder.size()-1 ,searchIndex);
}

int main(void)
{
    vector<int>preorder = {3,9,20,15,7};
    vector<int>inorder = {9,3,15,20,7};    
    TreeNode * root = buildTree(preorder,inorder);
    print2DUtil(root,COUNT);
    return 0;
    
}