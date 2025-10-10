#include<bits/stdc++.h>
using namespace std;

int solve(){
    int m,n;
    cin>>n>>m;
    int a[n][m];
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            a[i][j]=s[j]-'0';
        }
    }
    int b[n][m];
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            b[i][j]=s[j]-'0';
        }
    }

    int flag=1,sum_a=0,sum_b=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum_a+=a[i][j];
            sum_b+=b[i][j];
        }
        if(sum_a%3 != sum_b%3){flag=0; return flag;}
    }
    sum_a=0,sum_b=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sum_a+=a[j][i];
            sum_b+=b[j][i];
        }
        if(sum_a%3 != sum_b%3){flag=0; return flag;}
    }

    return flag;
}
int main(){
    int t; cin >> t;
    while(t--) {
        int ans = solve();
        if(ans==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        }
    return 0;
}