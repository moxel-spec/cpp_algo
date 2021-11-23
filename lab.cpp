#include <iostream>
#include <list>
#include <string>
#include <cmath>

class HashTable
{
    static constexpr int bucketCount = 5;
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
    while (1)
    {
		std::cout << "1. Add new student\n"
				  << "2. Delete student\n"
				  << "3. Show hash-table\n"
				  << "4. Exit\n";
		
		int switcher;
        std::cin >> switcher;
        
        if (switcher == 4)
        {
			break;
		}
        
        while (std::cin.get() != '\n'); // прочитать строку до конца
        
        switch (switcher) 
        {
			case 1: 
			{
				std::cout << "Enter a value:\n";
				std::string value;
				std::getline(std::cin, value);
				h.insertItem(value);
				break;
			}

			case 2: 
			{
				std::cout << "Enter a value:\n";
				std::string value;
				std::getline(std::cin, value);
				h.deleteItem(value);
				break;
			}
			case 3: 
			{
				h.display();
				break;
			}
		}
	}
}
