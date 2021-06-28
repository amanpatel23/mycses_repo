/*
    Author: Aman Patel
    Date: 27-06-2021
*/
 
#include <bits/stdc++.h>
 
#define int long long int
#define mod 1000000007
#define i_max LONG_LONG_MAX
#define i_min LONG_LONG_MIN
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
#define yes (cout << "YES" << "\n")
#define no (cout << "NO" << "\n")
#define rep(i, a, b) for(int i = a; i < b; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
 
using namespace std;
 
const int N = (1e5);
vp_ii adjList[N];
 
void addEdge(int a, int b, int w) {
    adjList[a].emplace_back(mp(b, w));
}
 
void solve() {
 
    int n, m;
    cin >> n >> m;
 
    adjList->resize(n);
    int a, b, w;
    rep(i, 0, m) {
        cin >> a >> b >> w;
        a--, b--;
        addEdge(a, b, w);
    }
 
    bool visited[n];
    mem0(visited);
 
    v_i dist(n, i_max);
    dist[0] = 0;
 
    //cout << dist[0] << nline;
    priority_queue<p_ii, vp_ii, greater< > > pq;
    pq.push(mp(0, 0));
 
    while (!pq.empty()) {
 
        int node = pq.top().ss;
        int weight = pq.top().ff;
        pq.pop();
 
        visited[node] = true;
        if(dist[node] < weight) // simply do nothing, current distance better than heap distand, we do nothing...
            continue;
 
        for (auto x: adjList[node]) {
            int xNode = x.ff;
            int xWeight = x.ss;
            if (visited[xNode])
                continue;
 
            int newWt = dist[node] + xWeight;
            if (newWt < dist[xNode]) {
                dist[xNode] = newWt;
                pq.push(mp(newWt, xNode));
            }
        }
    }
 
    for(auto x: dist)
        cout << x << " ";
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