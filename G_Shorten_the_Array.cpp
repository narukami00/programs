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

const int X=29;
struct node{
    int child[2]{-1,-1};
    int last=-1;
};

int32_t main(){
    Flashyy
    tc
    {
        int n,k;
        cin>>n>>k;
        int ans=n+1;
        vector<node>trie(1);

        auto find=[&](int x,int idx)->int{
            int res=-1;
            int cur=0;
            bool f=1;
            for(int pos=X; f && pos>=0; pos--){
                int bx=(x>>pos)&1;
                int bk=(idx>>pos)&1;
                auto& child=trie[cur].child;
                if(bk==1){
                    if(child[bx^1]!=-1){
                        cur=child[bx^1];
                    }else f=0;
                }else{
                    if(child[bx^1]!=-1){
                        res=max(res,trie[child[bx^1]].last);
                    }
                    if(child[bx]!=-1){
                        cur=child[bx];
                    }else f=0;
                }
            }

            if(f)res=max(res,trie[cur].last);
            return res;
        };

        auto add=[&](int x,int idx){
            int cur=0;
            trie[cur].last=max(trie[cur].last,idx);
            for(int pos=X;pos>=0;pos--){
                int bx=(x>>pos)&1;
                if(trie[cur].child[bx]==-1){
                    trie[cur].child[bx]=sz(trie);
                    trie.pb(node());
                } 
                cur=trie[cur].child[bx];
                trie[cur].last=max(trie[cur].last,idx);
            }
        };

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            add(x,i);
            int y=find(x,k);
            if(y!=-1)ans=min(ans,i-y+1);
        }

        if(ans==n+1)cout<<-1<<endl;
        else cout<<ans<<endl;

    }
return 0;
}