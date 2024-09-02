#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;
    
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2]; 
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                    dp[i][j] = dp[i][j] || dp[i - 1][j]; 
                }
            }
        }
    }
    
    
    return dp[m][n];
}

int main() {
    
    cout << boolalpha; // Para imprimir 'true' ou 'false' no lugar de 1 e 0
    cout << "Example 1: " << isMatch("aa", "a") << endl;    // Output: false
    cout << "Example 2: " << isMatch("aa", "a*") << endl;   // Output: true
    cout << "Example 3: " << isMatch("ab", ".*") << endl;   // Output: true

    return 0;
}