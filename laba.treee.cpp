
#include <cstdio> 
#include <iostream>
#include <string>

using namespace std;

struct Node
{
 int x;
 Node *l, *r;
 Node *head;
};

int menu()
{ 
 cout << endl;
 cout << "Выберите пункт меню:" << endl
  << "1. Добавить элемент в дерево" << endl
  << "2. Поиск по значению элемента" << endl
  << "3. Удаление элемента" << endl
  << "4. Обход" << endl
  << "5. Выход из программы" << endl;
 int x;
 cin >> x;
 return x;
}

void add(int x, Node *&tree)
{
 if (tree == NULL)
 {
  tree = new Node;
  tree->x = x;
  tree->head = tree; 
  tree->l = tree->r = NULL;
  return;
 }
 if (x == tree->x)
 {
  cout << "Такой элемент дерева уже существует!" << endl;
  return;
 }
 if (x < tree->x)
 {
  if (tree->l != NULL) add(x, tree->l);
  else
  {
   tree->l = new Node;
   tree->l->x = x;
   tree->l->l = tree->l->r = NULL;
  }

 }
 else {
  if (tree->r != NULL) add(x, tree->r);
  else
  {
   tree->r = new Node;
   tree->r->x = x;
   tree->r->l = tree->r->r = NULL;
  }
 }
}



void search(int x, Node *&tree)
{
 if (tree->x > x) {
  if (tree->l->x == x) {
   cout << "Узел - " << tree->l->x << endl;
   cout << "Родитель - " << tree->x << endl;
   if (tree->l->l)
    cout << "Левый потомок - " << tree->l->l->x << endl;
   else cout << "Левый потомок - нет" << endl;
   if (tree->l->r)
    cout << "Правый потомок - " << tree->l->r->x << endl;
   else cout << "Правый потомок - нет" << endl;
   return;
  }
 }
 else if (tree->x < x)
 {
  if (tree->r)
   if (tree->r->x == x) {
    cout << "Узел - " << tree->r->x << endl;
    cout << "Родитель - " << tree->x << endl;
    if (tree->r->l)
     cout << "Левый потомок - " << tree->r->l->x << endl;
    else cout << "Левый потомок - нет" << endl;
    if (tree->r->r)
     cout << "Правый потомок - " << tree->r->r->x << endl;
    else cout << "Правый потомок - нет" << endl;
    return;
   }
 }
 if (tree->x > x)
  search(x, tree->l);
 if (tree->x < x)
  search(x, tree->r);
  
 if (tree->head->x == x)
 {
  cout << "Узел - " << tree->x << endl;
  cout << "Родитель - нет" << endl;
  cout << "Левый потомок - " << tree->head->l << endl;
  cout << "Правый потомок - " << tree->head->r << endl;
 }

}

void minim(Node *&x, Node *&z)
{
 while (x->l != NULL)
  x = x->l;
 z->x = x->x;
 if (x->r)
  x = x->r;
 else x = NULL;

}

void delt(int x, Node *&tree)
{
 Node *t = tree;
 if (tree->x > x) {

  if (tree->l)
   if (tree->l->x == x)
   {
    if (!(tree->l->l) && !(tree->l->r))
    {
     delete tree->l;
     tree->l = NULL;
     return;
    }
    if ((tree->l->l) && !(tree->l->r))
    {
     tree->l = t->l->l;
    }
    if ((t->l->r) && !(t->l->l))
    {
     tree->l = tree->l->r;
    }
    if ((t->l->l) && (t->l->r))
    {
     minim(tree->l->r, tree->l);
    }
   }
   else
   {
    if (tree->l->x > x)
     delt(x, tree->l);
    else
     delt(x, tree->r);
   }
 }
 else if (tree->x < x) {
  if (tree->r)
   if (tree->r->x == x)
   {
    if (!(tree->r->l) && !(tree->r->r))
    {
     delete tree->r;
     tree->r = NULL;
     return;
    }
    if ((tree->r->l) && !(tree->r->r))
    {
     tree->r = t->r->l;
    }
    if ((t->r->r) && !(t->r->l))
    {
     tree->r = tree->r->r;
    }
    if ((t->r->l) && (t->r->r))
    {
     minim(tree->r->l, tree->r);
    }
   }
   else
   {
    if (tree->r->x > x)
     delt(x, tree->l);
    else
     delt(x, tree->r);
   }
 }
 else if (tree->x == x) {
  delete tree;
  tree = NULL;
 }
}


void pr1(Node *&tree)
{
 if (tree != NULL)
 {
  cout << tree->x << " ";
  pr1(tree->l);
  pr1(tree->r);
 }
}
void pr(Node *&tree)
{
 if (tree != NULL)
 {
  pr(tree->l);
  pr(tree->r);
 }

}
bool prov(Node *&tree, int x)
{
 bool q = false;
 if (tree != NULL)
 {
  if (tree->x == x)

  {
   q = true;
   return q;
  }
  pr(tree->l);
  pr(tree->r);
 }

 if (tree->x == NULL) {
  cout << "Такого элемента нет!" << endl;
  return q;
 }
}

void ob(Node *&tree)
{
 if (tree != NULL)
 {
  ob(tree->l);
  ob(tree->r);
  cout << tree->x << " ";
 }
}


void show(Node *&tree, int x, int n)
{
 if (tree != NULL)
 {
  if (x == 0)
  {
   cout << tree->x << " ";
  }
  if (x == 0 || x == n) {
   if (tree->l)
    cout << tree->l->x << " ";
   if (tree->r)
    cout << tree->r->x << " ";
  }
  x++;
  n++;
  if (x == n)
   show(tree->l, x, n);
  show(tree->r, x, n);
 }


}

void showsim(Node *&tree)
{
 if (tree != NULL)
 {
  showsim(tree->l);
  cout << tree->x << " ";
  showsim(tree->r);
 }

}

int main() {



 Node *tree = NULL;

 for (;;) {
 
  int x = menu();
  switch (x) {
  case 1:
  {
   int a;
   cout << "Введите значение элемента: ";
   cin >> a;
   add(a, tree);
   bool q1 = prov(tree, a);
   if (q1 == false) break;
  }
  break;
  case 2:
  {
   int b;
   cout << "Введите значение элемента: ";
   cin >> b;
   search(b, tree);
   break;
  }
  case 3:
   int c;
   cout << "Введите значение элемента: ";
   cin >> c;
   delt(c, tree);
   break;
  case 4:
   cout << "прямой обход - ";  // узел - левое - правое
   pr1(tree);
   cout << endl;
   cout << "симметричный обход - "; // левое- узел - правое
   showsim(tree);
   cout << endl;
   cout << "обратный обход - "; //  левое - правое - узел
   ob(tree);
   cout << endl;
   cout << "обход в ширину - "; // по строкам
   show(tree, 0, 0);
   cout << endl;
   break;

  case 5:
   cout << "Выход из программы..." << endl;
   exit(EXIT_SUCCESS);
   break;
  default:
   cerr << "Неверный номер пункта!" << endl;
   break;
  }
 }
 return 0;
}
