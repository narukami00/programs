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
        int n,d,k;
        cin>>n>>d>>k;
        vector<int>st(n+2),en(n+2);

        for(int i=0;i<k;i++){
            int l,r;
            cin>>l>>r;
            st[l]++;
            en[r]++;
        }

        int cur=0;
        for(int i=1;i<=d;i++)cur+=st[i];

        int mx=cur,mn=cur;
        int mx_pos=1,mn_pos=1;

        for(int l=2;l+d-1<=n;l++){
            int r=l+d-1;

            cur+=st[r];
            cur-=en[l-1];

            if(cur>mx){
                mx=cur;
                mx_pos=l;
            }

            if(cur<mn){
                mn=cur;
                mn_pos=l;
            }
        }

        cout<<mx_pos<<" "<<mn_pos<<endl;
    }
return 0;
}