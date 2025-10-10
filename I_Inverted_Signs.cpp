#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
#define double long double
#define endl '\n'
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define Flashyy                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
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

int gcd(int a, int b)
{
    while (b != 0)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int rsum(int x, int y)
{
    if (x > y)
        return 0;
    return (x + y) * (y - x + 1) / 2;
}

#define tc     \
    int TC;    \
    cin >> TC; \
    for (int tt = 1; tt <= TC; tt++)

int32_t main()
{
    Flashyy
    // tc
    {
        int n;
        cin >> n;
        // vector<int> arr(n);
        int arr[n];
        // cin>>arr;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        // if(n==1){
        //     // cout<<arr[0];
        //     // cout<<0<<endl;
        //     cout<<abs(arr[0])<<endl;
        //     return 0;
        // }
        int max1 = 0, max2 = 0;
        int i1 = -1, i2 = -1;

        ll ans = 0;
        for (int i = 0; i < n - 1; i++)
        {

            ans += abs(arr[i] - arr[i + 1]);
            // if(arr[i]<0 && arr[i+1]<0){
            // }else if(arr[i]>=0&&arr[i+1]>=0){
            // }
            // else
            if ((arr[i] > 0 && arr[i + 1] < 0) || (arr[i] < 0 && arr[i + 1] > 0))
            {
                if (max1 <= abs(arr[i] - arr[i + 1]))
                {
                    // cout<<"lo"<<endl;
                    max2 = max1;
                    i2 = i1;
                    max1 = abs(arr[i] - arr[i + 1]);
                    i1 = i;
                }
                else if (max2 < abs(arr[i] - arr[i + 1]))
                {
                    max2 = abs(arr[i] - arr[i + 1]);
                    i2 = i;
                }
            }
        }
        // cout<<ans<<endl;
        // cout << i2 << " " << i1 << endl;
        ans=abs(ans);
        if (i2 != -1)
        {
            ll temp = abs(arr[i2] - arr[i2 + 1]);
            ll temp2 = abs(abs(arr[i2]) - abs(arr[i2 + 1]));
            ans -= (temp - temp2);
        }
        ans=abs(ans);

        if (i1 != -1)
        {
            ll temp = abs(arr[i1] - arr[i1 + 1]);
            ll temp2 = abs(abs(arr[i1]) - abs(arr[i1 + 1]));
            ans -= (temp - temp2);
        }
        ans=abs(ans);

        cout << ans << endl;
    }
    return 0;
}