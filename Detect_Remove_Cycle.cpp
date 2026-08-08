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
bool detectCycle(node* head){
    node* slow = head;
    node* fast = head;

    while(fast && fast->getNext()){
        slow = slow->getNext();
        fast = fast->getNext()->getNext();

        if(slow==fast){
            return true;
        }
    }
    return false;
}
void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;

    do{
        fast = fast->getNext()->getNext();
        slow = slow->getNext();
    }while(fast != slow);

    fast = head;
    while(slow->getNext() != fast->getNext()){
        slow = slow->getNext();
        fast = fast->getNext();
    }
    slow->getNext() = NULL;
}
int main(){

    LinkedList l1;
    l1.insert(1);
    l1.insert(3);
    l1.insert(2);
    l1.insert(4);
    l1.insert(5);
    l1.getHead()->getNext()->getNext()->getNext()->getNext()->getNext() = l1.getHead()->getNext()->getNext()->getNext();
    cout<<detectCycle(l1.getHead())<<endl;
    removeCycle(l1.getHead());
    l1.display();
    

    return 0;
}