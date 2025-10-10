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
        int num0=0;
        int num1=0;
        for(int i=1;i<30;i+=2)num0|=(1<<i);
        for(int i=0;i<30;i+=2)num1|=(1<<i);
        
        cout<<num0<<endl;
        int x;cin>>x;

        cout<<num1<<endl;
        int y;cin>>y;

        cout<<"!"<<endl;
        int z;cin>>z;

        int val1=0,val2=0;
        for(int i=0;i<30;i+=2){
            if((x>>(i+1))&1){
                val1|=(1<<i);
                val2|=(1<<i);
            }else if((x>>i)&1){
                val1|=(1<<i);
            }

            x-=4*(1<<i);
        }

        y-=2;
        for(int i=1;i<30;i+=2){
            if(((y>>(i+1))&1) && !((y>>i)&1)){
                val1|=(1<<i);
                val2|=(1<<i);
            }else if(((y>>i)&1) && !((y>>(i+1))&1)){
                val1|=(1<<i);
            }

            y-=4*(1<<i);
        }

        int ans=0;
        for(int i=0;i<30;i++){
            int cur=(z>>i)&1;
            int cur1=(val1>>i)&1;
            int cur2=(val2>>i)&1;

            if(cur||cur2){
                ans+=2*(1<<i);
            }else if(cur1){
                ans+=(1<<i);
            }
        }

        cout<<ans<<endl;
    }
return 0;
}