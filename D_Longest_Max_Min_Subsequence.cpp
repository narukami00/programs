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
        cout << it +1 << " ";
    return ostream;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;

        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            arr[i]--;
        }

        vector<int>pos(n+1,LLONG_MAX);
        for(int i=0;i<n;i++){
            pos[arr[i]]=i;
        }

        priority_queue<int,vector<int>,greater<int>>pq(all(pos));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> max_can,min_can;
        vector<bool>used(n,0);

        for(int i=0;i<=pq.top();i++){
            max_can.push({-arr[i],i});
            min_can.push({arr[i],i});
        }

        vector<int>ans;
        int i=0;

        while(!min_can.empty()){
            auto [x,pos]=(sz(ans)%2==0?max_can.top():min_can.top());
            
            if(sz(ans)%2==0){
                max_can.pop();
                x*=-1;
            }else{
                min_can.pop();
            }

            ans.pb(x);
            i=pos+1,used[x]=1;
            
            while(pq.top()!=LLONG_MAX && used[arr[pq.top()]]){
                int j=pq.top();
                pq.pop();
                for(int k=j+1;k<=min(pq.top(),n-1);k++){
                    max_can.push({-arr[k],k});
                    min_can.push({arr[k],k});
                }
            }

            while(!max_can.empty() && (used[-max_can.top().f] || max_can.top().s<i)){
                max_can.pop();
            }
            while(!min_can.empty() && (used[min_can.top().f] || min_can.top().s<i)){
                min_can.pop();
            }
        }

        cout<<sz(ans)<<endl;
        cout<<ans<<endl;
    }
return 0;
}