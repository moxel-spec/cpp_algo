#include <iostream>
#include <unordered_set>
#include <string>
//bucket == Hash(x) % bucket_count()
using namespace std;
struct Hash {
   std::size_t operator() (const std::string& kek) const {
   
     return 1;
   }
};
std::unordered_set<string,Hash> Myset;
std::hash<string> myHash;
int main ()
{
   
    
    
    
    cout << "Number of students: " << endl;
    int MAX;
    cin >> MAX;
    cin.ignore();
    string t;
    for (int i =0;i<MAX;i++)
    {
        
       std:: getline(std::cin,t);
       Myset.insert(t);
       
    }
  
    
    
    for (auto it : Myset)
    
     {
        cout << "[" << it << "] "<< "Index is: " << Myset.bucket(it) << endl <<" Hash is:" << myHash(it) <<"bucket_count() is:" << Myset.bucket_count() << endl << endl << "Teoretical index is :" << myHash(it)%Myset.bucket_count() << endl;
        
     }
    
    
   
    
}
