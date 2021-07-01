//
// Created by lidong on 2021/6/29.
//

#ifndef LEETCODECPP_REMOVE_ELEMENT_27_H
#define LEETCODECPP_REMOVE_ELEMENT_27_H

class Remove_Element_27 {
public:
    int removeElement(std::vector<int>& nums, int val) {
        if(nums.size() == 1 && nums[0] == val)
            return 0;
        int i = 0, j = nums.size() - 1;
        for(; i < j; i++) {
            while(nums[i] == val && i < j) {
                std::swap(nums[i], nums[j]);
                j--;
            }
        }
        return nums[j] == val ? j : j + 1;
    }
};

#endif //LEETCODECPP_REMOVE_ELEMENT_27_H
