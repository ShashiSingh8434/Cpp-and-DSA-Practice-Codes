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

void deleteNode(int position ,Node* &head){
    if(position == 1){
        Node* temp = head;

        head = head->next;
        delete temp;
    }
    else if(len(head)==position){
        int i = 1;
        Node* prev = head;
        while(i<position-1){
            prev = prev->next;
            i++;            
        }
        Node* temp = prev->next;
        prev->next = NULL;
        delete temp;
        
    }
    else if(position>0 && position<=len(head)){
        int i = 1;
        Node* prev = head;
        while(i<position-1){
            prev = prev->next;
            i++;            
        }
        Node* temp = prev->next;
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        cout<<"Invalid Index"<<endl;
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

    deleteNode(5,head);
    print(head);
    cout<<endl<<endl;

    return 0;
}