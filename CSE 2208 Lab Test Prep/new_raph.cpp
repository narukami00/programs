#include<bits/stdc++.h> 
using namespace std;

struct Params{
    double tol_f=1e-4;
    int max_iter=100;
};

template<typename F, typename G>
bool newton_raphson(F f, G f_prime, double x0, double &root, int &iter_count, const Params &p){
    double x=x0;
    for(int i=1;i<=p.max_iter;i++){
        double fx=f(x);
        double dfx=f_prime(x);

        double x_new=x-fx/dfx;

        if(fabs(fx)<p.tol_f){
            root=x_new;
            iter_count=i;
            return true;
        }

        x=x_new;
    }
    return false;
}

template<typename F, typename G>
void find_all_roots(F f,G f_prime, double a, double b, double step, const Params &p){
    vector<pair<double,int>>roots;
    for(double x=a;x<=b;x+=step){
        double root;int iter_count;
        if(newton_raphson(f,f_prime,x,root,iter_count,p)){
            roots.push_back({root,iter_count});
        }
    }

    sort(roots.begin(),roots.end());
    roots.erase(unique(roots.begin(),roots.end(),[](const pair<double,int>&p1,const pair<double,int>p2){return fabs(p1.first-p2.first)<step*0.5;}),roots.end());
    if(roots.empty()){
        cout<<"No roots found in the given interval."<<endl;
    }else{
        cout<<"Roots found:"<<endl;
        for(const auto &r:roots){
            cout<<fixed<<setprecision(7)<<"Root: "<<r.first<<", Iterations: "<<r.second<<endl;
        }
    }
    cout<<endl;
}

int main(){
    Params p;

    auto func1=[](double x){return x*x - 4;};
    auto func1_prime=[](double x){return 2*x;};
    cout<<"Finding roots for f(x) = x^2 - 4 in interval [-5, 5]"<<endl;
    find_all_roots(func1,func1_prime, -5, 5, 0.5, p);
}