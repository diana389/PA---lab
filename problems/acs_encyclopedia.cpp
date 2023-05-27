#include <bits/stdc++.h>

using namespace std;

#define NMAX 10005

void dfs(int node, std::vector<int> &adj, std::vector<bool> &visited, int &length) {
    visited[node] = 1;
    
    if (!visited[adj[node]]) {
        length++;
        dfs(adj[node], adj, visited, length);    
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    std::cin >> n;
    std::vector<int> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        adj[i] = x;
    }
    
    int max_length = INT_MIN;
    for (int node = 1; node <= n; ++node) {
        int length = 1; // avem deja un nod
        std::vector<bool> visited(n + 1, false);
        dfs(node, adj, visited, length);
        max_length = std::max(max_length, length);
    }
    
    std::cout << max_length << "\n";
    
    
    return 0;
}