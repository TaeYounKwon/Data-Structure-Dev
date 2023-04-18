#include "ShoppingCart.h"
#include <iostream>
using namespace std;

ShoppingCart::ShoppingCart()
{
    customerName="none";
    currentDate="January 1, 2016";
}
ShoppingCart::ShoppingCart(string customerName, string currentDate)
{
    this->customerName = customerName;
    this->currentDate = currentDate;
}
void ShoppingCart::SetCustomerName(string cname)
{
    customerName=cname;
    GetCustomerName();
};
string ShoppingCart::GetCustomerName()
{
    return customerName;
}
void ShoppingCart::SetDate(string date)
{
    currentDate = date;
    GetDate();

}
string ShoppingCart::GetDate()
{
    return currentDate;
}

void ShoppingCart::PrintTotal()
{   ItemToPurchase itp;
    cout<<customerName<<"\'s Shopping Cart - "<<currentDate<<endl;
    cout<<"Number of Items: "<<GetNumItemsInCart()<<"\n"<<endl;
    if(cartItems.size()==0)
    {cout<<"SHOPPING CART IS EMPTY"<<endl;}
    else
    {
        for (int i = 0; i < cartItems.size(); ++i)
        {
            cartItems.at(i).PrintItemCost();
        }
    }
    cout << "\nTotal: $" << GetCostOfCart() << endl;

}


void ShoppingCart::PrintDescriptions()
{
    ItemToPurchase itp;
    cout<<customerName<<"\'s Shopping Cart - "<<currentDate<<endl;
    cout<<"\nItem Descriptions"<<endl;
    for(int i=0;i<cartItems.size();++i)
    {
        cartItems.at(i).PrintItemDescription();
    }
}

void ShoppingCart::AddItem(ItemToPurchase item)
{
    this->cartItems.push_back(item);
}

void ShoppingCart::removeItem(string itemName) {

    if (cartItems.size() == 0)
    {
        cout << "ItemList is empty" << endl;
        goto endPoint;
    }
    for (int i = 0; i < cartItems.size(); i++)
    {
        if (this->cartItems.at(i).GetName() == itemName)
        {
            this->cartItems.erase(cartItems.begin() + i);
            goto endPoint;
        }

    }
    cout << "Item not found in cart. Nothing removed." << endl;
    endPoint:
    cout << "";
}



int ShoppingCart::GetCostOfCart() {
    ItemToPurchase itp;
    int totalcost = 0;
    for (int i = 0; i < cartItems.size(); ++i)
    {
        totalcost = totalcost +cartItems.at(i).GetPrice()*cartItems.at(i).GetQuantity();
    }
    return totalcost;
}
int ShoppingCart::GetNumItemsInCart()
{ int numItems=0;
    for( int i=0;i< cartItems.size();++i)
    {
        numItems=numItems+cartItems.at(i).GetQuantity();
    }
    return numItems;
}
void ShoppingCart::modifyItem(string itemName, int nitemQuantity)
{
    if (cartItems.size() == 0)
    {
        cout << "ItemList is empty" << endl;

        goto endPoint;
    }

    for (int i = 0; i < cartItems.size(); ++i)
    {
        if (this->cartItems.at(i).GetName() == itemName)
        {
            cartItems.at(i).SetQuantity(nitemQuantity);
            goto endPoint;
        }
    }
    cout<<"Item not found in cart. Nothing modified."<<endl;
    endPoint:
    cout<<"";
}
