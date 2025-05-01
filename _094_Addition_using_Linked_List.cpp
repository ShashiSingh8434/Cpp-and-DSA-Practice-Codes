#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(){}   

    Node(int data):data(data), next(NULL){}

    Node(int data, Node* next):data(data), next(next){}
};

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}
Node* addition(Node* num1, Node* num2){
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    int carry = 0;
    int digit = 0;
    int sum = 0;

    num1 = reverse(num1);
    num2 = reverse(num2);

    // print(num1);
    // cout<<endl;

    // print(num2);
    // cout<<endl;

    
    Node* num1Tail = num1;
    Node* num2Tail = num2;

    while(num1Tail != NULL && num2Tail != NULL){
        sum = num1Tail->data + num2Tail->data + carry;
        digit = sum%10;
        carry = sum/10;

        Node* ans = new Node(digit);

        if(ansHead == NULL){
            ansHead = ans;
            ansTail = ans;
        }else{
            ansTail->next = ans;
            ansTail = ans;
        }

        num1Tail = num1Tail->next;
        num2Tail = num2Tail->next;

        
        // print(ansHead);
        // cout<<endl;
        
    } 

    while(num1Tail != NULL){
        sum = num1Tail->data+ carry;
        digit = sum%10;
        carry = sum/10;

        Node* ans = new Node(digit);

        if(ansHead == NULL){
            ansHead = ans;
            ansTail = ans;
        }else{
            ansTail->next = ans;
            ansTail = ans;
        }

        num1Tail = num1Tail->next;
    }

    while(num2Tail != NULL){
        sum = num2Tail->data+ carry;
        digit = sum%10;
        carry = sum/10;

        Node* ans = new Node(digit);

        if(ansHead == NULL){
            ansHead = ans;
            ansTail = ans;
        }else{
            ansTail->next = ans;
            ansTail = ans;
        }

        num2Tail = num2Tail->next;
    }

   
    while(carry != 0){
        Node* ans = new Node(carry);
        if(ansHead == NULL){
            ansHead = ans;
            ansTail = ans;
        }else{
            ansTail->next = ans;
            ansTail = ansTail->next;
        }
        carry = 0;
    }

    return reverse(ansHead);
    
}

int main(){
    Node* a = new Node(8);
    Node* b = new Node(1,a);
    Node* c = new Node(2,b);

    Node* d = new Node(2);
    Node* e = new Node(3,d);

    print(c);
    cout<<endl;
    print(e);
    cout<<endl;

    print(addition(c,e));
    return 0;
}