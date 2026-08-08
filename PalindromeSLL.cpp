#include<iostream>
using namespace std;
class LinkedList;
class node{
    friend class LinkedList;
    int data;
    node* next;
    node* prev;
    public:
    node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
    int& getData(){
        return this->data;
    }
    node* & getNext(){
        return next;
    }
};
class LinkedList{
    friend class node;
    node* head;
    public:
    LinkedList(){
        head = NULL;
    }
    node* &getHead(){
        return head;
    }
    void insert(int d){
        if(head == NULL){
            head = new node(d);
        }
        else{
            node* temp = head;
            node* nn = new node(d);
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = nn;
        }
    }
    void display(){
        node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
bool isPalindrome(node* head){
    node* slow = head;
    node* fast = head;
    while(fast && fast->getNext()){
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }
    node* curr = slow->getNext();
    node* prev = slow;
    slow->getNext() = NULL;
    while(curr){
        node* nextptr = curr->getNext();
        curr->getNext() = prev;
        prev = curr;
        curr = nextptr;
    }
    
    node* head1 = head;
    node* head2 = prev;
    while(head2){
        if(head1->getData() != head2->getData()){
            return false;
        }
        head1 = head1->getNext();
        head2 = head2->getNext();
    }
    return true;
}
int main(){

    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    // l1.insert(4);
    l1.insert(2);
    l1.insert(1);
    l1.display();
    if(isPalindrome(l1.getHead())){
        cout<<"Linked List is Palindrome.";
    }
    else{
        cout<<"Linked List is not Palindrome.";
    }

    return 0;
}