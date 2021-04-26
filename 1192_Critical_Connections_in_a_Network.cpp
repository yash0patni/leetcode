class Solution {
public:
    void dfs(vector<vector<int>> &arr, int node, int par, vector<int> &vis, vector<int> &in, vector<int> &low, int &timer, vector<vector<int>> &ans)
    {
        //cout << "in dfs " << timer << endl;
        vis[node] = 1;
        in[node] = low[node] = timer;
        timer++;

        for (int child : arr[node])
        {
            if (child == par) continue;
            if (vis[child])
            {
                low[node] = min(low[node], in[child]);
            }
            else
            {
                dfs(arr, child, node, vis, in, low, timer, ans);
                if (low[child] > in[node])
                {
                    ans.push_back({child, node});
                    //cout << child << " - " << node << " is a bridge..." << endl;
                }
                low[node] = min(low[node], low[child]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> arr(n+1);
        for (int i = 0; i < connections.size(); i++)
        {
            int x = connections[i][0];
            int y = connections[i][1];
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        vector<int> vis(n+1);
        vector<int> in(n+1);
        vector<int> low(n+1);
        vector<vector<int>> ans;
        int timer = 0;
        dfs(arr, 0, -1, vis, in, low, timer, ans);
        return ans;
    }
};