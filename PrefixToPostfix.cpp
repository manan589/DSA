#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
string eval(string &prep){
    stack<string> st;
    reverse(prep.begin(),prep.end());
    for(int i=0;i<prep.size();i++){
        if(isdigit(prep[i])){
            st.push(to_string(prep[i]-'0'));
        }
        else{
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();
            string newexp = v1+v2+prep[i];
            st.push(newexp);
        }
    }
    return st.top();
}
int main(){

    string str = "*+532";
    cout<<eval(str)<<endl;

    return 0;
}