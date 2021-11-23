#include <iostream>
using namespace std;

    struct Stack
    {
        int key;
        Stack*next;
    
    };

    Stack *phead;
    Stack *now;
    Stack* tmp;
    Stack* previous;
    

    void push_back()
    {
        if (phead)
        {
            tmp = new Stack;
            cout << "Enter data: " << endl;
            cin >> tmp->key;
            tmp->next = phead;
            phead=tmp;
            
            
        }
        else 
        {
            phead = new Stack;
            cout << "Enter data: " << endl;
            cin >>phead->key;
            phead->next =nullptr; 
        }
    }

    void print()
    {
        if (!phead)
        {
            cout << "Stack is empty! " << endl;
            return;
        }
        
        now = new Stack;
        now = phead;
        cout << endl;
        cout << "Stack: " << endl;
        cout << "____________________________________" << endl;
        cout << "↓TOP↓  " << endl;
        
        while(now)
        {
            cout << now->key << endl;
            now = now->next;
        }
        
    cout << "____________________________________" << endl; 
    }

    void delete_phead()
    {
        if (!phead)
        {
            cout << "Stack is empty!"<< endl;
            return;
        }
        
        tmp = new Stack;
        tmp = phead;
        phead = tmp->next;
        delete tmp;
    }   


void delete_element(int number) 
{
    tmp = new Stack;
	tmp = phead; 
	previous = new Stack;
	previous = NULL;
	while (tmp != NULL) {//пока указатель tmp не пустой, мы будем выполнять код в цикле, если он все же пустой цикл заканчивается
		if (tmp->key == number) {//если key элемента равна числу, которое нам нужно удалить
			if (tmp == phead) {//если такой указатель равен вершине, то есть элемент, который нам нужно удалить - вершина
				phead = tmp->next;//передвигаем вершину на следующий элемент
				free(tmp);//очищаем ячейку
				
				tmp->next = NULL;
			}
			else//если элемент последний или находится между двумя другими элементами
			{
				previous->next = tmp->next;//Проводим связь от предыдущего элемента к следующему
				free(tmp);//очищаем ячейку 
				
				tmp->next = NULL;
			}
		}
		previous = tmp; 
		tmp = tmp->next;
	}
}


int main ()
{

    for (;;)
    {
    cout << endl;
    cout << "1.Add new element in stack " << endl;
    cout << "2.Delete phead from stack "<< endl;
    cout << "3.Delete element from stack " << endl;
    cout << "4.Print stack " << endl;
    
        int switcher;
        cin >> switcher;
       switch(switcher)
       {
        case 1:
        {
            push_back();
            break;
        }
        
        case 2:
        {
            delete_phead();
            break;
        }
        case 3:
        {
            int number;
            cout << "Enter number you want to delete: " << endl;
            cin >> number;
            delete_element(number);
            break;
        }
        case 4:
        {
            print();
            break;
        }
       }
    }
}
