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
#define sz(x) x.size()
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
        int n,k;
        cin>>n>>k;
        
        if(n==1){
            if(k==1){
                cout<<1<<endl<<1<<endl;
            }else{
                cout<<-1<<endl;
            }
            continue;
        }

        if(k==1 || k==n){
            cout<<-1<<endl;
            continue;
        }

        int temp;
        if(k%2==0) temp=0;
        else temp=1;

        if(k-temp-1<1 || n-k-temp<1){
            cout<<-1<<endl;
            continue;
        }

        int p1=1;
        int p2=k-temp;
        int p3=k+temp+1;
        
        cout<<3<<endl;
        cout<<p1<<sp<<p2<<sp<<p3<<endl;
    }
return 0;
}