#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define FastAF ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)

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

int32_t main(){
    FastAF
    tc
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        //cin>>arr;
        //int gcd=1;
        cin>>arr;
        int z = 1;
        for (int i = 0; i < n; i++) {
        z = lcm(z, arr[i]);
        }
        int sum=0;
        vector<int> sol(n);
        for(int i=0;i<n;i++){
            sol[i]=z/arr[i];
            sum+=sol[i];
        }

        if(z>sum){
            cout<<sol<<endl;
        }
        else cout<<"-1"<<endl;
    }
return 0;
}