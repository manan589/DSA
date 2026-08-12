#include<iostream>
#include<stack>
using namespace std;
class Queue{
    stack<int> st;
    public:
    Queue(){}
    void enqueue(int data){
        st.push(data);
    }
    void dequeue(){
        stack<int> temp;
        while(st.size() > 1){
            int x = st.top();
            st.pop();
            temp.push(x);
        }
        st.pop();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
    int getFront(){
        stack<int> temp;
        while(st.size() > 1){
            temp.push(st.top());
            st.pop();
        }
        int result = st.top();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return result;
    }
    bool isEmpty(){
        return st.empty();
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