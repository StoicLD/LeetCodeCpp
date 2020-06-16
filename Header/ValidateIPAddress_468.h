//
// Created by lidong on 2020/6/16.
//

#ifndef LEETCODECPP_VALIDATEIPADDRESS_468_H
#define LEETCODECPP_VALIDATEIPADDRESS_468_H
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class ValidateIPAddress_468
{
public:
    string validIPAddress(string IP)
    {
        // "172.16.254.1"
        // "2001:0db8:85a3:0:0:8A2E:0370:7334"
        // "172.0123.333121..."
        string IPV4 = "IPv4";
        string IPV6 = "IPv6";
        string NEITHER = "Neither";
        vector<string::iterator> delimiterVec;

        //check IPv4
        auto delimiterIt = IP.begin();
        if(*delimiterIt == '.')
            return NEITHER;
        delimiterVec.push_back(IP.begin());
        while ((delimiterIt = find(delimiterIt + 1, IP.end(), '.')) != IP.end())
        {
            delimiterVec.push_back(delimiterIt);
        }
        delimiterVec.push_back(IP.end());
        if(delimiterVec.size() == 5)
        {
            // IPv4
            // 192.10.34.01
            auto startIt = delimiterVec.begin();
            auto endIt = delimiterVec.begin() + 1;
            while (endIt != delimiterVec.end())
            {
                //（1） 小于等于3个字符
                //（2） 每个字符需要是数字
                //（3） 转换为数字之后在0-255之间
                string numberStr;
                for(auto it = (startIt == delimiterVec.begin()) ? *startIt : *startIt + 1; it != *endIt; it++)
                {
                    if(*it >= '0' && *it <= '9')
                    {
                        numberStr += *it;
                    }
                    else
                        return NEITHER;
                }

                if(!numberStr.empty() && numberStr.size() <= 3)
                {
                    //check no leading zero
                    int number = stoi(numberStr);
                    string numberStrBack = to_string(number);
                    if(number > 255 || number < 0 || numberStr.size() != numberStrBack.size())
                        return NEITHER;
                }
                else
                    return NEITHER;

                startIt += 1;
                endIt += 1;
            }

            return IPV4;
        }
        else if(delimiterVec.size() > 2)
        {
            return NEITHER;
        }
/*----------------------------------------------------------------------------------------------*/
        // check IPv6
        delimiterIt = IP.begin();
        delimiterVec.clear();
        if(*delimiterIt == '.')
            return NEITHER;
        delimiterVec.push_back(IP.begin());
        while ((delimiterIt = find(delimiterIt + 1, IP.end(), ':')) != IP.end())
        {
            delimiterVec.push_back(delimiterIt);
        }
        delimiterVec.push_back(IP.end());
        if(delimiterVec.size() == 9)
        {
            // IPv6
            // "2001:0dB8:85a3:00:0:8A2E:0370:7334"
            auto startIt = delimiterVec.begin();
            auto endIt = delimiterVec.begin() + 1;
            while (endIt != delimiterVec.end())
            {
                //（1） 小于等于4个字符
                //（2） 每个字符需要是数字或者大小写字母
                //（3） 允许存在leading zero
                string groupStr;
                for(auto it = (startIt == delimiterVec.begin()) ? *startIt : *startIt + 1; it != *endIt; it++)
                {
                    if((*it >= '0' && *it <= '9') || (*it >= 'a' && *it <= 'f') || (*it >= 'A' && *it <= 'F'))
                    {
                        groupStr += *it;
                    }
                    else
                        return NEITHER;
                }

                if(groupStr.empty() || groupStr.size() > 4)
                {
                    return NEITHER;
                }

                startIt += 1;
                endIt += 1;
            }
            return IPV6;
        }
        return NEITHER;
    }
};


#endif //LEETCODECPP_VALIDATEIPADDRESS_468_H
