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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        
        vector<pair<pair<char,int>,int>>vec;
        vec.pb({{s[0],0},1});
        for(int i=1;i<n;i++){
            if(s[i]==vec.back().f.f)vec.back().s++;
            else vec.pb({{s[i],i},1});
        }

        // for(int i=0;i<sz(vec);i++){
        //     cout<<vec[i].f.f<<sp<<vec[i].f.s<<sp<<vec[i].s<<endl;
        // }

        int bad=0;
        vector<pair<pair<char,int>,int>>temp;
        for(int i=0;i<sz(vec);i++){
            if(vec[i].s!=k){bad++;temp.pb(vec[i]);}
        }

        // for(int i=0;i<sz(temp);i++){
        //     cout<<temp[i].f.f<<sp<<temp[i].f.s<<sp<<temp[i].s<<endl;
        // }

        if(bad==0){
            cout<<n<<endl;
            continue;
        }

        if(bad==1){
            if(temp[0].s!=2*k){
                cout<<-1<<endl;
                continue;
            }
            if(temp[0].f.f==vec.back().f.f){
                cout<<-1<<endl;
                continue;
            }
            cout<<temp[0].f.s+k<<endl;
            continue;
        }

        if(bad!=2){
            cout<<-1<<endl;
            continue;
        }

        if(temp.back().f.s + temp.back().s != n){
            cout<<-1<<endl;
            continue;
        }

        if(temp[0].f.f != temp[1].f.f){
            cout<<-1<<endl;
            continue;
        }

        if(temp[0].s>k)temp[0].s-=k;

        if(temp[0].s+temp[1].s!=k){
            cout<<-1<<endl;
            continue;
        }

        cout<<temp[0].f.s+temp[0].s<<endl;
    }
return 0;
}