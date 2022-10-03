#include <iostream>
#include <vector>
using namespace std;
#ifndef UNTITLED2_SHOPPINGCART_H
#define UNTITLED2_SHOPPINGCART_H
#include "ItemToPurchase.h"

class ShoppingCart
{
public:
    ShoppingCart();
    ShoppingCart(string customerName, string currentDate);
    void SetCustomerName(string cname);
    void SetDate(string date);
    string GetCustomerName();
    string GetDate();
    void AddItem(ItemToPurchase item);
    void removeItem(string itemName);
    void modifyItem(string itemName, int nitemQuantity);
    int GetNumItemsInCart();
    int GetCostOfCart();
    void PrintTotal();
    void PrintDescriptions();

private:
    string customerName;
    string currentDate;
    vector <ItemToPurchase> cartItems;

};


#endif //UNTITLED2_SHOPPINGCART_H