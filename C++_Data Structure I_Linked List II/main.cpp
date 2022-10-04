#include <iostream>
#include <cstddef>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};

void print_list(Node *n){
    while(n!=nullptr){
        cout<<n->data<<"";
        n=n->next;
    }
}

void push(struct Node **head_ref, int new_data){
    struct Node * new_node =(struct Node *)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}

int main() {
  Node* head = nullptr;
  Node* second = nullptr;
  Node* third = nullptr;

  head = new Node();
  second = new Node();
  third = new Node();

  head-> data=1;
  head->next = second;
  second->data=2;
  second->next = third;
  third->data = 3;
  third->next = nullptr;
  push(&head, 0);

  print_list(head);

}
