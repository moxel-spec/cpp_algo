#include <iostream>
#include <stdlib.h>
 using namespace std;

 
  struct Node                           
    {
       int x;                           
       Node *Next;                      
    };
 

 
class List
{
    Node *Head, *Tail;                  
public:
     List():Head(NULL),Tail(NULL){};    
     ~List();                           
     void Add(int x);                   
     void Show();                       
     void del();                       
 
 };
 
 
List::~List() 
{
 Node *temp = Head;                     
 while (temp != NULL)                   
 
   {
     temp = Head->Next;                 
 
     delete Head;                       
 
     Head = temp;                       
 
   }
}
 
 

 
void List::Add(int x)
{
    Node *temp = new Node;              
    temp->x = x;                        
    temp->Next = NULL;                  
 
    if (Head != NULL)                   
    {
        Tail->Next = temp;              
        Tail = temp;
    }     else Head = Tail = temp;      
}
 

void List::Show()
{
    Node *temp = Head;                  
     while (temp != NULL)               
     {
         cout << temp->x << " ";        
         temp = temp->Next;             
     }
    cout << endl;
}
 
 
 

void List::del()
{
    if (Head != NULL)                   
    {
        Node *temp = Head;             
        cout << "ЭЛЕМЕНТ " << Head->x << " ВЫШЕЛ" << endl;
        Head = Head->Next;             
        delete temp;                    
    }
}
 
 
 
int main()
{
   List lst;
   for (;;)
   {
    cout << "1.Add " << endl;
    cout << "2.Delete " << endl;
    cout << "3.Show " << endl;
    int switcher;
    cin >> switcher;
    switch(switcher)
    {
        case 1:
        {
            cout << "value: " << endl;
            int value;
            cin >> value;
            lst.Add(value);
            break;
        }
        case 2:
        {
          lst.del();
          break;
            
        }
        case 3:
        {
            lst.Show();
            break;
            
        }
    }
   }
   return 0;
}
