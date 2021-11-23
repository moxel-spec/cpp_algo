#include <iostream>
using namespace std;
int main()
{
  int number;
  cout << "Enter your number: ";
  cin >> number;
  int *mass = new int[number + 1];
  for (int i = 0; i < number + 1; i++)
    mass[i] = i;
    
  for (int p = 2; p < number + 1; p++)
  {
    if (mass[p] != 0)
    {
      cout << mass[p] << endl;
      for (int j = p*p; j < number + 1; j += p)
        mass[j] = 0;
    }
  }
 
}
