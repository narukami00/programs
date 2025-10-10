#include<bits/stdc++.h>
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


int32_t main(){
    Flashyy
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for (int i=0;i<n;i++){
            cin>>arr[i];
        }
        int f = 1;
        for (int i=1;i<= n;i++){
            if (2*(n-i)+1>arr[i-1] or 2*i-1>arr[i-1]){
                cout<<"NO\n";
                f=0;
                break;
            }
        }
        if (f) cout<<"YES\n";
    }
}
