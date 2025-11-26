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
int t,n;
vector<int>nums;
set<vector<int>,greater<>>res;

void bktrk(int idx, int cur_sum, vector<int>&cur){
    if(cur_sum==t){
        res.insert(cur);
        return;
    }

    if(cur_sum>t || idx>=n)return;

    cur.pb(nums[idx]);
    bktrk(idx+1,cur_sum+nums[idx],cur);
    cur.pop_back();

    int nxt=idx+1;
    while(nxt<n && nums[nxt]==nums[idx])nxt++;

    bktrk(nxt,cur_sum,cur);
}

int32_t main(){
    Flashyy
    //tc
    while(cin>>t>>n)
    {
        if(n==0)break;
        nums.resize(n);
        for(int i=0;i<n;i++)cin>>nums[i];
        res.clear();
        vector<int>cur;
        bktrk(0,0,cur);
        cout<<"Sums of "<<t<<":"<<endl;
        if(res.empty()){
            cout<<"NONE"<<endl;
        }else{
            for(auto &it:res){
                for(int i=0;i<it.size();i++){
                    if(i)cout<<"+";
                    cout<<it[i];
                }
                cout<<endl;
            }
        }
    }
return 0;
}