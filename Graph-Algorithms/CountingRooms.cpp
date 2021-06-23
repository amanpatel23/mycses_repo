#include <bits/stdc++.h>
 
//#define int long long
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
#define yes (cout << "YES" \
                  << "\n")
#define no (cout << "NO" \
                 << "\n")
#define rep(i, a, b) for (int i = a; i < b; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
 
using namespace std;
 
int n, m;
char houseMap[1005][1005];
 
bool isValid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
 
void dfs(int x, int y)
{
    houseMap[x][y] = '#';
 
    if (isValid(x - 1, y) && houseMap[x - 1][y] == '.')
        dfs(x - 1, y);
 
    if (isValid(x, y + 1) && houseMap[x][y + 1] == '.')
        dfs(x, y + 1);
 
    if (isValid(x + 1, y) && houseMap[x + 1][y] == '.')
        dfs(x + 1, y);
 
    if (isValid(x, y - 1) && houseMap[x][y - 1] == '.')
        dfs(x, y - 1);
}
 
void solve()
{
 
    cin >> n >> m;
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> houseMap[i][j];
        }
    }
 
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (houseMap[i][j] == '.')
            {
                dfs(i, j);
                result += 1;
            }
        }
    }
 
    cout << result << nline;
}
 
int32_t main()
{
 
    fast;
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    int t;
    t = 1;
    //cin >> t;
 
    while (t--)
    {
        solve();
    }
 
    return 0;
}