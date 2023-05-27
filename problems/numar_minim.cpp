#include <bits/stdc++.h>

#define NMAX 20005

int main() {
    
    std::unordered_map<int, int> dist;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    std::cin >> n;
    
    std::vector<int> v;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        v.push_back(x);
        v.push_back(-x);
    }
        
    int src, tgt;
    std::cin >> src >> tgt;
    
    std::queue<std::pair<int, int>> q;

    q.push({src, 0});
    dist[src] = 0;

    while (!q.empty()) {
        auto [top, op] = q.front();
        q.pop();
        for (auto offset : v) {
            if (top + offset <= 20000 && top + offset >= -20000) {
                int number = top + offset;
                if (dist.find(number) == dist.end()) {
                    dist[number] = op + 1;
                    q.push({number, op + 1});
                }
            }
        }
    }
    
    std::cout << dist[tgt] << "\n";
    
    return 0;
}