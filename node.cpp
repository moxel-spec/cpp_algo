#include <iostream>
using namespace std;
    struct List 
{
    int data;
    List*next;
    
};
List *phead;
List *tail;
List* now;


void add()
{
    if(phead)
    {
        tail->next = new List;
        tail = tail->next;
        cout << "Enter data: " << endl;
        cin >> tail->data;
        tail->next = nullptr;
    }
    else 
    {
        phead = new List;
        tail = phead;
        cout << "Enter data: " << endl;
        cin >> tail->data;
        tail->next = nullptr;
    }
    
}
void show()
{
    List*now = new List;
    now = phead;
    while(now)
    {
        cout << now->data << " ";
        now = now->next;
    }
}
void add_in_head()
{
    if (phead)
    {
        now = new List;
        cout << "Enter data: " << endl;
        cin >> now->data;
        now->next = phead;
        phead=now;
        
    }
    else 
    {
        phead = new List;
        tail = phead;
        cout << "Enter data: " << endl;
        cin >> tail->data;
        tail->next = NULL;
    }
}
void delete_data(int number)
{  
    if (!phead)
    {
        cout << "List is empty!" << endl;
    }
    else 
    {
        now = phead;
        while(now)
        {
            if (now->next!=nullptr && number==now->data)
            {
                List*tmp = now->next;
                now->next = tmp->next;
                delete tmp;
            }
            else
            {
                while(phead)
                {
                    List*tmp = phead;
                    phead = phead->next;
                    delete tmp;
                }
            }
            now = now->next;
        }
        cout << endl;
    }
}
int main ()
    {
        for (;;)
        {
        cout << endl;
            cout << "1.Add new element in the end" << endl;
            cout << "2.Add new element int the start" << endl;
            cout << "3.Delete data" << endl;
            cout << "4.Show all list " << endl;
            int menu;
            cin >> menu;
            switch (menu)
            {  
                case 1:
                {
                    add();
                    break;
                }
                case 2:
                {
                    add_in_head();
                    break;
                }
                case 3:
                {
                cout << "Enter data for delete: " << endl;
                int number;
                cin >> number;
                delete_data(number);
                break;
                }
                case 4:
                {
                    show();
                    break;
                }
            }
        }
    }
