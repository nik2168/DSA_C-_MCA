#include <iostream>
#include <vector>
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

bool searchNode(node *root, int val)
{

    if (root == NULL)
    {

        return false;
    }

    if (root->val == val)
    {
        return true;
    }

    if (root->val > val)
    {
      return  searchNode(root->left, val);
    }

    return searchNode(root->right, val);
}

void deleteANode(node *root, int key)
{
    if (root->left == NULL || root->right == NULL)
        return;

    if (root->left->val == key)
    {

        if (root->left->left == NULL)
        {
            root->left = root->left->right;
            return;
        }

        if (root->left->right == NULL)
        {
            root->left = root->left->left;
            return;
        }

        // else get the left child right most node;

        node *t = root->left->left;

        while (t->right != NULL)
        {
            t = t->right;
        }

        t->right = root->left->right;
        root->left = root->left->left;
        return;
    }

    if (root->right->val == key)
    {
        if (root->right->left == NULL)
        {
            root->right = root->right->right;
            return;
        }

        if (root->right->right == NULL)
        {
            root->right = root->right->left;
            return;
        }

        // else get the left child right most node;

        node *t = root->right->left;

        while (t->right != NULL)
        {
            t = t->right;
        }

        t->right = root->right->right;
        root->right = root->right->left;
        return;
    }

    else
    {
        deleteANode(root->left, key);
        deleteANode(root->right, key);
    }
}

int main()
{

    tree t;

    t.root = new node(19);
    t.root->right = new node(116);
    t.root->left = new node(15);
    t.root->left->right = new node(16);
    t.root->left->right->right = new node(17);
    t.root->left->left = new node(4);
    t.root->left->left->right = new node(5);

    cout << "Preorder : ";
    preorder(t.root);
    cout << endl;

    cout << "Inorder : ";
    inorder(t.root);
    cout << endl;

    cout << "Postorder : ";
    postorder(t.root);
    cout << endl;

    cout << "searching node 15 : "<<endl;
    bool isPresent = searchNode(t.root, 15);

    if (isPresent)
        cout << "15 is present in the tree" << endl;
    else
        cout << "15 is not present in the tree" << endl;

    deleteANode(t.root, 116);

    cout << "After deleting the node with value 15 : " << endl;

    cout << "Preorder : ";
    preorder(t.root);
    cout << endl;

    return 0;
}

// output : Preorder : 1 2 4 5 3 6 7
// Inorder : 4 2 5 1 6 3 7
// Postorder : 4 5 2 6 7 3 1