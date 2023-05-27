#include <bits/stdc++.h>

using namespace std;

int grid[51][51][51];
int arr[51][51];
int N, M;

int sum(int i1, int j1, int i2, int j2)
{
    if (i1 == i2 && j1 == j2) {
        return arr[i1][j1];
    }
    return arr[i1][j1] + arr[i2][j2];
}
 
// Recursive function to return the
// required maximum cost path
int maxSumPath(int i1, int j1, int i2)
{
 
    // Column number of second path
    int j2 = i1 + j1 - i2;
 
    // Base Case
    if (i1 >= N || i2 >= N || j1 >= M || j2 >= M) {
        return 0;
    }
 
    // If already calculated, return from DP matrix
    if (grid[i1][j1][i2] != -1) {
        return grid[i1][j1][i2];
    }
    int ans = INT_MIN;
 
    // Recurring for neighbouring cells of both paths together
    ans = max(ans, maxSumPath(i1 + 1, j1, i2 + 1) + sum(i1, j1, i2, j2));
    ans = max(ans, maxSumPath(i1, j1 + 1, i2) + sum(i1, j1, i2, j2));
    ans = max(ans, maxSumPath(i1, j1 + 1, i2 + 1) + sum(i1, j1, i2, j2));
    ans = max(ans, maxSumPath(i1 + 1, j1, i2) + sum(i1, j1, i2, j2));
 
    // Saving result to the DP matrix for current state
    grid[i1][j1][i2] = ans;
 
    return ans;
}

int main() {
    memset(grid, -1, sizeof(grid));
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }

    cout << maxSumPath(0, 0, 0);

    return 0;
}