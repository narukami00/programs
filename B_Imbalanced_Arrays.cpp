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
        deque<pair<int,int>>dq;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            dq.pb({x,i});
        }
        sort(all(dq));

        vector<int>ans(n);
        int rem=0;
        bool pos=1;

        for(int i=n;i>0;i--){
            int curf=dq.front().f-rem;
            int curb=dq.back().f-rem;
            
            if(curf==0){
                ans[dq.front().s]=-i;
                dq.pop_front();
            }else if(curb==i){
                ans[dq.back().s]=i;
                dq.pop_back();
                rem++;
            }else{
                pos=0;
                break;
            }
        }

        if(!pos){no;continue;}

        yes;
        cout<<ans<<endl;
    }
return 0;
}