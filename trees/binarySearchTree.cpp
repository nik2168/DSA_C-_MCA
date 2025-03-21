#include <iostream>
#include <vector>
#include
using namespace std;

class node
{
public:
    int val;
    node *left;
    node *right;

    node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class tree
{
public:
    node *root;

    tree()
    {
        root = NULL;
    }
};

void preorder(node *root)
{

    if (root == NULL)
    {

        return;
    }

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{

    if (root == NULL)
    {

        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(node *root)
{

    if (root == NULL)
    {

        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void levelOrder(node * root){

}

int main()
{

    tree t;
    t.root = new node(1);
    t.root->right = new node(3);
    t.root->right->left = new node(6);
    t.root->right->right = new node(7);
    t.root->left = new node(2);
    t.root->left->left = new node(4);
    t.root->left->right = new node(5);

    cout<<"Preorder : ";
    preorder(t.root);
   cout<<endl;

    cout<<"Inorder : ";
    inorder(t.root);
   cout<<endl;

    cout<<"Postorder : ";
    postorder(t.root);
   cout<<endl;

    return 0;
} 



// output : Preorder : 1 2 4 5 3 6 7 
// Inorder : 4 2 5 1 6 3 7 
// Postorder : 4 5 2 6 7 3 1