//
// Created by lidong on 2021/6/29.
//

#ifndef LEETCODECPP_BINARY_SEARCH_704_H
#define LEETCODECPP_BINARY_SEARCH_704_H

class Binary_Search_704 {
public:
    int search(std::vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size() - 1;
        while(head >= 0 && head <= tail) {
            int mid = (head + tail) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) {
                tail = mid - 1;
            }
            else {
                head = mid + 1;
            }
        }

        return -1;
    }
};

#endif //LEETCODECPP_BINARY_SEARCH_704_H
