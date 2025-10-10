#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  while(n--){
    string s;
    cin>>s;
    bool flg=false;
    int first_1=0,last_1=0;;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            first_1=i;
            break;
        }
    }
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1'){
            last_1=i;
            break;
        }
    }
    for(int i=first_1;i<=last_1;i++){
        if(s[i]=='0'){
            flg=true;
            break;
        }
    }
    if(!flg)cout<<"YES\n";
    else cout<<"NO\n";
  }
}