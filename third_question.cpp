#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;  // number of test cases
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> cards(n);
        for (int i = 0; i < n; i++) {
            cin >> cards[i];
        }

        // Sort the cards to make consecutive numbers adjacent
        sort(cards.begin(), cards.end());

        unordered_map<int, int> freq;  // frequency map to count distinct numbers
        int distinct_count = 0;        // number of distinct numbers in the window
        int max_cards = 0;             // to store the maximum number of cards Monocarp can take
        int left = 0;                  // left pointer for the window

        // Iterate with the right pointer
        for (int right = 0; right < n; right++) {
            // Increment frequency of the current card
            freq[cards[right]]++;
            // If this is a new number, increase the distinct count
            if (freq[cards[right]] == 1) {
                distinct_count++;
            }

            // While the distinct numbers exceed k, move the left pointer to reduce the window
            while (distinct_count > k) {
                freq[cards[left]]--;
                if (freq[cards[left]] == 0) {
                    distinct_count--;
                }
                left++;
            }

            // Update the maximum number of cards Monocarp can take
            max_cards = max(max_cards, right - left + 1);
        }
            
            // have to cross verify this      

        // Output the result for this test case
        cout << max_cards << endl;
    }

    return 0;
}


