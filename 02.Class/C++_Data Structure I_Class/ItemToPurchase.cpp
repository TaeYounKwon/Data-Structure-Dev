#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase()
{
    itemName="none";
    itemPrice=0;
    itemQuantity=0;
}

void ItemToPurchase::SetName(string name1)
{
    itemName=name1;
    GetName();
}
void ItemToPurchase::SetPrice(int price1)
{
    itemPrice=price1;
    GetPrice();
}
void ItemToPurchase::SetQuantity(int quantity1)
{
    itemQuantity=quantity1;
    GetQuantity();
};
string ItemToPurchase::GetName()
{
    return itemName;
}

int ItemToPurchase::GetQuantity()
{
    return itemQuantity;
}
int ItemToPurchase::GetPrice()
{
    return itemPrice;
}

void ItemToPurchase::Print()
{
    cout<<itemName<<" "<<itemQuantity<<" @ $"<<itemPrice<<" = $"<<itemPrice*itemQuantity<<endl;
}
ItemToPurchase ItemToPurchase::operator+(ItemToPurchase itms)
{
    ItemToPurchase total;
    total.itemPrice=itemPrice*itemQuantity+itms.itemPrice*itms.itemQuantity;
    cout<<"\nTotal: $"<<total.itemPrice<<endl;

    return total;
}