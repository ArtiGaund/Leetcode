class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> map;

        // Count occurrences of each number
        for (int num : arr) {
            map[num]++;
        }

        for (int num : arr) {
            // Check for double
            if (num != 0 && map.find(2 * num) != map.end()) {
                return true;
            }
            // Handle zero case (ensure there are at least two zeros)
            if (num == 0 && map[num] > 1) {
                return true;
            }
        }
        return false;
    }
};