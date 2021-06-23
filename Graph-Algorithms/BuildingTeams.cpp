/*
    Author: Aman Patel
    Date: 19-06-2021
*/
 
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
 
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
bool visited[N];
int teams[N];
int n, m;
 
void addEdge(int a, int b) {
    adjList[a].pb(b);
    adjList[b].pb(a);
}
 
bool dfs(int currTeam, int currTeamType) {
    //cout << "currTeam: " << currTeam << " " << currTeamType << nline;
    visited[currTeam] = true;
    teams[currTeam] = currTeamType;
    for (auto x: adjList[currTeam]) {
        if (!visited[x]) {
            int nextTeamType = (currTeamType == 1 ? 2 : 1);
            if (dfs(x, nextTeamType))
                return true;
        } else {
            if (teams[currTeam] == teams[x]) {
                //cout << currTeam << " " << x << nline;
                return true;
            }
        }
    }
 
    return false;
}
 
void solve() {
 
    cin >> n >> m;
    int a, b;
    rep(i, 0, m) {
        cin >> a >> b;
        addEdge(a, b);
    }
 
    mem0(visited);
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, 1)) {
                flag = true;
                break;
            }
        }
    }
 
    if (flag) {
        cout << "IMPOSSIBLE" << nline;
    } else {
        rep(i, 1, (n + 1))cout << teams[i] << " ";
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