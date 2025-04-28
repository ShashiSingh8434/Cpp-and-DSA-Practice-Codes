#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node():data(0){}

    Node(int data):data(data){}

    Node(int data, Node* next):data(data), next(next){}
};

int main(){
    Node* one = new Node(10);
    Node* two = new Node(20);
    Node* three = new Node(30);

    Node* four = new Node(40,one);
    
    one -> next = two;
    two -> next = three;

    cout<<one->data<<" ";
    cout<<two->data<<" ";
    cout<<three->data<<" ";
    
    cout<<one->next<<" ";
    cout<<two->next<<" ";
    cout<<three->next<<" ";

    
    cout<<(one->next)->data<<" ";

    cout<<endl<<endl;

    cout<<four->data<<" "<< four->next->data;

    return 0;
}