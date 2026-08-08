#include<iostream>
using namespace std;
class LinkList;
class node{
    friend class LinkList;
    int data;
    node *next;
    public:
    node(int d){
        data = d;
        next = NULL;
    }
    int & getData(){
        return data;
    }
    node* & getNext(){
        return next;
    }
};
class LinkList{
    friend class node;
    node *head;
    public:
    LinkList(){
        head = NULL;
    }
    void insert(int d){
        if(head == NULL){
            head = new node(d);
        }
        else{
            node *nn = new node(d);
            node *temp = head;
            while(temp -> next != NULL){
                temp = temp->next;
            }
            temp->next = nn;
        }
    }
    void display(){
        node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
        }
        node* & getHead(){
            return head;
    }

    node* reverseLL(){
        node *prevptr = NULL;
        node *currptr = head;
        while(currptr != NULL){
            node *nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        node *new_head = prevptr;
        return new_head;
    }
};
node* reverseLL(node* &head){                      // using recursive methode
    if(head == NULL || head->getNext() == NULL){
        return;
    }
    node* new_head = reverseLL(head->getNext());
    head->getNext()->getNext() = head;
    head->getNext() = NULL;
    return new_head;
}
int main(){

    LinkList L;
    L.insert(10);
    L.insert(20);
    L.insert(30);
    L.insert(40);
    L.insert(50);
    L.display();
    L.getHead() = L.reverseLL();
    L.display();

    return 0;
}