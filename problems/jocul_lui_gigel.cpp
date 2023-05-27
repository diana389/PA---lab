#include <bits/stdc++.h>

int main() {
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n + 1);

    int sum = 0;

    for (int i = 1; i <= n; ++i) {
        std::cin >> v[i];
    } 

    for (int i = 1; i < n; ++i) {
        sum += abs(v[i + 1] - v[i]);
    }

    int diff_1 = INT_MAX;
    int diff_x = INT_MAX;
    for (int i = 1; i < n; ++i) {
        diff_1 = std::min(diff_1, abs(v[i] - 1) + abs(v[i + 1] - 1) - abs(v[i + 1] - v[i]));
        diff_x = std::min(diff_x, abs(v[i] - m) + abs(v[i + 1] - m) - abs(v[i + 1] - v[i]));
    }

    diff_1 = std::min({diff_1, abs(v[1] - 1), abs(v[n] - 1)});
    diff_x = std::min({diff_x, abs(v[1] - m), abs(v[n] - 1)});
    
    if(*std::max_element(v.begin(),v.end()) >= m) {
        diff_x = 0;
    }

    std::cout << sum + diff_1 + diff_x << "\n";

    return 0;
}