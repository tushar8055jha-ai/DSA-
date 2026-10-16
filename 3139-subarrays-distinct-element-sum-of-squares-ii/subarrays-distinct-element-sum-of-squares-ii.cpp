class Solution {
    int mod = 1e9 + 7;
    vector<long long> sum_tree, sq_tree, lazy;

    void push_down(int node, int start, int end) {
        if (lazy[node] != 0) {
            int mid = start + (end - start) / 2;
            long long val = lazy[node];
            long long left_len = mid - start + 1;
            long long right_len = end - mid;
            
            // Update left child
            sq_tree[2 * node + 1] = (sq_tree[2 * node + 1] + 2 * val * sum_tree[2 * node + 1] + val * val % mod * left_len) % mod;
            sum_tree[2 * node + 1] = (sum_tree[2 * node + 1] + val * left_len) % mod;
            lazy[2 * node + 1] = (lazy[2 * node + 1] + val) % mod;
            
            // Update right child
            sq_tree[2 * node + 2] = (sq_tree[2 * node + 2] + 2 * val * sum_tree[2 * node + 2] + val * val % mod * right_len) % mod;
            sum_tree[2 * node + 2] = (sum_tree[2 * node + 2] + val * right_len) % mod;
            lazy[2 * node + 2] = (lazy[2 * node + 2] + val) % mod;
            
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (r < start || l > end) return;
        if (l <= start && end <= r) {
            long long len = end - start + 1;
            sq_tree[node] = (sq_tree[node] + 2 * val * sum_tree[node] + val * val % mod * len) % mod;
            sum_tree[node] = (sum_tree[node] + val * len) % mod;
            lazy[node] = (lazy[node] + val) % mod;
            return;
        }
        
        push_down(node, start, end);
        int mid = start + (end - start) / 2;
        
        update(2 * node + 1, start, mid, l, r, val);
        update(2 * node + 2, mid + 1, end, l, r, val);
        
        sum_tree[node] = (sum_tree[2 * node + 1] + sum_tree[2 * node + 2]) % mod;
        sq_tree[node] = (sq_tree[2 * node + 1] + sq_tree[2 * node + 2]) % mod;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum_tree.assign(4 * n, 0);
        sq_tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        
        unordered_map<int, int> last_seen;
        long long total_sum_of_squares = 0;
        
        for (int i = 0; i < n; ++i) {
            // Find where this element was last seen (or 0 if new)
            int start_idx = last_seen.count(nums[i]) ? last_seen[nums[i]] + 1 : 0;
            
            // Increment the count for all subarrays starting between start_idx and i
            update(0, 0, n - 1, start_idx, i, 1);
            
            // Update last seen position
            last_seen[nums[i]] = i;
            
            // sq_tree[0] holds the sum of squares for all subarrays ending at current index i
            total_sum_of_squares = (total_sum_of_squares + sq_tree[0]) % mod;
        }
        
        return total_sum_of_squares;
    }
};