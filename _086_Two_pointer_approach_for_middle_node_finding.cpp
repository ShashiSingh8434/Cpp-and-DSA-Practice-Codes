#include <iostream>
using namespace std;

// Two pointer Approach for finding middle Node 
// Time complexity O(n/2)

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

    Node* slow = head;
    Node* fast = head;

    if(head == NULL){
        cout << "List is empty.\n";
        return;
    }

    while(fast != NULL && fast->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;
    }

    cout<<"The middle node is: "<<slow->data<<endl;

}

int main(){
    // Node* six = new Node(6);
    Node* five = new Node(5);
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