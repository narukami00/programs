#include <bits/stdc++.h>
using namespace std;

struct Params {
    double tol_x = 1e-8;
    double tol_rel = 1e-8;
    double tol_f = 1e-10;
    int max_iter = 100;
    bool verbose = false;
};

// --------------------------
// False Position (Regula Falsi)
// --------------------------
template <typename F>
bool false_position(F f, double a, double b, double &root, string &reason, const Params &p) {
    double fa = f(a), fb = f(b);
    if (!isfinite(fa) || !isfinite(fb)) {
        reason = "Non-finite function values at endpoints.";
        return false;
    }
    if (fa * fb > 0) {
        reason = "No sign change in interval.";
        return false;
    }

    double prev_c = a;
    for (int iter = 1; iter <= p.max_iter; iter++) {
        double c = (a * fb - b * fa) / (fb - fa);
        double fc = f(c);

        if (p.verbose)
            cout << "Iter " << iter << ": a=" << a << " b=" << b << " c=" << c << " f(c)=" << fc << endl;

        // Stopping conditions
        if (fabs(fc) < p.tol_f) {
            root = c;
            reason = "Function value close enough to zero.";
            return true;
        }
        if (fabs(b - a) < p.tol_x) {
            root = c;
            reason = "Interval width below absolute tolerance.";
            return true;
        }
        if (fabs(b - a) < p.tol_rel * fabs(c)) {
            root = c;
            reason = "Interval width below relative tolerance.";
            return true;
        }
        if (fabs(c - prev_c) < 1e-14) {
            root = c;
            reason = "Stagnation detected (no progress).";
            return true;
        }

        // Normal regula falsi update
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }

        prev_c = c;
    }

    root = (a * fb - b * fa) / (fb - fa);
    reason = "Maximum iterations reached.";
    return true;
}

// --------------------------
// Finds all roots in an interval
// --------------------------
template <typename F>
void find_all_roots(F f, double start, double end, double step, const Params &p) {
    vector<double> roots;
    double a = start, fa = f(a);

    for (double b = a + step; b <= end; b += step) {
        double fb = f(b);

        if (!isfinite(fa) || !isfinite(fb)) {
            cout << "Discontinuity detected between " << a << " and " << b << endl;
        } else if (fa * fb < 0) {
            double root;
            string reason;
            if (false_position(f, a, b, root, reason, p)) {
                cout << "Root found at x = " << root << " between [" << a << ", " << b << "] | " << reason << endl;
                roots.push_back(root);
            }
        }

        fa = fb;
        a = b;

        if (roots.size() >= 10) break;
    }

    if (roots.empty())
        cout << "No roots found in given interval.\n";
    cout << endl;
}

// --------------------------
// Main function
// --------------------------
int main() {
    auto f1 = [](double x) { return x * x * x - 2 * x * x - 4 * x + 5; };
    auto f2 = [](double x) { return x * x - 4 * sin(x) - 5; };

    Params p;
    p.verbose = false;

    cout << "f1(x) = x^3 - 2x^2 - 4x + 5\n";
    find_all_roots(f1, -3.0, 3.0, 0.1, p);

    cout << "f2(x) = x^2 - 4sin(x) - 5\n";
    find_all_roots(f2, -5.0, 5.0, 0.1, p);

    return 0;
}
