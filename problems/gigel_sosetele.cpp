#include <bits/stdc++.h>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    std::cin >> n;
    
    std::string s1, s2;
    std::cin >> s1 >> s2;
    
    std::unordered_map<int, int> freq_s1;
    std::unordered_map<int, int> freq_s2;
    
    for (auto letter : s1) {
        freq_s1[letter]++;
    }
    
    for (auto letter : s2) {
        freq_s2[letter]++;
    }
    
    int res = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
        res += std::min(freq_s1[i], freq_s2[i]);
    }
    
    res += freq_s1['*'] + freq_s2['*'];
    std::cout << std::min(n, res) << "\n";
    
    return 0;
}