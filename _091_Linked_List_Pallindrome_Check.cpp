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

bool checkPallindrome(Node* head){
    int i = 1;
    int length = len(head);

    int middle = length/2 ;
    Node* middleNode = head;

    while(i <= middle){
        middleNode = middleNode->next;
        i++;
    }



    Node* prev = NULL;
    Node* curr = middleNode;
    Node* next = middleNode;

    while(next != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    print(head);
    cout<<endl;
    print(prev);
    cout<<endl;

    //now new LL is like:=>             (head -> ....... -> middle <- ....... <- prev)

    while(prev->next != NULL){
        if(head->data != prev->data){
            return false;
        }
        head = head->next;
        prev = prev->next;
    }
    return true;
}

int main(){
    Node* six = new Node(1);
    Node* five = new Node(2,six);
    Node* four = new Node(3,five);
    // Node* three  = new Node(3, four);
    Node* two = new Node(2,four);
    Node* one = new Node(1,two);

    Node* head = one;


    cout<<checkPallindrome(head);


    // print(head);
    
    cout<<endl<<endl;

    return 0;
}