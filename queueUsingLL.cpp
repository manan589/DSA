#include<iostream>
using namespace std;
class Queue;
class node{
    friend class Queue;
    int data;
    node* next;
    public:
    node(int data){
        this->data = data;
        next = NULL;
    }
};
class Queue{
    friend class node;
    node* head;
    node* tail;
    int size;
    public:
    Queue(){
        head = tail = NULL;
        size = 0;
    }
    void enqueue(int d){
        node* nn = new node(d);
        if(head == NULL){
            head = tail = nn;
        }
        else{
            tail->next = nn;
            tail = nn;
        }
        size++;
    }
    void dequeue(){
        if(head == NULL){
            return;
        }
        else{
            node* oldHead = head;
            node* newHead = head->next;
            head = newHead;
            if(head == NULL) tail = NULL;
            oldHead->next = NULL;
            delete oldHead;
            size--;
        }
    }
    int front(){
        if(head == NULL) return INT8_MIN;
        else return head->data;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return head==NULL;
    }
};
int main(){

    Queue Q;
    Q.enqueue(10);
    Q.enqueue(30);
    Q.enqueue(20);
    Q.enqueue(15);
    Q.dequeue();
    Q.enqueue(60);
    Q.enqueue(50);

    while(!Q.isEmpty()){
        cout<<Q.front()<<" ";
        Q.dequeue();
    }
    cout<<endl;

    return 0;
}