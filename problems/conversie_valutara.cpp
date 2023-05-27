#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <iomanip>

using namespace std;

#define NMAX 105

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    std::cin >> n >> m;
    std::vector<std::tuple<int, int, double>> edges;
    for (int i = 0; i < m; ++i) {
        int x, y;
        double d;
        std::cin >> x >> y >> d;
        edges.push_back({x, y, d});
    }
    
    double dp[NMAX][NMAX];
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                dp[i][i] = 1;
            } else {
                dp[i][j] = -1;                
            }
        }
    }
    
    for (auto [x, y, d] : edges) {
        dp[x][y] = d;
    }
    
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dp[i][k] >= 0 && dp[k][j] >= 0 && dp[i][k] * dp[k][j] >= dp[i][j]) {
                    dp[i][j] = dp[i][k] * dp[k][j];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cout << std::fixed << std::setprecision(10) << dp[i][j] << " ";  
        }
        
        std::cout << "\n";
    }
    
    return 0;
}