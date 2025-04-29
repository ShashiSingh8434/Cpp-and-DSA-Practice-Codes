#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node():data(0),next(NULL){}

    Node(int data):data(data), next(NULL){}

    Node(int data, Node* next):data(data), next(next){}
};

int len(Node* head){
    int count = 0;
    if(head != NULL){
        count++;
        while(head->next != NULL){
            head = head->next;
            count++;
        }
    }
    
    return count;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<endl;
        head = head->next;
    }
}

void insertAtHead(int data, Node* &head, Node* &tail){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data,head);
        head = temp;
    }
}

void insertAtTail(int data, Node* &head, Node* tail){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        tail->next = temp;
    }
}

void insertAtPos(int data,int position ,Node* &head, Node* tail){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else if(position == 1){
        insertAtHead(data, head, tail);
    }
    else if(len(head)<position){
        insertAtTail(data, head, tail);
    }
    else{
        int i = 1;
        Node* iteration = head;
        while(i<position-1){
            iteration = iteration->next;
            i++;            
        }
        Node* temp = new Node(data,iteration->next);
        iteration->next = temp;
    }
}

int main(){
    // intialised a linked list of [1->2->3->4->5->6]
    Node* six = new Node(6);
    Node* five = new Node(5,six);
    Node* four = new Node(4,five);
    Node* three = new Node(3,four);
    Node* two = new Node(2,three);
    Node* one = new Node(1,two);

    Node* head = one;
    Node* tail = six;

    // insertAtHead(0, head, tail);
    // insertAtTail(7, head, tail);
    insertAtPos(123,3,head,tail);

    print(head);
    cout<<endl<<endl;

    return 0;
}