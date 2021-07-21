//
// Created by lidong on 2021/7/19.
//

#ifndef LEETCODECPP_MINIMUM_SIZE_SUBARRAY_SUM_209_H
#define LEETCODECPP_MINIMUM_SIZE_SUBARRAY_SUM_209_H
class Minimum_Size_Subarray_Sum_209 {
public:
    /**
     * @brief 一种O(N2)的暴力做法
     * @param target
     * @param nums
     * @return
     */
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int curr_sum = 0;
        int min_k = nums.size() + 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i; j < nums.size(); j++) {
                curr_sum += nums[j];
                if(curr_sum >= target && (j - i + 1) < min_k) {
                    min_k = (j - i + 1);
                    break;
                }
            }
            curr_sum = 0;
        }
        return min_k > nums.size() ? 0 : min_k;
    }

    /**
     * @brief 滑动窗口解法
     * @param target
     * @param nums
     * @return
     */
    int minSubArrayLen2(int s, std::vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};
#endif //LEETCODECPP_MINIMUM_SIZE_SUBARRAY_SUM_209_H
