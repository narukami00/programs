#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
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

        set<int>known;
        vector<pair<int,int>>ans;

        known.insert(1);
        
        for(int i=2;i<=n;i++){
            while(known.count(i)==0){
                int cur=1;
                int target=i;

                while(known.count(target)==0){
                    cout<<"? "<<cur<<sp<<target<<endl;
                    int x;cin>>x;

                    if(x==cur){
                        known.insert(target);
                        ans.pb({cur,target});
                    }else if(known.count(x)!=0){
                        cur=x;
                    }else{
                        target=x;
                    }
                }
            }
        }

        cout<<"! ";
        for(auto [p,q]:ans)cout<<p<<sp<<q<<sp;
        cout<<endl;
    }
return 0;
}