#ifndef LEETCODECPP_TWITTER_PROBLEM_SET_H
#define LEETCODECPP_TWITTER_PROBLEM_SET_H

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;
class TwitterProblemSet1 {
public:
    vector<string> signInSignOutLogs(const vector<string>& logs, int max_span)
    {
        vector<string> tokens;
        vector<string> result;
        unordered_map<string, int> table;
        for(auto& s : logs)
        {
            istringstream iss(s);
            copy(istream_iterator<string>(iss),
                istream_iterator<string>(),
                back_inserter(tokens));
            if(tokens.size() == 3)
            {
                if(tokens[2] == "sign-in")
                {
                    if(table.find(tokens[0]) != table.end())
                    {
                        table[tokens[0]] -= stoi(tokens[1]);
                        if(table[tokens[0]] <= max_span)
                        {
                            result.push_back(tokens[0]);
                        }
                    }
                    else
                    {
                        table[tokens[0]] = -stoi(tokens[1]);
                    }
                }
                else if(tokens[2] == "sign-out")
                {
                    if(table.find(tokens[0]) != table.end())
                    {
                        table[tokens[0]] += stoi(tokens[1]);
                        if(table[tokens[0]] <= max_span)
                        {
                            result.push_back(tokens[0]);
                        }
                    }
                    else
                    {
                        table[tokens[0]] = stoi(tokens[1]);
                    }
                }
            }
            tokens.clear();
        }
        return result;
    }

    void hackerCards()
    {
        unordered_set<int> table;
        vector<int> result;
        string input;
        int min_card = INT32_MAX;
        int n;
        getline(std::cin, input);
        n = stoi(input);
        while(n--)
        {
            getline(std::cin, input);
            int card = stoi(input);
            table.insert(card);
            if(card < min_card)
            {
                min_card = card;
            }
        }
        getline(std::cin, input);
        int d = stoi(input);
        
        for(auto i = min_card + 1; d >= i; i++)
        {
            if(table.find(i) == table.end())
            {
                d -= i;
                result.push_back(i);
            }
        }

        cout << endl;
        for(auto c : result)
        {
            cout << c << endl;
        }
    }

    void closetNumbers()
    {
        int n;
        string input;
        getline(cin, input);
        n = stoi(input);
        const int nums_size = n;
        vector<int> nums(n, 0);
        while(n--)
        {
            getline(cin, input);
            int num = stoi(input);
            nums[n] = num;
        }

        int min_distance = INT32_MAX;
        
        vector<pair<int,int> > result;
        for(int i = 0; i < nums_size; i++)
        {
            int curr_min_dis = INT32_MAX;
            vector<pair<int, int> > target_values;
            for(int j = i + 1; j < nums_size; j++)
            {
                int curr_dis = abs(nums[i] - nums[j]);
                if(curr_dis < curr_min_dis)
                {
                    curr_min_dis = curr_dis;
                    target_values.clear();
                    target_values.push_back(make_pair(min(nums[i], nums[j]), max(nums[i], nums[j])));
                }
                else if(curr_dis == curr_min_dis)
                {
                    target_values.push_back(make_pair(min(nums[i], nums[j]), max(nums[i], nums[j])));
                }
            }
            if(curr_min_dis < min_distance)
            {
                min_distance = curr_min_dis;
                result = target_values;
            }
            else if(curr_min_dis == min_distance)
            {
                result.insert(result.end(), target_values.begin(), target_values.end());
            }
        }

        sort(result.begin(), result.end(), [](pair<int, int> a, pair<int, int> b) {
            if(a.first == b.first)
            {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        
        cout << endl;
        for(auto p : result)
        {
            cout << p.first << " " << p.second << endl;
        }
    }

    int twitterNewOfficeDesign(vector<int>& positions, vector<int>& heights)
    {
        int result = 0;
        if(positions.size() != heights.size())
        {
            return 0;
        }

        // suppose positions is sorted
        for(int i = 0; i < positions.size() - 1; i++)
        {
            result = max(result, twitterNewOfficeDesignHelper(positions, heights, i));
        }

        return positions.size() == 1 ? heights[0] + 1 : result;
    }

    int twitterNewOfficeDesignHelper(vector<int>& positions, vector<int>& heights, int index)
    {
        int left = positions[index];
        int right = positions[index + 1];
        int left_value = heights[index];
        int right_value = heights[index + 1];
        if(abs(left_value - right_value) >= abs(left - right))
        {
            return min(left_value, right_value) + abs(left - right);
        }
        else
        {
            // return (abs(left_value - right_value) + (left + right)) / 2;
            return (abs(right - left) + (left_value + right_value)) / 2;
        }
    }

    int EfficientJobProcessingService(vector<int> tasks, vector<int> weights, int p)
    {
        vector<int> dp(p + 1, 0);
        for(int i = 0; i < tasks.size(); i++)
        {
            for(int j = p; j >= 0; j--)
            {
                dp[j] = max(dp[j], dp[j - tasks[i] * 2] + weights[i]);
            }
        }
        return dp[p];
    }

    int EfficientJobProcessingService2(vector<int> tasks, vector<int> weights, int p)
    {
        int n = tasks.size();
        vector<vector<int>> dp(n + 1, vector<int>(p + 1, 0));

        for(int i = 0; i < tasks.size(); i++)
        {
            for(int j = 1; j <= p; j++)
            {
                if(j - tasks[i] * 2 >= 0)
                {
                    dp[i + 1][j] = max(dp[i][j], dp[i][j - tasks[i] * 2] + weights[i]);
                }
                else
                {
                    dp[i + 1][j] = dp[i][j];
                }
            }
        }
        return dp[n][p];
    }

};

#endif //LEETCODECPP_TWITTER_PROBLEM_SET_H