#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define see(x) cout  <<"<DBG> " << #x << ": " << (x) << endl
#endif
#ifndef LOCAL
#define see(x)
#endif
template<typename T> void println(const T &t) { cout << t << '\n'; }
template<typename T, typename ...Args> void println(const T &t, const Args &...rest) { cout << t << ' '; println(rest...); }

template<typename T> void print(const T &t) { cout << t << ' '; }

template<typename T, typename ...Args> void print(const T &t, const Args &...rest) { cout << t; print(rest...); }

// this overload is chosen when there's only one argument
template<class T> void scan(T &t) { cin >> t; }
template<class T, class ...Args> void scan(T &a, Args &...rest) { cin >> a; scan(rest...); }
using ll = long long;
using vl = vector<ll>;
using vi = vector<int>;
using pii = pair<int,int>;
using vb = vector<bool>;
using vpii = vector<pii>;

#define rng(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(n) for(int _ = 0, __ = (int)n; _ < __; _++)
#define stp(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define FOR(x, cont) for (auto &x: cont)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define SZ(x) (int)(x).size()
#define pq(T,COMP) priority_queue<T, vector<T>, COMP>
#define popcnt(x) __builtin_popcount((x))
#define SET(arr, v) memset(arr, (v), sizeof (arr))
#define UNIQ(vec) (vec).erase(unique(all(vec)), (vec).end())
auto bet = [](const ll x, const ll y, const ll i) {
    return x <= i && i <= y;
};

template <typename T>
struct bit {
    vector<T> a;
    explicit bit(int n, int v = 0) {
        a.resize(n + 1);
        if(v != 0) {
            for (int i = 1; i <= n; ++i) a[i] = v;
        }
    }

    T sum(T x) {
        T res = 0;
        while (x) {
            res += a[x];
            x -= x & -x;
        }
        return res;
    }

    T sum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int x, T v) {
        while (x < a.size()) {
            a[x] += v;
            x += x & -x;
        }
    }
    void clear(){
        fill(a.begin(), a.end(), 0);
    }
};
vi get_prime(int n) {
    vi minp(n + 1), p;
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = i;
            p.pb(i);
        }
        FOR(x, p) {
            if (x <= minp[i] && x * i <= n)
                minp[x * i] = x;
            else break;
        }
    }
    return p;
}

const int mod = 998244353;

void add_mod(ll &x, const ll &y) {
    x += y;
    if (x >= mod) x -= mod;
}
void sub_mod(ll &x, const ll &y) {
    x -= y;
    if (x < 0) x += mod;
}
// alias templates
template<typename T> using vv = vector<vector<T>>;
template <typename T1, typename T2 = T1> using vp = vector<pair<T1,T2>>;



using vec = vector<ll>;
using mat = vector<vec>;
mat get_I(int n) {
    mat res(n, vec(n));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    return res;
}

mat operator*(const mat &a, const mat &b) {
    mat c(a.size(), vec(b[0].size()));
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a[0].size(); j++) {
            if (a[i][j]) { // optimization for sparse matrix
                for (size_t k = 0; k < b[0].size(); k++) {
                    add_mod(c[i][k], a[i][j] * b[j][k] % mod);
                }
            }
        }
    }
    return c;
}

vec operator*(const mat &a, const vec &b) {
    vec c(a.size());
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a[0].size(); j++) {
            add_mod(c[i], a[i][j] * b[j] % mod);
        }
    }
    return c;
}

mat pow(mat a, ll n) {
    mat res(a.size(), vec(a[0].size()));
    for (size_t i = 0; i < a.size(); i++) {
        res[i][i] = 1;
    }
    while (n) {
        if (n & 1) {
            res = res * a;
        }
        a = a * a;
        n >>= 1;
    }
    return res;
}



/**** SUPER MACROs ****/
#define FAIL {println("No"); return 0;}
const int N = 100005;


int main() {
#ifdef LOCAL
    freopen("main.in", "r", stdin);
//    freopen("main.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    scan(n, k);

    vi d(n), lev(n);
    vi par(n);


    vv<int> g(n);
    rep(n - 1) {
        int u, v;
        scan(u, v);
        --u, --v;
        d[u]++, d[v]++;
        g[u].pb(v), g[v].pb(u);
    }




    int c3 = 0;
    rng(i, 0, n) {
        if (d[i] == 2) FAIL
        c3 += d[i] == 3;
        if (c3 == 2) FAIL
    }
    queue<int> que;
    rng(i, 0, n) if(d[i] == 1) {
        lev[i] = 1;
        FOR(j, g[i]) {
            if (d[j] == 1) FAIL;
            if (!lev[j]) {
                par[i] = j;
                lev[j] = lev[i] + 1;
                que.push(j);
            }
        }
    }
    while (que.size() > 1) {
        auto u = que.front(); que.pop();
        bool flag = false;
        FOR (v, g[u]) {
            if (lev[v]) {
                if (lev[v] == lev[u] + 1) {
                    if (!flag) par[u] = v, flag = true;
                    else FAIL
                }
                else if(lev[v] != lev[u] -1) FAIL
            }
            else if(!flag) {
                flag = true;
                que.push(v);
                lev[v] = lev[u] + 1;
                par[v] = u;
            } else FAIL
        }
        if (!flag) FAIL
    }

    if (que.size() != 1) FAIL;
    int u = que.front();

//    vi a[2];
//    int cur = 0;
//    rng(i, 0, n) if (d[i] == 1) {
//            lev[i] = 1;
//            FOR(j, g[i]) {
//                if (d[j] == 1)  FAIL
//                if (!lev[j]) {
//                    lev[j] = 2;
//                    a[cur].pb(j);
//                }
//            }
//        }
//
//    while(!a[cur].empty()) {
//        cur ^= 1;
//        a[cur].clear();
//        FOR(x, a[cur ^ 1]) FOR(y, g[x])
//            if (!lev[y]) {
//                     lev[y] = lev[x] + 1;
//                     a[cur].pb(y);
//                 }
//                 else if(abs(lev[x] - lev[y])) FAIL
//    }
//
//    if (SZ(a[cur^1]) != 1) FAIL
//
//    int u = a[cur^1].back();
    if (lev[u] != k + 1 || c3 && d[u] != 3) FAIL

    println("Yes");


#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}