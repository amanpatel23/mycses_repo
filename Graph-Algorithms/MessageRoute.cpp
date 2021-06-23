/*
    Author: Aman Patel
    Date: 08-06-2021
*/
 
#include <bits/stdc++.h>
 
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
#define yes (cout << "YES" << "\n")
#define no (cout << "NO" << "\n")
#define rep(i, a, b) for(int i = a; i < b; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
 
using namespace std;
 
const int N = (1e5 + 5);
v_i adjList[N];
int n, m;
 
void addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
 
bool shortesPath(int dist[], int pred[]) {
 
    bool visited[n + 1];
    mem0(visited);
 
    q_i bfsQueue;
    bfsQueue.push(1);
    visited[1] = true;
 
    while (!bfsQueue.empty()) {
        int ele = bfsQueue.front();
        for (int x : adjList[ele]) {
            if (!visited[x]) {
                visited[x] = true;
                dist[x] = dist[ele] + 1;
                pred[x] = ele;
                bfsQueue.push(x);
 
                if (x == n)
                    return true;
            }
        }
 
        bfsQueue.pop();
    }
 
    return false;
}
 
void solve() {
    cin >> n >> m;
 
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        addEdge(a, b);
    }
 
    int dist[n + 1], pred[n + 1];
    for (int i = 0; i <= n; i++)
        dist[i] = i_max;
    dist[1] = 0;
 
    mem1(pred);
 
    if (!shortesPath(dist, pred))
        cout << "IMPOSSIBLE" << nline;
    else {
        int resultCount = 0;
        v_i resultPath;
        int i = n;
        while (true) {
            resultPath.push_back(i);
            i = pred[i];
            resultCount += 1;
 
            if (i == -1)
                break;
        }
 
        cout << resultCount << nline;
        reverse(resultPath.begin(), resultPath.end());
        for(auto x : resultPath)
            cout << x << " ";
    }
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