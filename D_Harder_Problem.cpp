#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sp " "
#define all(x) x.begin(), x.end()

template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int rsum(int x, int y){
    if(x>y)return 0;
    return (x+y)*(y-x+1)/2;
}

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int> a;
        map<int,int> mp;

        for(int i=0;i<n;i++){
            int m;
            cin>>m;
            if(mp[m]==0)a.push_back(m);
            mp[m]=1;
        }

        if(a.size()==n){
            for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        else{
            int i=1;
            while(a.size()!=n){
                if(!mp[i])a.push_back(i);
                i++;
            }

            for(int i=0;i<n;i++)cout<<a[i]<<" ";
            cout<<endl;
        }

    }
return 0;
}