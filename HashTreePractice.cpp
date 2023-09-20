#include <iostream>
using namespace std;



class Node {

public:

    int SID = 0;

    Node* left = NULL;

    Node* right = NULL;

    Node* parent = NULL;
};



int depth(Node* ptr) {

    int counter = 0;

    while (ptr->parent != NULL) {

        ptr = ptr->parent;

        counter++;
    }

    return counter;
}



void enumerate(Node* ptr) {

    cout << ptr->SID << ' ';

    cout << depth(ptr) << ' ';

    cout << endl;

    if (ptr->left != NULL) {

        enumerate(ptr->left);
    }
    if (ptr->right != NULL) {

        enumerate(ptr->right);
    }
}


int isRoot(Node* ptr) {

    if (ptr->parent == NULL) {

        return 1;
    }
    else {

        return 0;
    }
}


int isLeaf(Node* ptr) {

    if (ptr->left == NULL && ptr->right == NULL) {

        return 1;
    }
    else {

        return 0;
    }
}


Node* Insert(Node* root, Node* x) {

    if (root == NULL) {

        root = x;
    }
    else {

        if (x->SID <= root->SID) {

            root->left = Insert(root->left, x);
        }
        else {

            root->right = Insert(root->right, x);
        }
    }

    return root;
}




int height(Node* x)
{
    if (x == NULL)
    {
        return 0;
    }

    if (isLeaf(x))
    {
        return 1;
    }
    else
    {
        if (height(x->left) > height(x->right))
        {
            return height(x->left) + 1;
        }
        else
        {
            return height(x->right) + 1;
        }
    }
}



int findmax(Node* root)
{
    if (root->right == NULL)
    {
        return root->SID;
    }
    else
    {
        return findmax(root->right);
    }
}



Node* rotation_counterclock(Node* root)
{
    Node* temp = root->right;

    root->right = root->right->left;

    temp->left = root;

    root = temp;
}



int main()
{
    Node x[8];

    x[0].SID = 44;
    x[1].SID = 17;
    x[2].SID = 32;
    x[3].SID = 78;
    x[4].SID = 50;
    x[5].SID = 88;
    x[6].SID = 48;
    x[7].SID = 62;

    Node* root;

    root = &x[0];

    x[0].left = &x[1];
    x[0].right = &x[3];
    x[1].right = &x[2];
    x[3].left = &x[4];
    x[3].right = &x[5];
    x[4].left = &x[6];
    x[4].right = &x[7];

    x[1].parent = &x[0];
    x[2].parent = &x[1];
    x[3].parent = &x[0];
    x[4].parent = &x[3];
    x[5].parent = &x[3];
    x[6].parent = &x[4];
    x[7].parent = &x[4];

    cout << height(&x[0]) << " " << height(&x[3]) << endl;

    cout << findmax(&x[0]) << endl;

    root = rotation_counterclock(root);

    enumerate(root);

    return 0;
}
