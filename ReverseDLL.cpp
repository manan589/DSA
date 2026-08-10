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
    void reverseDLL(){
        node* currptr = head;
        while(currptr != NULL){
            node* nextptr = currptr->next;
            currptr->next = currptr->prev;
            currptr->prev = nextptr;
            head = currptr;
            currptr = nextptr;
        }
    }
};
int main(){

    DoublyLL dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(40);
    dll.insert(33);
    dll.insert(50);
    cout<<"Before Reverse:\n";
    dll.display();
    dll.reverseDLL();
    cout<<"After Reverse:\n";
    dll.display();

    return 0;
}