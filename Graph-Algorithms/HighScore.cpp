/*
Created By: Aman Patel
Date: 03-07-2021
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
//#define i_max 1e15
//#define i_min -1e15
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
 
const int i_max = 1e17;
const int i_min = i_max * (-1);
 
struct edge {
    int src;
    int dest;
    int weight;
};
 
int n, m;
vector<edge> edges;
v_i dist;
 
void bellmanFord() {
 
    rep(i, 0, (n - 1)) {
        for (auto e: edges) {
            int u = e.src;
            int v = e.dest;
            int w = e.weight;
 
            if (dist[u] == i_max) continue;
            dist[v] = min(dist[v], w + dist[u]);
            dist[v] = max(dist[v], i_min);
        }
    }
 
//    rep(i, 0, n) cout << dist[i] << " ";
//    cout << nline;
 
    rep(i, 0, (n - 1)) {
        for (auto e: edges) {
            int u = e.src;
            int v = e.dest;
            int w = e.weight;
 
            if (dist[u] == i_max) continue;
            dist[v] = max(dist[v], i_min);
            if (dist[v] > dist[u] + w) {
                dist[v] = i_min;
            }
        }
    }
 
}
 
void solve() {
 
    cin >> n >> m;
 
    edges.resize(m);
    struct edge temp;
    rep(i, 0, m) {
        cin >> temp.src >> temp.dest >> temp.weight;
        temp.src--;
        temp.dest--;
        temp.weight *= -1;
        edges[i] = temp;
    }
 
    dist.resize(n);
    rep(i, 0, n) dist[i] = i_max;
    dist[0] = 0;
 
    bellmanFord();
//    rep(i, 0, n) cout << dist[i] << " ";
//    cout << nline;
    //cout << dist[n - 1] << nline;
    (dist[n - 1] == i_min) ? (cout << "-1" << nline) : (cout << (-1 * dist[n - 1]) << nline);
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