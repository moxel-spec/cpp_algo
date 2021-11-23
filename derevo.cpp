#include <iostream>
using namespace std;
struct Node
{
        int x;
        Node *left;
        Node *right;
        Node *parent;
        
};
    
    
    
void insert (int x, Node*&root,Node *parent = nullptr)
{
      if (root == nullptr)
      {
        
          root = new Node;
          root->x = x;
          root->parent = parent;
          root->left = nullptr;
          root->right = nullptr;
      }
      
      if (x < root->x)
      {
          insert(x,root->left,root);
      }
      else if (x > root->x)
      {
          insert(x,root->right,root);
      }
}


void print (Node*&root)
{

    if (root != nullptr)
    {
        print(root->left);
        cout << root->x << " ";
        print(root->right);
    }
}
void free_memory(Node*&root)
{
    if (root == nullptr)
    {
        return;
    }
    else 
    {
        free_memory(root->left);
        
        free_memory(root->right);
       
        delete root;
        root = nullptr;
        
    }
}



Node* max (Node*root)
{
    
    while (root && root->right)
    {
        root = root->right;
    }
    return root;
}
Node* min(Node*root)
{
    
    while (root && root->left)
    {
        root = root->left;
    }
    return root;
}
void erase_leaf(Node *leaf)
{
    Node *parent = leaf->parent;
    if (parent->left == leaf)
        parent->left = nullptr;
    else
        parent->right = nullptr;
    delete leaf;
}

void erase(Node *&root, int x)
{


    Node *node = root;
    while (node && node->x != x)
        node = (x < node->x) ? node->left : node->right;
    if (!(node->left) && !(node->right))
    {
        erase_leaf(node);
        return;
    }
    if (node->left && node->right)
    {
        Node *m = min(node->right);
        node->x = m->x;
        erase_leaf(m);
    }
    else if (node->left)
    {
        Node *parent = node->parent;
        if (!parent)
        {
            root = node->left;
            delete node;        
        } else
        if (parent->left == node)
            parent->left = node->left;
        else
            parent->right = node->left;
        delete node;
    }
    else if (node->right)
    {
        Node *parent = node->parent;
        if (!parent)
        {
            root = node->right;
            delete node;        
        } else
        if (parent->left == node)
            parent->left = node->right;
        else
            parent->right = node->right;
        delete node;
    }
}


int main ()
{
    Node*root = nullptr;
    for (;;)
    {
    cout << endl;
        cout << "1. Add " << endl;
        cout << "2. Show " << endl;
        cout << "3. Delete " << endl;
        int switcher;
        cin >> switcher;
        switch(switcher)
        {
            case 1:
            {
                int x;
                cout << "Enter a value: ";
                cin >> x;
                insert(x,root);
                break;
            }
            case 2:
            {
                print(root);
                break;
            }
            case 3:
            {
                int x;
                cout << "El for delete: " << endl;
                cin >> x;
                erase(root,x);
                break;
            }
        }
    }
}
