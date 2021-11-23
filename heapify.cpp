#include <iostream>
using namespace std;

class Heap
 {
  static const int SIZE = 100; 
  int *h;        
  int HeapSize; 
public:
  Heap();  
  void addelem(int);  
  void outHeap();  
  void out();  
  int getmax();  
  void heapify(int);  
};


Heap :: Heap() {
  h = new int[SIZE];
  HeapSize = 0;
}


void Heap :: addelem(int n) {
  int i, parent;
  i = HeapSize;
  h[i] = n;
  parent = (i-1)/2;
  while(parent >= 0 && i > 0)  {
    if(h[i] > h[parent]) {
      int temp = h[i];
      h[i] = h[parent];
      h[parent] = temp;
    }
    i = parent;
    parent = (i-1)/2;
  }
  HeapSize++;
}


void Heap:: outHeap(void) {
  int i = 0;
  int k = 1;
  while(i < HeapSize) {
    while((i < k) && (i < HeapSize)) {
      cout << h[i] << " ";
      i++;
    }
    cout << endl;
    k = k * 2 + 1;
  }
}

void Heap:: out(void) {
  for(int i=0; i< HeapSize; i++) {
    cout << h[i] << " "; }
  cout << endl;
}



int Heap:: getmax(void) {
  int x;
  x = h[0];
  h[0] = h[HeapSize-1];
  HeapSize--;
  heapify(0);
  return(x);
}


int main ()
{
    Heap heap;
    for (;;)
    {
        cout << "Heapify" << endl;
        cout << "1.Add new element " << endl;
        cout << "2.Print heapify as massive " << endl;
        cout << "3.Print heapify as heap " << endl;
        cout << "4.Get root " << endl;
        cout << "5.Regularize " << endl;
        int switcher;
        cin >> switcher;
        switch(switcher)
        {
        case 1:
           {
            int k;
           cout << "Enter element " << endl;
           cin >> k;
           heap.addelem(k);
           break;
           }
           case 2:
           {
            heap.out();
            break;
           }
           case 3:
           {
            heap.outHeap();
            break;
           }
           case 4:
           {
            heap.getmax();
            break;
           }
        }
    }
    

}
