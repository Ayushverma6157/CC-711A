class Solution {
public:
    vector<int> rangeSumQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> sum(n + 1, 0);
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + arr[i - 1];
        }
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            ans.push_back(sum[r + 1] - sum[l]);
        }
        return ans;
    }
};
