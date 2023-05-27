#include <bits/stdc++.h>

using namespace std;

#define NMAX 1005

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n, m, p, start_row, start_col;
    
    int adj[NMAX][NMAX];
    
    cin >> n >> m >> p >> start_row >> start_col;
    // std::vector<std::vector<int> adj(n + 1, std::vector<int>(m + 1 + 1));
    
    // vector<int> v(5, 0); // vector cu 5 elemente de valoare 0
    // vector<int> v{5, 0}; // vector cu 2 elemente cu valoare 5 si 0
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> adj[i][j];
        }
    }   
    
    int max_value = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (abs(i - start_row) + abs(j - start_col) <= p) {
                max_value = std::max(max_value, adj[i][j]);
            } 
        }
    }
    
    std::cout << max_value << "\n";
    
    
    
    return 0;
}