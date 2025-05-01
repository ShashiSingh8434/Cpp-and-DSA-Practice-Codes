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

Node* reverseKgroup(Node* head, int k){
    if(head == NULL){
        return head;
    }

    if(len(head)<k){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = head->next;
    int count = 0;

    while(count<k){
        forward = curr->next; 
        curr->next = prev;
        prev = curr;
        curr = forward;

        count++;
    }

    if(forward != NULL){
        head->next = reverseKgroup(forward, k);
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

    print(head);
    cout<<endl;

    Node* rev = reverseKgroup(head , 4);
    print(rev);
    cout<<endl<<endl;

    return 0;
}