#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sp " "
#define all(x) x.begin(), x.end()
int dp[1001][3001];


int apple(int l, int n, int k){
    if(n<=l)return 0;
    if(n<=k)return n-l;
    if(l==0)return n;
    if(dp[l][n]!=-1)return dp[l][n];

    int max_cnt=LLONG_MIN;
    int trip_cnt;
    if(n%k==0){
        trip_cnt=((2*n)/k)-1;
    }
    else{
        trip_cnt=((2*n)/k)+1;
        
    } 

    for(int i=1;i<=l;i++){
        int current=apple(l-i,n-trip_cnt*i,k);
        if(current>max_cnt){
            max_cnt=current;
            dp[l][n]=max_cnt;
        }
    }
    
    return max_cnt;
}

int maxapple(int l, int n, int k){
    memset(dp,-1,sizeof(dp));
    return apple(l,n,k);
}

int32_t main(){
    Flashyy
    //tc
    {
        int l,n,k;
        cin>>l>>n>>k;
        cout<<maxapple(l,n,k)<<endl;
    }
return 0;
}