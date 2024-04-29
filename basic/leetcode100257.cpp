class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        long long k = ((long long) n * (n + 1) / 2 + 1) / 2;
        auto check = [&](int meidan_num) {
            long long cnt = 0;
            int l = 0;
            unordered_map<int, int> hmap;
            for (int r = 0; r < n; r++) {
                hmap[nums[r]]++;
                while (hmap.size() > meidan_num) {
                    int erase_num = nums[l];
                    l++;
                    hmap[erase_num]--;
                    if (!hmap[erase_num]) {
                        hmap.erase(erase_num);
                    }
                }
                cnt += r - l + 1;
            }
            return cnt < k;
        };
        int l = 0, r = n;
        int mid = (l + r) >> 1;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};