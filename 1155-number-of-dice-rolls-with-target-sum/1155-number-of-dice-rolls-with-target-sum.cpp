class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if (n * k < target) return 0;
		vector<vector<int>> mem(2, vector<int>(target + 1, 0));
        const int MOD = 1e9 + 7;
		int cur = 1, other = 0;
		mem[0][0] = 1;

		for (int i = 1; i < n + 1; i++)
		{
			for (int val = 1; val < target + 1; val++)
			{
				int ret = 0;
				for (int j = 1; j <= k; j++)
				{
					if (val - j >= 0)
						ret += mem[other][val - j], ret %= MOD;
				}
				mem[cur][val] = ret;
			}
			cur = other;
			other = 1 - other;
			mem[cur][0] = 0;
		}
		//Printer::print(mem);
		return mem[other][target];
    }
};