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

void push(int x,int y,set<vector<int>>&for0,set<vector<int>>&for1,set<pair<int,int>>&vis){
    if(vis.find({x,y})!=vis.end()){
        return;
    }

    for0.insert({3*x+3*y+2,x,y});

    for1.insert({3*x+3*y+2,3*x+1,3*y+1});
    for1.insert({3*x+3*y+3,3*x+2,3*y+1});
    for1.insert({3*x+3*y+3,3*x+1,3*y+2});
    for1.insert({3*x+3*y+6,3*x+2,3*y+2});

    vis.insert({x,y});
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        cin>>arr;

        set<vector<int>> for0,for1;
        set<pair<int,int>> vis;

        push(0,0,for0,for1,vis);
        push(0,1,for0,for1,vis);
        push(1,0,for0,for1,vis);

        for(int i=0;i<n;i++){
            if(arr[i]==0){
                auto v=*for0.begin();
                int x=v[1],y=v[2];
                for1.erase({3*x+3*y+2,3*x+1,3*y+1});
                for0.erase(v);
                cout<<3*x+1<<sp<<3*y+1<<endl;

                push(x+1,y,for0,for1,vis);
                push(x+2,y,for0,for1,vis);
                push(x,y+1,for0,for1,vis);
                push(x,y+2,for0,for1,vis);
                push(x+1,y+1,for0,for1,vis);
            }else{
                auto v=*for1.begin();
                int x=v[1]/3,y=v[2]/3;
                for0.erase({3*x+3*y+2,x,y});
                for1.erase(v);
                cout<<v[1]<<sp<<v[2]<<endl;

                push(x+1,y,for0,for1,vis);
                push(x+2,y,for0,for1,vis);
                push(x,y+1,for0,for1,vis);
                push(x,y+2,for0,for1,vis);
                push(x+1,y+1,for0,for1,vis);
            }
        }        
    }
return 0;
}