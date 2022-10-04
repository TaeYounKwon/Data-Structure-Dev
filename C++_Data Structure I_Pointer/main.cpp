#include <iostream>
using namespace std;

class ContactNode {
public:
    ContactNode(string name, string number, ContactNode* nextLoc = nullptr);
    void InsertAfter(ContactNode* nodeLoc);
    ContactNode* GetNext();
    string GetPhoneNumber();
    string GetName();
    void PrintContactNode();

private:
    string contactName;
    string contactPhoneNum;
    ContactNode* nextNodePtr;
};
ContactNode::ContactNode(string name, string number, ContactNode* nextLoc) {
    this->contactName = name;
    this->contactPhoneNum = number;
}
void ContactNode::InsertAfter(ContactNode* nodeLoc) {
    ContactNode* tmpNext = nullptr;

    tmpNext = this->nextNodePtr;    // Remember next
    this->nextNodePtr = nodeLoc;    // this -- node -- ?
    nodeLoc->nextNodePtr = tmpNext; // this -- node -- next
}
string ContactNode::GetName(){
    return this->contactName;
}
string ContactNode::GetPhoneNumber() {
    return this-> contactPhoneNum;
}



void ContactNode::PrintContactNode() {
    cout << "Name: "<<this->contactName << endl;
    cout << "Phone number: "<<this->contactPhoneNum << endl;
    cout<<"\n";
}

ContactNode* ContactNode::GetNext() {
    return this->nextNodePtr;
}

int main() {
    string name,name2,name3;
    string number,number2,number3;
    ContactNode* headObj  = nullptr; // Create IntNode objects
    cout<<"Person 1"<<endl;
    cout<<"Enter name:"<<endl;
    getline(cin,name);
    cout<<"Enter phone number:"<<endl;
    getline(cin,number);
    headObj = new ContactNode(name,number);
    cout<<"You entered: "<<name<<", "<<number<<endl;
    cout<<"\n";

    cout<<"Person 2"<<endl;
    cout<<"Enter name:"<<endl;
    getline(cin,name2);
    cout<<"Enter phone number:"<<endl;
    getline(cin,number2);
    ContactNode* nodeObj1 = nullptr;
    nodeObj1 = new ContactNode(name2,number2);
    cout<<"You entered: "<<name2<<", "<<number2<<endl;
    cout<<"\n";
    headObj->InsertAfter(nodeObj1);

    cout<<"Person 3"<<endl;
    cout<<"Enter name:"<<endl;
    getline(cin,name3);
    cout<<"Enter phone number:"<<endl;
    getline(cin,number3);
    ContactNode* nodeObj2 = nullptr;
    nodeObj2 = new ContactNode(name3,number3);
    cout<<"You entered: "<<name3<<", "<<number3<<endl;
    cout<<"\n";
    nodeObj1->InsertAfter(nodeObj2);

    ContactNode* currObj  = nullptr;
    currObj = headObj;
    cout<<"CONTACT LIST"<<endl;
    while (currObj != nullptr) {
        currObj->PrintContactNode();
        currObj = currObj->GetNext();
    }

    return 0;
}