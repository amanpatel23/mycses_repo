/*
Created By: Aman Patel
Date: 11-07-2021
*/

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <iomanip>

#define int long long
#define mod 1000000007
#define i_max INT_MAX
#define i_min INT_MIN
#define s_i set<int>
#define v_i vector<int>
#define v_s vector<string>
#define v_c vector<char>
#define stk_i stack<int>
#define q_i queue<int>
#define qp_ii queue<pair<int, int>>
#define pqp_ii priority_queue<pair<int, int>>
#define vp_ii vector<pair<int, int>>
#define um_ii unordered_map<int, int>
#define m_ii map<int, int>
#define p_ii pair<int, int>
#define all(a) (a).begin(), (a).end()
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define lbnd lower_bond
#define ubnd upper_bond
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define nline "\n"
#define yes (cout << "YES" << nline)
#define no (cout << "NO" << nline)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

const int N = 2505;
const int M = 5005;
struct edge {
    int src;
    int dest;
    int weight;
};
vector<edge> edges(M);
int n, m;

void bellmanFord() {

    v_i dist(N, 0);
    v_i relaxant(N, -1);

    int x;
    rep(i, 0, n) {

        x = -1;
        for (auto edge: edges) {
            int u = edge.src;
            int v = edge.dest;
            int w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                relaxant[v] = u;
                x = v;
            }
        }
    }

    if (x == -1)
        no;
    else {
        yes;

        rep(i, 0, n) x = relaxant[x];

        v_i result;
        int v = x;
        while (true) {
            result.pb(v);
            if (v == x && result.size() > 1)
                break;

            v = relaxant[v];
        }

        reverse(all(result));
        for (auto x: result)
            cout << x << " ";
    }
}

void solve() {

    cin >> n >> m;
    rep(i, 0, m) {
        edge temp;
        cin >> temp.src >> temp.dest >> temp.weight;
        edges[i] = temp;
    }

    bellmanFord();
}

int32_t main() {

    fast;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}