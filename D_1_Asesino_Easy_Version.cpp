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

bool query(int i,int j,int ans=0){
    cout<<"? "<<i<<sp<<j<<endl;
    cin>>ans;
    return ans;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        
        int t=n;
        pair<int,int>can={-1,-1};

        while(t>4){
            if(query(t-1,t)!=query(t,t-1)){
                can={t-1,t};
                break;
            }else t-=2;
        }

        if(can.f!=-1){
            int innocent=(can.f==n-1?n-2:n);
            if(query(can.f,innocent)!=query(innocent,can.f)){
                cout<<"! "<<can.f<<endl;
            }else cout<<"! "<<can.s<<endl;
        }else{
            if(t==3){
                if(query(1,2)==query(2,1))cout<<"! 3"<<endl;
                else if(query(1,3)==query(3,1))cout<<"! 2"<<endl;
                else cout<<"! 1"<<endl;
            }else{
                if(query(1,2)!=query(2,1)){
                    if(query(1,3)==query(3,1))cout<<"! 2"<<endl;
                    else cout<<"! 1"<<endl;
                }else{
                    if(query(1,3)!=query(3,1))cout<<"! 3"<<endl;
                    else cout<<"! 4"<<endl; 
                }
            }
        }

    }
return 0;
}