#include<iostream>
#include<stack>
using namespace std;
bool validBracket(string str){
    stack<char> st;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else{
            if(ch==')' && !st.empty() && st.top()=='('){
                st.pop();
            }
            else if(ch=='}' && !st.empty() && st.top()=='{'){
                st.pop();
            }
            else if(ch==']' && !st.empty() && st.top()=='['){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}
int main(){

    string s = "([{}])";
    if(validBracket(s)){
        cout<<"Brackets are Balanced"<<endl;
    }
    else{
        cout<<"Brackets are not Balanced"<<endl;
    }

    string str = "([{}]()";
    if(validBracket(str)){
        cout<<"Brackets are Balanced"<<endl;
    }
    else{
        cout<<"Brackets are not Balanced"<<endl;
    }

    return 0;
}