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
        int n,x,y;
        cin>>n>>x>>y;

        {
            int left=(x-1>0?x-1:x-1+n);
            int right=(x+1>n?x+1-n:x+1);

            if(y==left || y==right){
                bool odd=0;
                if(n&1){
                    odd=1;
                    n--;
                }

                for(int i=0;i<n;i++){
                    if(i&1)cout<<0<<sp;
                    else cout<<1<<sp;
                }

                if(odd)cout<<2;
                cout<<endl;

                continue;
            }
        }

        if(x>y)swap(x,y);
        
        vector<int>left,right;
        for(int i=x+1;i<y;i++){
            right.pb(i-1);
        }

        {
            int go=(y+1>n?y+1-n:y+1);
            while(go!=x){
                left.pb(go-1);
                go++;
                if(go>n)go-=n;
            }
        }

        reverse(all(left));

        vector<int>ans(n);
        bool left_even=sz(left)&1?0:1;
        bool right_even=sz(right)&1?0:1;

        if(left_even && right_even){
            ans[x-1]=1;
            ans[y-1]=0;
        }else {
            ans[x-1]=1;
            ans[y-1]=2;
        }

        bool f=1;
        for(auto x:left){
            if(f)ans[x]=0,f=0;
            else ans[x]=1,f=1;
        }
        f=1;
        for(auto x:right){
            if(f)ans[x]=0,f=0;
            else ans[x]=1,f=1;
        }

        cout<<ans<<endl;
    }
return 0;
}