#include <iostream>
#include <cstdlib>
using namespace std;


int NOD(int a, int b) 
{

	    while (a != b) 
	    {
		    if (a > b) 
		        {
			        a = a - b;
		        } 
		            else
		                {
			                b = b - a;
		                }
	    }
	    return a;
}


int NOD_1(int k,int l)
{
 if(k==0) return l;
    else return NOD_1(l % k,k)
}


    int NOD_2(int a,int b)
    {
    if (a==b)
    {
    return a;
    }
    if (a>b)
    {
    int tmp = a;
    a=b;
    b=tmp;
    }
    return NOD_2(a,b-a);
    }
    
int main ()
    {
    for (;;)
    {
       int k;
       int l;
       cout << "Enter k: "; cin>>k;
       cout << "Enter l: "; cin >>l;
       cout << NOD(abs(k),abs(l)) << endl;
   }
    }
