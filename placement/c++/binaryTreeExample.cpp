#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Tree
{
    public:
    struct TreeNode* root;
        Tree()
        {
            root = NULL;
        }

        void insert(TreeNode* node)
        {
            int data;
            cout<<"Enter data (-1 for NULL): ";
            cin>>data;
            if(data==-1)
            {
                node = nullptr;
                return;
            }

            node->val = data;
            node->left = new TreeNode;
            node->right = new TreeNode;
            // if(root == NULL)
            // {
            //     root = node;
            // }
            cout<<"Creating Left Node for "<<data<<endl;
            insert(node->left);
            cout<<"Creating Right Node for "<<data<<endl;
            insert(node->right);
        }

        void inorder(TreeNode *node)
        {
            if(node == NULL)
                return;
            
            cout<<node->val<<" ";
            inorder(node->left);
            inorder(node->right);
        }
};

int main()
{
    Tree binaryTree;
    binaryTree.insert(binaryTree.root);
    cout<<"Inorder traversal : ";
    binaryTree.inorder(binaryTree.root);
    return 0;
}