#include <bits/stdc++.h>

using namespace std;

#define NMAX 5005

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    std::cin >> n;
    
    std::vector<int> important_meetings;
    
    int battery = 0;
    
    for (int i = 0; i < n; ++i) {
        int type, importance;
        std::cin >> type >> importance;
        if (type == 0) {
            battery += importance;
        } else if (type == 1) {
            important_meetings.push_back(importance);
        }
    }
    
    int x;
    std::cin >> x;
    
    std::sort(important_meetings.begin(), important_meetings.end(), std::greater<int>()); // sortare crescatoare
    // std::sort(importance.begin(), importance.end(), std::greater<int>()); // sortare descrescatoare
    // std::sort(importance.begin(), importance.end(), [](auto elem1, auto elem2) {
    //     return elem1 < elem2; 
    // });
    
    for (int i =0 ; i < std::min(x, (int) important_meetings.size()); ++i) {
        battery += important_meetings[i];
    }
    
    for (int i = std::min(x, (int) important_meetings.size()); i < important_meetings.size(); ++i) {
        battery -= important_meetings[i];
    }
    
    std::cout << battery << "\n";
    
    
    return 0;
}