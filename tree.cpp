#include <iostream>
using namespace std;

struct node
    {
        int info;
        node *l;
        node *r;
    };
    
  node *tree = nullptr;
void push(int a,node**t)
    {
        if ((*t)==nullptr)
        {
            (*t) = new node;
            (*t)->info = a;
            (*t)->l = (*t)->r = nullptr;
            return;
        }
        
        if (a>(*t)->info)
        {
            push(a,&(*t)->r);
        }  
        else push(a,&(*t)->l);
    }
void print (node*t, int u)
    {
        if (t == nullptr) return;
        else
        {
            print(t->l,++u);
            for (int i =0;i<u;++i) cout << "|";
            cout << t->info << endl;  
            u--;
                
        }
        print (t->r,++u);
    }
    
    
int main ()
    {
       int n;
       int s;
       cout << "ENter number of elements: ";
       cin >> n; 
       for (int i =0;i<n;++i)
       {
        cout << "Enter number: " << endl;
        cin >> s;
        push(s,&tree);
       }
       cout << "Tree: " << endl;
       print(tree,0);
    }
