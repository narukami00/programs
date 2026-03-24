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
        int n,m;
        cin>>n>>m;

        if(m<n || m>(n*(n+1))/2){
            cout<<-1<<endl;
            continue;
        }

        if(m==n){
            cout<<"1"<<endl;
            for(int i=1;i<=n-1;i++){
                cout<<i<<" "<<i+1<<endl;
            }
            continue;
        }

        if(m==n*(n+1)/2){
            cout<<n<<endl;
            for(int i=1;i<=n-1;i++){
                cout<<n<<" "<<i<<endl;
            }
            continue;
        }

        if(m>=2*n){
            cout<<n<<endl;
            int left=m-n;
            int i=1;
            vector<bool> vis(n+1,0);
            do{
                left-=(n-i);
                if(left<=(n-(i+1)) && left>0){
                    cout<<n<<" "<<left+1<<endl;
                    vis[left+1]=1;
                    for(int j=2;j<=n;j++){
                        if(!vis[j]){
                            cout<<1<<" "<<j<<endl;
                        }
                    }
                }else if(left>0){
                    cout<<n<<" "<<n-i<<endl;
                    vis[n-i]=1;
                    i++;
                }
            }while(left>0);
            continue;
        }

        if(m<=2*n-1){
            cout<<2<<endl;
            int left=m-2;
            int twos=left/2;
            int ones=left%2;
            while(twos+ones!=n-1){
                twos--;
                ones+=2;
            }
            int total=n;
            while(twos--){
                cout<<2<<" "<<total<<endl;
                total--;
            }
            while(ones--){
                cout<<1<<" "<<total<<endl;
                total--;
            }
            continue;
        }

    }
return 0;
}