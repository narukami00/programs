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

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int findGCD(const std::vector<int>& arr) {
    int result = arr[0];
    for (const int& num : arr) {
        result = gcd(result, num);
        if (result == 1) {
            return 1; 
        }
    }
    return result;
}


int32_t main(){
    Flashyy
    tc
    {
        int n,m;
        cin>>n>>m;
        vector<int> arr(m);
        cin>>arr;
        sort(all(arr));
        reverse(all(arr));

        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=i+i;j<=n;j+=i){
                if(ans[i]==ans[j])ans[j]++;
            }
        }

        if(*max_element(all(ans))>=m) cout<<-1<<endl;
        else{
            for(int i=1;i<=n;i++) cout<<arr[ans[i]]<<" ";
            cout<<endl;
        }

    }
return 0;
}