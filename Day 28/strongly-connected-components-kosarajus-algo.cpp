// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1#



#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/
void transpose(int V, vector<int> adj[], vector<int> transpose_adj[]) {
    for (int u = 0; u < V; u++)
        for (auto v : adj[u])
            transpose_adj[v].push_back(u);
}

stack<int> s;

int dfs(vector<int> adj[], bool *visited, int u) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (visited[v] == 0)
            dfs(adj, visited, v);
    }
}

int fillorder(vector<int> adj[], bool *visited, int u) {
    visited[u] = true;
    for (auto v : adj[u])
        if (visited[v] == 0)
            fillorder(adj, visited, v);
    s.push(u);
}

int kosaraju(int V, vector<int> adj[]) {
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            fillorder(adj, visited, i);

    vector<int> transpose_adj[V];
    transpose(V, adj, transpose_adj);

    for (int i = 0; i < V; i++)
        visited[i] = false;

    int ans = 0;
    while (!s.empty()) {
        int temp = s.top();
        s.pop();

        if (!visited[temp]) {
            dfs(transpose_adj, visited, temp);
            ans++;
        }
    }

    return ans;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
  // } Driver Code Ends
  
  
  #include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj); 
        }
    }
    
    st.push(node); 
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " "; 
    vis[node] = 1; 
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose); 
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	}
	
	stack<int> st;
	vector<int> vis(n, 0); 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, st, vis, adj); 
	    }
	} 
	
	vector<int> transpose[n]; 
	
	for(int i = 0;i<n;i++) {
	    vis[i] = 0; 
	    for(auto it: adj[i]) {
	        transpose[it].push_back(i); 
	    }
	}
	
	
	
	while(!st.empty()) {
	    int node = st.top();
	    st.pop(); 
	    if(!vis[node]) {
	        cout << "SCC: "; 
	        revDfs(node, vis, transpose); 
	        cout << endl; 
	    }
	}
	
	
	return 0;
}
