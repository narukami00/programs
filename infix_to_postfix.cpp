#include<bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c=='^') return 3;
    else if(c=='/' || c=='*') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

void toPostfix(string s){
    stack<char> st;
    string res;

    for(int i=0;i<s.length();i++){
        char c=s[i];

        if((c>='a' && c<='z') || (c>='A' && c<='Z')||(c>='0' && c<='9'))
            res+=c;
        else if(c=='(')
            st.push(c);
        else if(c==')'){
            while(st.top()!='('){
                res+=st.top();
                st.pop();
            }st.pop();
        }
        else{
            while(!st.empty() && prec(c)<=prec(st.top())){
                res+=st.top();
                st.pop();
            }st.push(c);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    cout<<res<<endl;
}

int main(){
    string test;
    cin>>test;
    toPostfix(test);
    return 0;
}