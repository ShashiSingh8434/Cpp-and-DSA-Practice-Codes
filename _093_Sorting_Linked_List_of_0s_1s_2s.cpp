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
        cout<<head->data<<" ";
        head = head->next;
    }
}

void sortingLinkedList(Node* &head){
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    Node* curr = head;

    if(head == NULL){
        return;
    }
    int i = 1;
    while(curr != NULL){
        if(curr->data == 0){
            zeroHead->next = curr;
            zeroHead = zeroHead->next;
        }
        else if(curr->data == 1){
            oneHead->next = curr;
            oneHead = oneHead->next;
            
        }
        else if(curr->data == 2){
            twoHead->next = curr;
            twoHead = twoHead->next;
        }
        curr = curr->next;
        i++;
    }
    twoHead->next = NULL;

    zeroHead -> next = one->next;
    one->next = NULL;
    oneHead -> next = two->next;
    two->next = NULL;

    // -1 -> ....0.... -> -1 -> ....1....  -> -1 -> ....2....  

    head = zero->next;
    zero->next = NULL;

    delete zero;
    delete one;
    delete two;
}

int main(){
    Node* six = new Node(0);
    Node* five = new Node(1,six);
    Node* four = new Node(0,five);
    Node* three = new Node(2,four);
    Node* two = new Node(2,three);
    Node* one = new Node(1,two);

    Node* head = one;

    print(head);
    sortingLinkedList(head);
    cout<<endl;

    print(head);
    
    cout<<endl<<endl;

    return 0;
}