/*
    Author: Aman Patel
    Date: 21-06-2021
*/
 
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
 
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
 
const int N = (1e5 + 10);
v_i adjList[N];
bool visited[N];
stk_i ansStack;
int toStartWith = -1;
 
void addEdge(int a, int b) {
    adjList[a].pb(b);
    adjList[b].pb(a);
}
 
bool dfs(int curr, int parent) {
 
    visited[curr] = true;
    ansStack.push(curr);
    //cout << curr << " ";
 
    for (auto x: adjList[curr]) {
        if (!visited[x]) {
            if (dfs(x, curr))
                return true;
        } else {
            if (x != parent) {
                toStartWith = x;
                return true;
            }
        }
    }
 
    ansStack.pop();
    return false;
}
 
void solve() {
 
    int n, m;
    cin >> n >> m;
 
    int a, b;
    rep(i, 0, m) {
        cin >> a >> b;
        addEdge(a, b);
    }
 
    // print Graph
//    rep(i, 1, (n + 1))
//    {
//        cout << i << " -> ";
//        for(auto x: adjList[i])
//            cout << x << " ";
//        cout << nline;
//    }
 
    mem0(visited);
    bool flag = false;
    rep(i, 1, (n + 1)) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                flag = true;
                break;
            }
        }
    }
 
    //cout << nline;
    if (flag) {
        v_i resultArr;
        //cout << toStartWith << " ";
        resultArr.pb(toStartWith);
        while (!ansStack.empty()) {
            int ele = ansStack.top();
            //cout << ele << " ";
            resultArr.pb(ele);
            if (ele == toStartWith)
                break;
 
            ansStack.pop();
        }
 
        cout << resultArr.size() << nline;
        for (auto x: resultArr)
            cout << x << " ";
 
    } else
        cout << "IMPOSSIBLE" << nline;
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