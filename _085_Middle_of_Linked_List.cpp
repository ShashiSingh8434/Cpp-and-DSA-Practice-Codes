#include <iostream>
using namespace std;

// Linear Approach for finding middle Node 
// Time complexity O(n)

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
void middleNode(Node* &head){ 
    int length = len(head);

    int count = 1;
    int target = 1;
    Node* temp = head;

    if(length%2 == 0){
        target = length/2;
    }
    else{
        target = length/2 + 1;
    }

    while(count<target){
        temp = temp->next;
        count++;
    }
    cout<<temp->data<<endl;
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

    middleNode(head);

    cout<<endl<<endl;

    return 0;
}