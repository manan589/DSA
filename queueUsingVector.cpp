#include<iostream>
#include<vector>
using namespace std;
class Queue{
    vector<int> v;
    int front;
    int rear;
    public:
    Queue(){
        front = rear = -1;
    }
    void enqueue(int data){
        v.push_back(data);
        rear++;
        if(rear == 0){ 
            front = 0;
        }
    }
    void dequeue(){
        if(front == rear){
            front = -1;
            rear = -1;
            v.clear();
        }
        else{
            front++;
        }
    }
    int getFront(){
        if(front == -1) return INT8_MIN;
        else return v[front];
    }
    bool isEmpty(){
        return front == -1;
    }
};
int main(){

    Queue Q;
    Q.enqueue(10);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(15);
    Q.enqueue(20);
    cout<<Q.getFront()<<endl;
    Q.dequeue();
    cout<<Q.getFront()<<endl;
    while(!Q.isEmpty()){
        cout<<Q.getFront()<<" ";
        Q.dequeue();
    }

    return 0;
}