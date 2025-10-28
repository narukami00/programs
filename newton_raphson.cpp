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

struct Params {
    double tol_f = 1e-3;     
    double tol_x = 1e-8;     
    int max_iter = 100;
};

template <typename F, typename DF>
bool newton_raphson(F f, DF df, double x0, double &root,int &iter_count, const Params &p) {
    double x = x0;
    for (int i = 0; i < p.max_iter; i++) {
        double fx = f(x);
        double dfx = df(x);

        if (!isfinite(fx) || !isfinite(dfx) || fabs(dfx) < 1e-12)
            return false; 

        double x_new = x - fx / dfx;

        if (fabs(fx) < p.tol_f || fabs(x_new - x) < p.tol_x) {
            root = x_new;
            iter_count = i + 1;
            return true;
        }

        if (fabs(x_new) > 1e6) 
            return false;

        x = x_new;
    }
    root = x;
    return true; 
}

template <typename F, typename DF>
void find_all_roots(F f, DF df, double start, double end, double step, const Params &p) {
    vector<pair<double,int>> roots;

    for (double x = start; x <= end; x += step) {
        double root;
        int iter_count;
        if (newton_raphson(f, df, x, root, iter_count, p))
            roots.pb({root, iter_count});
    }
    sort(all(roots));
    roots.erase(unique(all(roots),
                       [](pair<double,int> a, pair<double,int> b) { return fabs(a.f - b.f) < 1e-4; }),
                roots.end());

    if (roots.empty())
        cout << "No roots found.\n";
    else {
        cout << "Roots found (" << roots.size() << "):\n";
        for (int i = 0; i < roots.size(); i++)
            cout << "  Root " << i + 1 << " = " << roots[i].f <<" After "<<roots[i].s<<" iterations\n";
    }
}

int32_t main() {
    auto f = [](double x) { return pow(x,4) - 3*x*x*x + 2*x*x + 6*x; };
    auto df = [](double x) { return 4*x*x*x - 9*x*x + 4*x + 6; };
    
    Params p;
    find_all_roots(f, df, -sqrt(5), sqrt(5) , 0.5, p);
}
