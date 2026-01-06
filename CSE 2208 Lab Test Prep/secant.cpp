#include<bits/stdc++.h>
using namespace std;

struct Params{
    double tol=1e-7;
    int max_iter=1000;
};

template<typename F>
bool secant(F f,double x0, double x1, double &root, int &iter_count, const Params &p){
    double f0=f(x0), f1=f(x1);
    for(int i=1;i<=p.max_iter;i++){
        double x2=x1-f1*(x1-x0)/(f1-f0);
        double f2=f(x2);

        if(fabs(f2)<p.tol){
            root=x2;
            iter_count=i;
            return true;
        }

        x0=x1,f0=f1,x1=x2,f1=f2;
    }
    return false;
}

template<typename F>
void find_all_roots(F f, double a, double b, double step, const Params &p){
    vector<pair<double,int>>roots;
    for(double x=a;x<=b;x+=step){
        double y=x+step;
        double root;
        int iter_count;
        if(secant(f,x,y,root,iter_count,p)){
            roots.push_back({root,iter_count});
        }
    }
    sort(roots.begin(),roots.end());
    roots.erase(unique(roots.begin(),roots.end(),[](const pair<double,int>&p1,const pair<double,int>&p2){return fabs(p1.first - p2.first) < 1e-6;}),roots.end());

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
    p.tol=1e-7;
    p.max_iter=1000;

    auto func1=[](double x){return x*x - 4;};
    cout<<"Finding roots for f(x) = x^2 - 4 in interval [-5, 5]"<<endl;
    find_all_roots(func1, -5, 5, 0.5, p);

    auto func2=[](double x){return cos(x) - x;};
    cout<<"Finding roots for f(x) = cos(x) - x in interval [-5, 5]"<<endl;
    find_all_roots(func2, -5, 5, 0.5, p);

    return 0;
}