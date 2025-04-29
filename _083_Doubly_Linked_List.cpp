#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node* prev, Node* next){
        this->data = 0;
        this->prev = prev;
        this->next = next;
    }
};

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<endl;
        head = head->next;
    }
}

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

void insertAtHead(int data, Node* &head, Node* &tail){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(int data, Node* &head, Node* &tail){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }    

    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPos(int data,int position ,Node* &head, Node* &tail){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    else if(position == 1){
        insertAtHead(data, head, tail);
        return;
    }
    else if(len(head)<position){
        insertAtTail(data, head, tail);
        return;
    }
    else{
        int i = 1;
        Node* previous = head;

        while(i<position-1){
            previous = previous->next;
            i++;            
        }
        Node* newNode = new Node(data);  
        Node* current = previous->next;   // here current pointer is necessary since we can lose the linked list while inserting in this case     

        // both working method
         
        // previous->next = newNode;
        // newNode->prev = previous;
        // current->prev = newNode;
        // newNode->next = current;
        
        newNode->next = current;
        current->prev = newNode;
        previous->next = newNode;
        newNode->prev = previous;
        return;
    }
}

void deleteNode(int pos, Node* &head, Node* &tail){
    // if null LL
    if(head == NULL){
        return;
    }

    // if single element in LL
    if(head->next == NULL){
        Node* temp = head;
        head = NULL;
        tail = NULL;

        delete temp;
        return;
    }

    // removing first element 
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;

        delete temp;
        return;
    }
    
    if(pos > len(head)) {
        cout << "Invalid position\n";
        return;
    }

    // removing last element of the linked list
    if(pos == len(head)){
        Node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;

        delete temp;
        return;
    }

    Node* previous = head;
    int i = 1;
    while(i < pos-1){
        previous = previous->next;
        i++;
    }
    Node* current = previous->next;

    previous->next = current->next;
    current->next->prev = previous;
    current->next = NULL;
    current->prev = NULL;

    delete current;
    return;
}

int main(){
    Node* five = new Node(5);
    Node* four = new Node(4);
    Node* three = new Node(3);
    Node* two = new Node(2);
    Node* one = new Node(1);

    Node* head = one;
    Node* tail = five;

    one->next = two;
    two->next = three;
    three->next = four;
    four -> next = five;

    two -> prev = one;
    three -> prev = two;
    four -> prev = three;
    five -> prev = four;

    print(head);
    cout<<endl;

    // insertAtHead(0,head,tail);
    // insertAtTail(6,head,tail);
    // insertAtPos(123,2, head, tail);

    deleteNode(3,head, tail);
    print(head);

    cout<<endl;
    return 0;
}