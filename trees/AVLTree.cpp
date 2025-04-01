#include<iostream>
using namespace std;

template <typename T> class node {
    public:

    T val;
    node * left;
    node * right;
    int height;

    node (T val){
        this->val = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

template<typename T> class avlTree{;
    public:
        node <T> *root;

        avlTree()
        {
            root = NULL;
        }

        int height(node <T> * n){
               if(n == NULL) return 0;
               return n->height;
        }

        int balanceFactor(node<T> * n){
            if(n == NULL) return 0;
            return height(n->left) - height(n->right);
        }

        node<T> *rightRotate (node<T> * n){

        node<T> *x = n->left;
        node<T> *y = x->right;

        // perform rotation
        x->right = n;
        n->left = y;

        // adjusting the heights
        n->height = max(height(n->left), height(n->right));
        x->height = max(height(x->left), height(x->right));
        // y height remains the same

        return x;
        }

        node<T> *leftRotate(node<T> * n){
            node<T> * x = n->right;
            node<T> * y = x->left;

            // perform rotation
            x->left = n;
            n->right = y;

            // adjusting the heights
            n->height = max(height(n->left), height(n->right));
            x->height = max(height(x->left), height(x->right));
            // y height remains the same
            
            return x;
        }

        node<T> * insertNode(node<T> * n, T v){

            if(n == NULL) return  new node<T>(v);

            // insert node normally !
            if(n->val < v){
                n->right = insertNode(n->right, v);
            }
            else if(n->val > v){
                n->left = insertNode(n->left, v);
            }
            else{
                return n;
            }

            // adjust the height of node
            n->height = max(height(n->left), height(n->right)) + 1;

            int balance = balanceFactor(n);

            // If this n becomes unbalanced, then there are 4
            // cases

            // Left Left Case
            if (balance > 1 && v < n->left->val)
                return rightRotate(n);

            // Right Right Case
            if (balance < -1 && v > n->right->val)
                return leftRotate(n);

            // Left Right Case
            if (balance > 1 && v > n->left->val)
            {
                n->left = leftRotate(n->left);
                return rightRotate(n);
            }

            // Right Left Case
            if (balance < -1 && v < n->right->val)
            {
                n->right = rightRotate(n->right);
                return leftRotate(n);
            }

           return n;
        }

        void preOrder(node <T> * r)
        {
            if (r == NULL)
            {
                return;
            }
            
            cout<<r->val<<" ";
            preOrder(r->left);
            preOrder(r->right);
        }

        void insert(T key) { root = insertNode(root, key); }
};






int main(){

// construct a avl tree using val

vector<int> v = {40, 20, 10, 25, 30, 22, 50};

avlTree <int> t;

for(int i = 0; i < v.size(); i++){
  t.insert(v[i]);
}

t.preOrder(t.root);

    return 0;
}