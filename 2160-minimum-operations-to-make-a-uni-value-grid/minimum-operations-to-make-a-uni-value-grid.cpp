class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // Initialize an empty array to store all numbers
        vector<int> numsArray;
        int result = INT_MAX;

        // Flatten the grid into numsArray and check if all elements have the
        // same remainder when divided by x
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                // If remainder of any element doesn't match the first element,
                // return -1
                if (grid[row][col] % x != grid[0][0] % x) return -1;
                numsArray.push_back(grid[row][col]);
            }
        }

        // Sort numsArray in non-decreasing order to easily calculate operations
        sort(numsArray.begin(), numsArray.end());

        int length = numsArray.size();
        vector<int> prefixSum(length, 0);
        vector<int> suffixSum(length, 0);

        // Calculate the prefix sum up to each index (excluding the current
        // element)
        for (int index = 1; index < length; index++) {
            prefixSum[index] = prefixSum[index - 1] + numsArray[index - 1];
        }

        // Calculate the suffix sum from each index (excluding the current
        // element)
        for (int index = length - 2; index >= 0; index--) {
            suffixSum[index] = suffixSum[index + 1] + numsArray[index + 1];
        }

        // Iterate through numsArray to calculate the number of operations for
        // each potential common value
        for (int index = 0; index < length; index++) {
            int leftOperations =
                (numsArray[index] * index - prefixSum[index]) / x;

            int rightOperations =
                (suffixSum[index] - numsArray[index] * (length - index - 1)) /
                x;

            // Update the result with the minimum operations needed
            result = min(result, leftOperations + rightOperations);
        }

        return result;
    }
};