#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> parent;

void dfs(int start, int pre)
{
    visited[start] = true;
    for (auto x : graph[start])
    {
        if (x != pre)
        {
            if (!visited[x])
            {
                parent[x] = start;
                dfs(x, start);
            }
            else
            {
                vector<int> ans = {x};
                do
                {
                    ans.push_back(start);
                    start = parent[start];
                } while (start != x);
                ans.push_back(ans[0]);

                cout << ans.size() << "\n";
                for (auto y : ans)
                {
                    cout << y << " ";
                }
                exit(0);
            }
        }
    }
}

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    file_i_o();
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    visited.resize(n + 1);
    parent.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, 0);
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}