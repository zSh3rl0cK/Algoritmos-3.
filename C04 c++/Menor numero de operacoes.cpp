#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainOrder(const vector<int>& dimensions) {
    int n = dimensions.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));

    // Para cadeias de comprimento 1, o custo é 0
    for (int i = 1; i < n; ++i) {
        dp[i][i] = 0;
    }

    for (int chainLength = 2; chainLength <= n; ++chainLength) {
        for (int i = 1; i <= n - chainLength; ++i) {
            int j = i + chainLength - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    vector<int> dimensions = {20, 35, 15, 10, 55};
    int minOperations = matrixChainOrder(dimensions);
    cout << "Menor numero de operacoes: " << minOperations << endl;
    return 0;
}
