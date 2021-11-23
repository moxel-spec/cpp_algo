#include <iostream>
#include <string>
using namespace std;
class Tiles 
{
    public:
    string brand;
    int size_1;
    int size_2;
    int price;
    auto getData();
    Tiles (string brand,int size_1,int size_2,int price)
    {
        this->brand = brand;
        this->size_1 = size_1;
        this->size_2 = size_2;
        this->price = price;
    }
};

auto Tiles::getData ()
{
    cout <<"Brand if Tile: " << brand << endl;
    cout <<"Size of Tile: " <<  size_1 << "x" << size_2 <<endl;
    cout <<"Price of Tile: " <<  price << "$"<< endl;
}
int main ()
{
    string tile1_brand = "Microsoft brand";
    int tile1_size1 = 15;
    int tile1_size2 = 10;
    int tile1_price = 32;
    Tiles tile1(tile1_brand,tile1_size1,tile1_size2,tile1_price);
    
    tile1.getData();
    
}