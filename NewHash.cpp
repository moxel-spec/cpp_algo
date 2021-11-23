#include <iostream>
#include <list>
#include <string>
#include <cmath>

class HashTable
{
    static constexpr int bucketCount = 29;
    std::list<std::string> table[bucketCount];
    
    int hashFunction(const std::string &str)
    {
        int sum = 0;
        for (const auto &c: str) 
        {
            sum += c;
        }
        return sum;
    }
public:
    void insertItem(const std::string &key);
    void deleteItem(const std::string &key);
    void display();
};

void HashTable::insertItem(const std::string &key)
{
    int index = std::abs(hashFunction(key)) % bucketCount;
    table[index].push_back(key);
}

void HashTable::deleteItem(const std::string &key)
{
    int index = std::abs(hashFunction(key)) % bucketCount;
    std::list<std::string>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) 
    {
        if (*i == key) 
        {
            break;
        }
    }
    if (i != table[index].end()) 
    {
        table[index].erase(i);
    }
}

void HashTable::display()
{
    for (int i = 0; i < bucketCount; i++) {
        std::cout << i;
        for (auto x : table[i]) {
            std::cout << "----->" << x;
        }
        std::cout << std::endl;
    }
}

int main()
{
    HashTable h;
    h.insertItem("Azarov Sergey");
    h.insertItem("Akimov Volodimir");
    h.insertItem("Borzakov Andrey");
    h.insertItem("Grigorenko Vlada");
    h.insertItem("Dobronos Pavel");
    h.insertItem("Zhdanov Anton");
    h.insertItem("Zagaynov Myhailo");
    h.insertItem("Kirichenko Myhailo");
    h.insertItem("Kinchik Artem");
    h.insertItem("Kompaniec Katerina");
    h.insertItem("Kuznecova Katerina");
    h.insertItem("Mamchur Sergey");
    h.insertItem("Merezhko Maxim");
    h.insertItem("Osipenko Julia");
    h.insertItem("Pilyak Dmitro");
    h.insertItem("Pishnenko Vitaliy");
    h.insertItem("Porohovnichenko Ivan");
    h.insertItem("Samojlenko Elena");
    h.insertItem("Strel`nik Violeta");
    h.insertItem("Tendit Maxim");
    h.insertItem("Timoshenko Yana");
    h.insertItem("Cehmeysstruk Ivan");
    h.insertItem("Cuber Pavel");
    h.insertItem("Shishkanov Dmitro");
    h.insertItem("Scherbec Nataliya");
    h.insertItem("Yanko Olexiy");
    h.display();
   
}
