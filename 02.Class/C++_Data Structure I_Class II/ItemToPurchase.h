# include <iostream>
using namespace std;

#ifndef UNTITLED2_ITEMTOPURCHASE_H
#define UNTITLED2_ITEMTOPURCHASE_H


class ItemToPurchase
{
public:
    ItemToPurchase();
    ItemToPurchase(string name, string description, int price, int quantity);
    void SetName(string name1);
    void SetDescription(string description1);
    void SetPrice(int price1);
    void SetQuantity(int quantity1);
    string GetName();
    string GetDescription();
    int GetPrice();
    int GetQuantity();
    void PrintItemCost();
    void PrintItemDescription();
private:
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;
};


#endif //UNTITLED2_ITEMTOPURCHASE_H