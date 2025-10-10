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
        int n,q;
        cin>>n>>q;
        vector<int>arr(n);
        set<int>pos;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==1)pos.insert(i);
        }
        while(q--){
            int c;cin>>c;
            if(c==1){
                int v;cin>>v;
                int num=sz(pos);
                if((v-num)&1){
                    if(num==0)no;
                    else{
                        int s1=2*(*pos.rbegin())-(num-1);
                        int s2=2*(n-*pos.begin()-1)-(num-1);
                        if(v<=max(s1,s2))yes;
                        else no;
                    }
                }else{
                    if(v<=(2*n-num))yes;
                    else no;
                }
            }else{
                int i;cin>>i;i--;
                pos.erase(i);
                cin>>arr[i];
                if(arr[i]==1)pos.insert(i);
            }
        }
    }
return 0;
}