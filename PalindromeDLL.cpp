#include<iostream>
using namespace std;
class DoublyLL;
class node{
    friend class DoublyLL;
    int data;
    node* next;
    node* prev;
    public:
    node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
    node* & getNext(){
        return this->next;
    }
    node* & getprev(){
        return this->prev;
    }
    int& getdata(){
        return this->data;
    }
};
class DoublyLL{
    friend class node;
    node* head;
    public:
    DoublyLL(){
        head = NULL;
    }
    void insert(int d){
        if(head == NULL){
            head = new node(d);
        }
        else{
            node* nn = new node(d);
            node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = nn;
            nn->prev = temp;
        }
    }
    void display(){
        node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    node* & getHead(){
        return this->head;
    }
};
bool palindrome(node* head){
    // tail is the last node of Doubly Linked List
    node* tail = head;
    while(tail->getNext() != NULL){
        tail = tail->getNext();
    }
    // Now check if head->data is equal to tail->data or not

    while(tail != head && tail != head->getprev()){
        if(tail->getdata() != head->getdata()){
            return false;
        }
        head = head->getNext();
        tail = tail->getprev();
    }
    return true;
}
int main(){

    DoublyLL dll;
    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.insert(3);
    dll.insert(2);
    dll.insert(1);

    dll.display();

    if(palindrome(dll.getHead())){
        cout<<"Yes, Doubly Linked List is Palindrome"<<endl;
    }
    else{
        cout<<"No, Doubly Linked List is not palindrome"<<endl;
    }

    return 0;
}