#include <iostream>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
using namespace std;



void PrintMenu()
{   ItemToPurchase item;
    ShoppingCart spc;
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity, nitemQuantity;
    char options;
    string cName;
    string currentDate;
    cout<<"Enter customer's name:"<<endl;
    getline(cin, cName);
    cout<<"Enter today's date:"<<endl;
    getline(cin,currentDate);
    cout<<"\nCustomer name: "<<cName<<endl;
    cout<<"Today's date: "<<currentDate<<endl;
    spc.SetCustomerName(cName);
    spc.SetDate(currentDate);

    while(true)
    {
        cout << "\nMENU" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit\n" << endl;
        defaultPoint:
        cout << "Choose an option:"<<endl;
        cin >> options;
        switch (options)
        {
            case 'a':
                cin.ignore();
                cout<<"ADD ITEM TO CART"<<endl;
                cout<<"Enter the item name:"<<endl;
                getline(cin,itemName);
                item.SetName(itemName);
                cout<<"Enter the item description:"<<endl;
                getline(cin,itemDescription);
                item.SetDescription(itemDescription);
                cout<<"Enter the item price:"<<endl;
                cin >> itemPrice;
                item.SetPrice(itemPrice);
                cout<<"Enter the item quantity:"<<endl;
                cin>> itemQuantity;
                item.SetQuantity(itemQuantity);
                spc.AddItem(item);
                break;
            case 'd':
                cout<<"REMOVE ITEM FROM CART"<<endl;
                cout<<"Enter name of item to remove:"<<endl;
                cin.ignore();
                getline(cin,itemName);
                spc.removeItem(itemName);
                break;
            case 'c':
                cin.ignore();
                cout<<"CHANGE ITEM QUANTITY"<<endl;
                cout<<"Enter the item name:"<<endl;
                getline(cin, itemName);
                cout<<"Enter the new quantity:"<<endl;
                cin>>nitemQuantity;
                spc.modifyItem(itemName,nitemQuantity);

                break;
            case 'i':
                cout<<"OUTPUT ITEMS' DESCRIPTIONS"<<endl;
                spc.PrintDescriptions();
                break;
            case 'o':
                cout<<"OUTPUT SHOPPING CART"<<endl;
                spc.PrintTotal();
                break;
            case 'q':
                exit(1);
            default:
                goto defaultPoint;




        }
    }



}
int main() {

    PrintMenu();

    return 0;
}