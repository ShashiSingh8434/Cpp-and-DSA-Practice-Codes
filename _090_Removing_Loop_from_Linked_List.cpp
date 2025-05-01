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

bool detectLoop(Node* head){    // Floyd Cycle Detection Approach
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }

    return false;
}

void removeLoop(Node* head){    
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){      // step one 
            slow = head;       // step two 
            break;
            // found that this is a cycle since fast and slow met
            // then reassigned the pointer to slow to head then reiterate from beginning then the next met point is the starting point 
        }
    }

    Node* temp = fast;
    while(slow!=fast){        // step three 
        temp = fast;
        slow = slow->next;
        fast = fast->next;
    }

    temp->next = NULL;
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

    six->next = three;


    // print(head);
    cout<<detectLoop(head)<<endl;
    removeLoop(head);
    cout<<detectLoop(head)<<endl;
    
    cout<<endl<<endl;

    return 0;
}