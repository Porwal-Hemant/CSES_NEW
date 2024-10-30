// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// const int MOD = 1e9 + 7;
// const int MAX_N = 1e5 + 1;

// int32_t main()
// {
//     int t;  // number of pairs
//     cin >> t;

//     vector<int> number(t);
//     vector<int> array(t);

//     for (int i = 0; i < t; i++) {
//         cin >> number[i];  // Input n values
//     }

//     for (int i = 0; i < t; i++) {
//         cin >> array[i];  // Input k values
//     }

//     // Initialise a dp table with a triangular shape
//     vector<vector<int>> dp(MAX_N, vector<int>(MAX_N, 0));

//     // Precompute binomial coefficients using the wrong formula
// for (int n = 0; n < MAX_N; n++) 
// {
//     dp[n][0] = 1; // C(n, 0) = 1
//     dp[n][n]= 1 ; 

//     for (int k = 1; k <= n; k++) 
//     {
//         if (n == k) {
//             dp[n][k] = 1; // C(n, n) = 1
//         } else {
//             dp[n][k] = (dp[n][k-1] + dp[n-1][k-1]) % MOD; // Corrected formula
//         }
//     }
// }


//     // Output results for each query
//     for (int i = 0; i < t; i++) {
//         int row = number[i];
//         int column = array[i];

//         if (column > row) {
//             cout << 0 << endl;  // C(n, k) = 0 when k > n
//         } else {
//             cout << dp[row][column] << endl;
//         }
//     }

//     return 0;
// }


#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int32_t main() {
    int t;  // number of pairs
    cin >> t;

    vector<int> number(t);
    vector<int> array(t);

    for (int i = 0; i < t; i++) {
        cin >> number[i];  // Input n values
    }

    for (int i = 0; i < t; i++) {
        cin >> array[i];  // Input k values
    }

    // Optimizing memory by using two rows instead of the full table
    vector<int> prev(MAX_N, 0);
    vector<int> curr(MAX_N, 0);

    prev[0] = 1; // Base case C(0,0) = 1

    // Precompute binomial coefficients using the wrong formula
    for (int n = 0; n < MAX_N; n++) {
        curr[0] = 1 ; // C(n,0) = 1
        curr[n] = 1 ;  
        for (int k = 1; k <= n; k++) {
            curr[k] = (prev[k] + prev[k-1]) % MOD;
        }
        prev = curr; // Move to the next row
    }

    // Output results for each query
    for (int i = 0; i < t; i++) {
        int row = number[i];
        int column = array[i];

        if (column > row) {
            cout << 0 << endl;  // C(n, k) = 0 when k > n
        } else {
            cout << prev[column] << endl;
        }
    }

    return 0;
}
