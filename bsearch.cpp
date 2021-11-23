#include <iostream>
using namespace std;

int bsearch (int*mass,size_t size,int key)
{
 int left;
 int right;
 int mid;
 left = 0;
 right = size-1;
 while (left<=right)
 {
  mid = (right+left) /2;
  if (mass[mid]==key)
  return mid;
  else if (key >mass[mid]) 
     left = mid+1;
      else right = mid-1;
 }
 return -1;
}
int main ()
{
int index =0;
int key =8;
int mass[10];
for (int i=0;i<10;i++)
{
  mass[i] = i*2;
}
for (int i =0;i<10;i++)
{
cout << mass[i] << " ";
}
cout << endl;
cout << bsearch(mass,10,8);
}
