
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

TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start,int end)
{
    if( start > end) return NULL;
    
    int mid = (start+end)/2;

    TreeNode* root = new TreeNode(nums[mid]);

    root->left = sortedArrayToBSTHelper(nums,start, mid-1);
    root->right = sortedArrayToBSTHelper(nums,mid+1, end);

    return root;


}


TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBSTHelper(nums,0,nums.size()-1);       
}

int main(void)
{
    vector<int>data = {-10,-3,0,5,9};
    
    TreeNode * root = sortedArrayToBST(data);
    print2DUtil(root,COUNT);
    return 0;
    
}
