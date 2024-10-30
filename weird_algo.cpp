#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n; // Use long long to handle larger values of n
    cin >> n;

    vector<long long> ans; // Vector to store the sequence

    while (n != 1)
    {
        ans.push_back(n); // Add current n to the sequence
        if (n % 2 == 0)
        {
            n /= 2; // If n is even, divide by 2
        }
        else
        {
            n = n * 3 + 1; // If n is odd, multiply by 3 and add 1
        }
    }
    ans.push_back(1); // Finally add 1 to the sequence

    // Output the sequence
    for (long long num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
