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
TreeNode* buildTreeHelper(vector<int>& postOrder, vector<int>& inorder, int start, int end, int &postIndex) {
    int searchIndex = 0;
    if( start > end) return NULL;
    TreeNode *node = new TreeNode(postOrder[postIndex--]);
    

    for( int i = start; i <= end ; i++)
    {
        if( inorder[i]==node->val)
        {
            searchIndex = i;
            break;
        }
    }

    if( start == end) return node;

    node->right = buildTreeHelper(postOrder, inorder,searchIndex+1,end,postIndex);
    node->left = buildTreeHelper(postOrder, inorder, start,searchIndex-1,postIndex);
    
    return node;
}


TreeNode* buildTree(vector<int>& postOrder, vector<int>& inorder) {
    int searchIndex = postOrder.size()-1;
    if( postOrder.size() == 0 || inorder.size() == 0 ) return NULL;
    return buildTreeHelper(postOrder,inorder,0,inorder.size()-1 ,searchIndex);
}

int main(void)
{
    vector<int>postOrder = {9,15,7,20,3};
    vector<int>inorder = {9,3,15,20,7};    
    TreeNode * root = buildTree(postOrder,inorder);
    print2DUtil(root,COUNT);
    return 0;
    
}