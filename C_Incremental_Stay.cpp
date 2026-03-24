#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define sp " "
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) x.size()
#define f first
#define s second
#define pb push_back
#define eb emplace_back

template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>a(2*n);
        cin>>a;

        //cout<<a<<endl;

        vector<int>pre1(2*n,0),pre2(2*n,0);
        for(int i=1;i<2*n;i++){
            if(i>0 && i%2==0){
                pre1[i]=pre1[i-1];
            }else if(i%2==1) pre1[i]=pre1[i-1]+a[i]-a[i-1];

            if(i>1 && i%2==1){
                pre2[i]=pre2[i-1];
            }else if(i%2==0) pre2[i]=pre2[i-1]+a[i]-a[i-1];
        }

        //cout<<pre1<<endl<<pre2<<endl;

        int ans=0,prev=0;
        for(int k=1;k<=n;k++){
            if(k==1){ans=pre1[2*n-1];prev=ans;}
            else if(k%2==0){
                ans=ans-prev+pre2[2*n-k]-pre2[k-1]+a[2*n-k+1]-a[k-2];
                prev=pre2[2*n-k]-pre2[k-1];
            }else{
                ans=ans-prev+pre1[2*n-k]-pre1[k-1]+a[2*n-k+1]-a[k-2];
                prev=pre1[2*n-k]-pre1[k-1];
            }

            cout<<ans<<" ";
        }
        cout<<endl;
    }
return 0;
}