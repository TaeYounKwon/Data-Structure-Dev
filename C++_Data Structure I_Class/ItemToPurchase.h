#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

/* Type your code here */
class ItemToPurchase
{
public:
    ItemToPurchase();
    void SetName(string name1);
    void SetPrice(int price1);
    void SetQuantity(int quantity1);
    string GetName();
    int GetPrice();
    int GetQuantity();
    ItemToPurchase operator+(ItemToPurchase itms);
    void Print();
    void TotalPrint();
private:
    string itemName;
    int itemPrice;
    int itemQuantity;
};
#endif