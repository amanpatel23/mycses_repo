/*
    Author: Aman Patel
    Date: 03-06-2021
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
 
const int N = (1e5);
int Parent[N + 1];
 
int find(int i) {
    if (Parent[i] < 0)
        return i;
 
    return find(Parent[i]);
}
 
void merge(int a, int b) {
    if (abs(Parent[a]) >= abs(Parent[b])) {
        Parent[a] += Parent[b];
        Parent[b] = a;
    } else {
        Parent[b] += Parent[a];
        Parent[a] = b;
    }
}
 
void solve() {
 
    int n, m;
    cin >> n >> m;
 
    mem1(Parent);
 
    int a, b;
    rep(i, 0, m) {
        cin >> a >> b;
        int parent1 = find(a), parent2 = find(b);
 
        if (parent1 != parent2)
            merge(parent1, parent2);
    }
 
    int noOfSets = 0;
    int centerIdx = -1;
    for (int i = 1; i <= n; i++) {
        if (Parent[i] < 0) {
            noOfSets += 1;
            centerIdx = i;
        }
    }
 
    noOfSets -= 1;
    cout << noOfSets << nline;
    for (int i = 1; i <= n; i++) {
        if (Parent[i] < 0 && i != centerIdx)
            cout << centerIdx << " " << i << nline;
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