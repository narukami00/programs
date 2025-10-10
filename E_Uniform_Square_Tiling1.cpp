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
    //tc
    {
        int n,k,r;
        cin>>n>>k;
        vector<string> arr(n);
        cin>>arr;

        int mini=LLONG_MAX;
    
        for(int i=0;i<n-k+1;i++){
            for(int j=0;j<n-k+1;j++){
                int g=0,s=0;
                for(int x=0;x<k;x++){
                    for(int y=0;y<k;y++){
                        if(arr[i+x][j+y]=='G')s++;
                        else g++;
                    }
                }
                r=min(g,s);
                mini=min(mini,r);
            }
        }
        cout<<mini<<endl;
    }
return 0;
}