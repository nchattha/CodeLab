/**
 * Given a binary tree, you need to compute the length of the diameter of the tree. The diameter 
 * of a binary tree is the length of the longest path between any two nodes in a tree. 
 * This path may or may not pass through the root.
 * 
 * Definition for a binary tree node.
 */
#include <iostream>
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

class Tree
{
    TreeNode *head;

public:
    Tree(void) : head(NULL) {}
    void addItem(int val)
    {
        if (head == NULL)
            head = new TreeNode(val);
        else
            addNode(val, head);
    }
    void printTree()
    {
        printTree(head);
    }

    // Function to print level order traversal of given binary tree
    void levelOrderTraversal()
    {
        // start from level 1 -- till height of the tree
        int level = 1;

        // run till printLevel() returns false
        while (printLevel(head, level))
        {
            level++;
            cout << endl;
        }
    }
    
    int diameterOfBinaryTree()
    {
        int leftH = 0, rightH = 0;
        if( head != NULL)
        {
            if(head->left != NULL)
                leftH = calculateHeight(head->left);
            if(head->right != NULL)
                rightH = calculateHeight(head->right); 

            cout<<leftH<<" :: "<<rightH<<endl;
        }
        return leftH+rightH;
    }


private:
    void addNode(int val, TreeNode *node)
    {

        if (node->left == NULL)
        {
            cout << "L" << endl;
            node->left = new TreeNode(val);
            return;
        }
        else if (node->right == NULL)
        {
            cout << "R" << endl;
            node->right = new TreeNode(val);
            return;
        }
        else
        {
            if (node->left != NULL && node->right == NULL)
            {
                cout << "ELSE ";
                addNode(val, node->right);
            }
            else
            {
                cout << "ELSE ";
                addNode(val, node->left);
            }
        }
    }
    void printTree(TreeNode *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->val << endl;
        printTree(node->left);
        printTree(node->right);
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

    int calculateHeight(TreeNode *node)
    {
        if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = calculateHeight(node->left);  
        int rDepth = calculateHeight(node->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
    }
};

int main(void)
{
    Tree *bTree = new Tree();
    bTree->addItem(3);
    bTree->addItem(1);
    bTree->addItem(2);
    bTree->addItem(4);
    bTree->addItem(5);
    bTree->levelOrderTraversal();
    cout<<"\n Diameter: "<<bTree->diameterOfBinaryTree()<<endl;;
}