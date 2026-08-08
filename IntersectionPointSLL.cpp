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
int getLength(node* head){
    node* temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->getNext();
    }
    return length;
}
node* moveHeadByk(node* head,int k){
    node* ptr = head;
    while(k--){
        ptr = ptr->getNext();
    }
    return ptr;
}
node* getInterSection(node* head1,node* head2){
   node* ptr1;
   node* ptr2;
   int l1 = getLength(head1);
   int l2 = getLength(head2);

   if(l1 > l2){
        int k = l1-l2;
        ptr1 = moveHeadByk(head1,k);
        ptr2 = head2;
   }
   else{
        int k = l2-l1;
        ptr1 = head1;
        ptr2 = moveHeadByk(head2,k);
    }
    while(ptr1){
        if(ptr1 == ptr2){
            return ptr1;
        }
        ptr1 = ptr1->getNext();
        ptr2 = ptr2->getNext();
    }
    return NULL;
}
int main(){

    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.display();

    LinkedList l2;
    l2.insert(5);
    l2.insert(7);
    l2.getHead()->getNext()->getNext() = l1.getHead()->getNext()->getNext();
    l2.display();

    node* intresection = getInterSection(l1.getHead(),l2.getHead());
    if(intresection){
        cout<<intresection->getData()<<endl;
    }
    else{
        cout<<-1<<endl;
    }

    return 0;
}