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
#define yes (cout << "YES" \
                  << "\n")
#define no (cout << "NO" \
                 << "\n")
#define rep(i, a, b) for (int i = a; i < b; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
 
using namespace std;
 
const int N = 1005, M = 1005;
char labyrinth[N][M];
int visited[N][M];
p_ii path[N][M];
qp_ii qq;
 
int moves, nodes_left_in_layer, nodes_in_next_layer;
 
const int dr[] = { -1, +1, 0, 0};
const int dc[] = {0, 0, +1, -1};
 
int n, m, sr, sc;
 
void exploreNeighbours(int r, int c)
{
 
    for (int i = 0; i < 4; i++)
    {
        int rr = r + dr[i];
        int cc = c + dc[i];
 
        if (rr < 0 || cc < 0 || rr >= n || cc >= m)
            continue;
 
        if (visited[rr][cc] || labyrinth[rr][cc] == '#')
            continue;
 
        qq.push(mp(rr, cc));
        visited[rr][cc] = 1;
        path[rr][cc] = mp(r, c);
        nodes_in_next_layer += 1;
    }
}
 
void solve()
{
 
    cin >> n >> m;
 
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == 'A')
            {
                sr = i;
                sc = j;
            }
        }
    }
 
    mem0(visited);
 
    bool reached_end = false;
    qq.push(mp(sr, sc));
    visited[sr][sc] = 1;
    moves = 0, nodes_left_in_layer = 1, nodes_in_next_layer = 0;
 
    p_ii temp;
    while (qq.size() > 0)
    {
 
        temp = qq.front();
 
        if (labyrinth[temp.ff][temp.ss] == 'B')
        {
            reached_end = true;
            break;
        }
 
        exploreNeighbours(temp.ff, temp.ss);
 
        nodes_left_in_layer--;
        if (nodes_left_in_layer == 0)
        {
            nodes_left_in_layer = nodes_in_next_layer;
            nodes_in_next_layer = 0;
            moves++;
        }
 
        qq.pop();
    }
 
    if (reached_end)
    {
 
        yes;
        cout << moves << nline;
 
        string pathString = "";
        int prevX = temp.ff, prevY = temp.ss;
        int currX, currY;
        while (true)
        {
 
            if (temp.ff == sr && temp.ss == sc)
                break;
            currX = path[temp.ff][temp.ss].ff;
            currY = path[temp.ff][temp.ss].ss;
 
            if (prevX == currX)
            {
                if (currY > prevY)
                    pathString += "L";
                else
                    pathString += "R";
            } else if (prevY == currY)
            {
                if (currX > prevX)
                    pathString += "U";
                else
                    pathString += "D";
            }
 
            temp = mp(currX, currY);
            prevX = currX, prevY = currY;
        }
 
        reverse(pathString.begin(), pathString.end());
        cout << pathString << nline;
    }
    else
        no;
 
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