#include <iostream>
#include <string>
#include <vector>
using namespace std;
    class Person
    {
    private:
        string name;
        int age;
        string adress;  
    public:    
        string getName()
        {
            return name;
        }
        int getAge()
         {
           return age; 
        }
        string getAdress()
        {
            return adress;
        }
        void setName(string name)
        {
            this->name = name;
        }
        void setAge(int age)
        {
            this->age = age;
        }
        void setAdress(string adress)
         {
            this->adress = adress;
        }
    };

int main ()
{

    Person person;
    /*person.setName("Maxim");
    person.setAge(19);
    person.setAdress("Kosmonavtov 22/35");
    cout << "Name:" << person.getName() << endl << "Age: " << person.getAge() << endl << "Adress: " << person.getAdress() << endl;*/
    vector <Person> persons;
    int switcher;
    for (;;)
    {
        cout << "1. Add new person to database " << endl;
        cout << "2. Show full database " << endl;
        cin >> switcher;
        switch(switcher)
        {
            case 1: 
            {
                string name;
                cout << "Name: ";
                cin >> name;
                person.setName(name);
                
                int age;
                cout << "Age: ";
                cin >> age;
                person.setAge(age);
                
                string adress;
                cout << "Adress: ";
                cin >> adress;
                person.setAdress(adress);
                persons.push_back(person);
                break;
                  
            }
            case 2:
            {
                for (int i =0;i<persons.size();i++)
                {
                    cout <<"Name: " << person.getName() << endl;
                    cout <<"Age: " << person.getAge() << endl;
                    cout <<"Adress: " << person.getAdress() << endl;
                }
                break;
            }
        }
    }
    
}

