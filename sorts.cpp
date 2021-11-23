#include <iostream>
#include <vector>
#define N 30
using namespace std;
void selection_sort (int*mass,int size)
    {
    int j=0;
    int tmp=0;
       for (int i = 0;i<size;i++)     // n
        {
           j=i;
           for (int k=i;k<size;k++)
            {
             if(mass[j]>mass[k])
                {
                    j=k;
                }
            }
            tmp =mass[i];
            mass[i]=mass[j];
            mass[j]=tmp;
        }
    }
    
void insertion_sort(int*mass,int size)       //O(n)
{
    int tmp;
    for (int i =1;i<size;i++)   // n 
    {
        if (mass[i-1]>mass[i])     //sum ..n(t)
        {
        tmp = mass[i];               //n-1
        i = (i-1);                    // n-1
        while(tmp < mass[i])         //sum 1..n
            {
                mass[i+1]=mass[i];      //sum 1..n(t-1)    
                i--;
            }
            mass[i+1]=tmp;
        }
    }
}
    
 
void bubble_sort(int*mass, int size)
{
  int tmp = 0;
  for(int i = 0;i<size;i++){
    for(int j = (size-1);j>=(i+1);j--){
      if(mass[j]<mass[j-1]){
        tmp = mass[j];
        mass[j]=mass[j-1];
        mass[j-1]=tmp;
      }
    }
  }
}


void shellSort(int *mass, int size)
{
  int increment = 3;    
  while (increment > 0)  
  {
    for (int i = 0; i < size; i++)  
    {
      int j = i;          
      int temp = mass[i];
     
      
      while ((j >= increment) && (mass[j - increment] > temp))
      {  
        mass[j] = mass[j - increment]; 
        j = j - increment;       
      }
      mass[j] = temp;
    }
    if (increment > 1)      
      increment = increment / 2;
    else if (increment == 1)   
      break;  
  }
}



void quickSort(int*arr, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
 
   
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
 
    
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
    
}
void CombSort(int*mass, int size )
{
  int jump = size;
  bool swapped = true;
 
  while (jump > 1 || swapped)
  {
    if (jump > 1)
      jump = (int)(jump / 1.247);
    swapped = false;
    for (int i = 0; i + jump < size; i++)
      if (mass[i] > mass[i + jump])
      {
       
            int tmp = mass[i];
            mass[i]=mass[i+jump];
            mass[i+jump]=tmp;
            swapped = true;
            }
  }
}
  int main ()
  {
    int mass[N];
    for (int i=0;i<N;i++)
        {
          mass[i]=rand()%10;
        }
        cout << "Initial mass: " << endl;
     for (int i=0;i<N;i++)
        {
          cout << mass[i] << " ";
        }   
        cout << endl;
        
         cout << "Selection sort" << endl;
        selection_sort(mass,N);
       
         for (int i=0;i<N;i++)
        {
          cout << mass[i] << " ";
        }   
        cout << endl;
        cout << endl;
        
        
        int mass1[N];
    for (int i=0;i<N;i++)
        {
          mass1[i]=rand()%10;
        }
        cout << "Initial mass: " << endl;
     for (int i=0;i<N;i++)
        {
          cout << mass1[i] << " ";
        }   
        cout << endl;
        
        cout << "Quick sort" << endl;
        quickSort(mass1,0,29);
        
         for (int i=0;i<N;i++)
        {
          cout << mass1[i] << " ";
        }   
        cout << endl;
        cout << endl;
        
        
        
        
        
        
        
        
        int mass3[N];
    for (int i=0;i<N;i++)
        {
          mass3[i]=rand()%10;
        }
        cout << "Initial mass: " << endl;
     for (int i=0;i<N;i++)
        {
          cout << mass3[i] << " ";
        }   
        cout << endl;
        
        cout << "Bubble sort" << endl;
        bubble_sort(mass3,N);
        
         for (int i=0;i<N;i++)
        {
          cout << mass3[i] << " ";
        }   
        cout << endl;
        cout << endl;
        
        
        
        
        int mass4[N];
    for (int i=0;i<N;i++)
        {
          mass4[i]=rand()%10;
        }
        cout << "Initial mass: " << endl;
     for (int i=0;i<N;i++)
        {
          cout << mass4[i] << " ";
        }   
        cout << endl;
        
        cout << "Combsort" << endl;
        CombSort(mass4,N);
        
         for (int i=0;i<N;i++)
        {
          cout << mass4[i] << " ";
        }   
        cout << endl;
        cout << endl;
        
        
        int mass5[N];
    for (int i=0;i<N;i++)
        {
          mass5[i]=rand()%10;
        }
        cout << "Initial mass: " << endl;
     for (int i=0;i<N;i++)
        {
          cout << mass5[i] << " ";
        }   
        cout << endl;
        
        cout << "Shell sort" << endl;
        shellSort(mass5,N);
        
         for (int i=0;i<N;i++)
        {
          cout << mass5[i] << " ";
        }   
        cout << endl;
        cout << endl;
        
        
        
        int mass6[N];
    for (int i=0;i<N;i++)
        {
          mass6[i]=rand()%10;
        }
        cout << "Initial mass: " << endl;
     for (int i=0;i<N;i++)
        {
          cout << mass6[i] << " ";
        }   
        cout << endl;
        
        cout << "Insertion sort" << endl;
        insertion_sort(mass6,N);
        
         for (int i=0;i<N;i++)
        {
          cout << mass6[i] << " ";
        }   
        cout << endl;
        cout << endl;



        
  }
