#include<iostream>
#include<stack>
using namespace std;
int prec(char op){
    if(op=='^') return 3;
    else if(op=='/' || op=='*') return 2;
    else if(op=='-' || op=='+') return 1;
    else return -1;
}
string convert(string &str){
    stack<char> st;
    string res =  "";
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(isalnum(ch)){
            res += ch;
        }
        else if(ch=='('){
            st.push(ch);
        }
        else if(ch==')'){
            while(!st.empty() && st.top()!='('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prec(ch) <= prec(st.top())){
                res += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}
int main(){

    string infix = "A+B-c*D";
    string postfix = convert(infix);
    cout<<postfix<<endl;

    return 0;
}