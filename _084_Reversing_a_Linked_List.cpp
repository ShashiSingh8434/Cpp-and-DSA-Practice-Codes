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

Node* reverse(Node* &prev, Node* &curr){
    if(curr == NULL){
        return prev;
    }

    Node* forward = curr->next;
    curr->next = prev;

    reverse(curr, forward);
}

Node* reverseUsingLoop(Node* &head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

int main(){
    Node* six = new Node(6);
    Node* five = new Node(5,six);
    Node* four = new Node(4,five);
    Node* three = new Node(3,four);
    Node* two = new Node(2,three);
    Node* one = new Node(1,two);
    
    Node* head = one;
    Node* tail = five;

    cout<<endl;

    Node* prev = NULL;
    Node* curr = head;

    // Node* rev = reverse(prev, curr);
    // print(rev);
    
    Node* revLoop = reverseUsingLoop(head);
    print(revLoop);

    return 0;
}