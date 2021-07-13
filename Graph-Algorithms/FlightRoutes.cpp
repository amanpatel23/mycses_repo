/*
Created By: Aman Patel
Date: 13-07-2021
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
#define i_max 1e15
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

const int N = 1e5;
vp_ii adjList[N];
int n, m, k;

void addEdge(int a, int b, int c) {
    adjList[a].pb(mp(b, c));
}

void dijkstras() {

    vector<vector<int>> dist(n, vector<int>(k, i_max));
    dist[0][0] = 0;

    priority_queue<p_ii, vector<p_ii >, greater<>> pq;
    pq.push(mp(0, 0));

    while(!pq.empty()) {

        int u = pq.top().ss;
        int d = pq.top().ff;
        pq.pop();

        if(dist[u][k - 1] < d) continue;

        for(auto e: adjList[u]) {

            int v = e.ff;
            int c = e.ss;

            if(dist[v][k - 1] > (d + c)) {
                dist[v][k - 1] = d + c;
                pq.push(mp(dist[v][k - 1], v));
                sort(all(dist[v]));
            }
        }
    }

    for(auto x: dist[n - 1])
        cout << x << " ";
}

void solve() {

    cin >> n >> m >> k;

    int a, b, c;
    rep(i, 0, m) {
        cin >> a >> b >> c;
        a--, b--;
        addEdge(a, b, c);
    }

    dijkstras();
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
