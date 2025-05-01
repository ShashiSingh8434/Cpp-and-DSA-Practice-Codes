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

void removeDuplicates(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = head;

    if(head == NULL){
        return ;
    }

    while(forward != NULL){
        forward = curr->next;
        if(curr->data == forward->data){
            Node* temp = forward; 
            curr->next = forward->next;

            temp->next = NULL;
            delete temp;
        }
        else{
            curr = curr->next;
            forward = forward->next;
        }
    }

    print(head);
}

int main(){
    Node* six = new Node(6);
    Node* five = new Node(5,six);
    Node* four = new Node(5,five);
    Node* three = new Node(3,four);
    Node* two = new Node(1,three);
    Node* one = new Node(1,two);

    Node* head = one;

    removeDuplicates(head);
    cout<<endl<<endl;

    return 0;
}