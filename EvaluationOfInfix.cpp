#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
int calc(int v1,int v2,char op){
    if(op=='^') return pow(v1,v2);
    if(op=='*') return v1*v2;
    if(op=='/') return v1/v2;
    if(op=='+') return v1+v2;
    if(op=='-') return v1-v2;
    return -1;
}
int prec(char op){
    if(op=='^') return 3;
    else if(op=='/' || op=='*') return 2;
    else if(op=='+' || op=='-') return 1;
    else return -1;
}
int eval(string &str){
    stack<int> nums;
    stack<char> ops;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(isdigit(ch)){
            nums.push(str[i]-'0');
        }
        else if(ch == '('){
            ops.push('(');
        }
        else if(ch == ')'){
            while(!ops.empty() && ops.top()!='('){
                char op = ops.top();
                ops.pop();
                
                int v2 = nums.top();
                nums.pop();
                int v1 = nums.top();
                nums.pop();
                nums.push(calc(v1,v2,op));
            }
            if(!ops.empty()){
                ops.pop();
            }
        }
        else{
            while(!ops.empty() && prec(ops.top())>=prec(ch)){
                char op = ops.top();
                ops.pop();
                
                int v2 = nums.top();
                nums.pop();
                int v1 = nums.top();
                nums.pop();
                nums.push(calc(v1,v2,op));
            }
            ops.push(ch);
        }
    }
    while(!ops.empty()){
        char op = ops.top();
        ops.pop();
                
        int v2 = nums.top();
        nums.pop();
        int v1 = nums.top();
       nums.pop();
        nums.push(calc(v1,v2,op));
    }
    return nums.top();
}
int main(){

    string s = "2^3-5+4-3*6+7";
    cout<<eval(s)<<endl;

    return 0;
}