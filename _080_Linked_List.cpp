#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node():data(0){}

    Node(int data):data(data), next(NULL){}

    Node(int data, Node* next):data(data), next(next){}
};

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<endl;
        head = head->next;
    }
}

int main(){
    Node* one = new Node(10);
    Node* two = new Node(20);
    Node* three = new Node(30);
    
    
    one -> next = two;
    two -> next = three;

    print(one);
    cout<<endl<<endl;

    cout<<one->data<<" ";
    cout<<two->data<<" ";
    cout<<three->data<<" ";
    cout<<endl<<endl;
    
    cout<<one->next<<" ";
    cout<<two->next<<" ";
    cout<<three->next<<" ";
    cout<<endl<<endl;

    cout<<(one->next)->data<<" ";
    cout<<endl<<endl;

    Node* four = new Node(40,one);
    cout<<four->data<<" "<< four->next->data;

    return 0;
}