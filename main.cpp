class Solution {
public:
    int minSwaps(string s) {
        int balance = 0; // Tracks the balance of opening and closing brackets
        int swaps = 0;   // Tracks the number of swaps needed
        std::vector<int> imbalance;

        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                balance++; // Increment for opening bracket
            } else {
                balance--; // Decrement for closing bracket
            }
            // If balance goes negative, it means there are more closing
            // brackets than opening
            if (balance < 0) {
                imbalance.push_back(i);
                balance =
                    0; // Reset balance because a swap will fix this imbalance
            }
        }

        swaps=imbalance.size()-imbalance.size() / 2; // Each 2 consecutive imbalanced closing brackets can be swapped
        return swaps;
    }
};
