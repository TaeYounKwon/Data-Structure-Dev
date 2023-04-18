#include <iostream>
using namespace std;

#include "ItemToPurchase.h"


int main()
{ string name1, name2;
    int price1, price2;
    int quant1, quant2;

    ItemToPurchase items1;
    ItemToPurchase items2;
    //Item1
    cout<<"Item 1"<<endl;
    cout<<"Enter the item name:"<<endl;
    getline(cin,name1);
    items1.SetName(name1);
    cout<<"Enter the item price:"<<endl;
    cin>>price1;
    items1.SetPrice(price1);
    cout<<"Enter the item quantity:"<<endl;
    cin>>quant1;
    items1.SetQuantity(quant1);
    cin.ignore();
    //Item2
    cout<<"\nItem 2"<<endl;
    cout<<"Enter the item name:"<<endl;
    getline(cin,name2);
    items2.SetName(name2);
    cout<<"Enter the item price:"<<endl;
    cin>>price2;
    items2.SetPrice(price2);
    cout<<"Enter the item quantity:"<<endl;
    cin>>quant2;
    items2.SetQuantity(quant2);
    cout<<"\nTOTAL COST"<<endl;
    items1.Print();
    items2.Print();
    items1.operator+(items2);
    return 0;
}