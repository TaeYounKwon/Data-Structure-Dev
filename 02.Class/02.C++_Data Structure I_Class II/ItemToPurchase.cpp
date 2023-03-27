#include "ItemToPurchase.h"
#include <iostream>
using namespace std;

ItemToPurchase::ItemToPurchase()
{
    itemName="none";
    itemDescription="none";
    itemPrice=0;
    itemQuantity=0;
}
ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity)
{
    this->itemName = name;
    this->itemDescription = description;
    this->itemQuantity = quantity;
    this->itemPrice = price;
}
void ItemToPurchase::SetName(string name1)
{
    itemName=name1;
    GetName();
}
void ItemToPurchase::SetDescription(string description1)
{
    itemDescription=description1;
    GetDescription();
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
}
string ItemToPurchase::GetName()
{
    return itemName;
}
string ItemToPurchase::GetDescription()
{
    return itemDescription;
}
int ItemToPurchase::GetQuantity()
{
    return itemQuantity;
}
int ItemToPurchase::GetPrice()
{
    return itemPrice;
}
void ItemToPurchase::PrintItemCost()
{
    cout<<itemName<<" "<<itemQuantity<<" @ $"<<itemPrice<<" = $"<<itemPrice*itemQuantity<<endl;
}
void ItemToPurchase::PrintItemDescription()
{
    cout<<itemName<<": "<<itemDescription<<endl;
}