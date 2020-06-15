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

vector<vector<int>> levelorderTraversalReverse(TreeNode *current)
{
    vector<vector<int>> result;
    vector<int> temp;
    queue<TreeNode *> nodeQueue;
    stack<int> tempData;
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
                cout<<current->val<<" , ";
                temp.push_back(current->val);
                if (current->left != NULL)
                    nodeQueue.push(current->left);
                if (current->right != NULL)
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
     
    vector<vector<int>>res1 = levelorderTraversalReverse(bTree);
    cout << endl;
    for (auto val : res1)
    {
        for (auto va : val)
            cout << va << " , ";
        cout<<endl;    
    }
    
    return 0;
}