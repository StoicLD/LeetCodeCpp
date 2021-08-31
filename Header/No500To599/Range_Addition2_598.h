//
// Created by Dong Li on 8/30/21.
//

#ifndef LEETCODECPP_HEADER_NO500TO599_RANGE_ADDITION2_598_H_
#define LEETCODECPP_HEADER_NO500TO599_RANGE_ADDITION2_598_H_
class Range_Addition2_598 {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int col_min = m;
        int raw_min = n;
        for(auto& op : ops)
        {
            if(op[0] != 0)
            {
                col_min = min(op[0], col_min);
            }
            if(op[1] != 0)
            {
                raw_min = min(op[1], raw_min);
            }
        }
        return col_min * raw_min;
    }
};
#endif //LEETCODECPP_HEADER_NO500TO599_RANGE_ADDITION2_598_H_
