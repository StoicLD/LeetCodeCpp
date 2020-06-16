#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include "ValidateIPAddress_468.h"

using namespace std;
/*
 * 为了方便，函数的实现也写在头文件里面了
 * 同时头文件也是用using namespace std
 */


void printIP(const string &s, ValidateIPAddress_468& ip, const string &expectedStr)
{
    cout << "ip:" << s << " is expected to be " << expectedStr << "  and it is actually " << ip.validIPAddress(s) << endl;
}

int main()
{
    string IPV4 = "IPv4";
    string IPV6 = "IPv6";
    string NEITHER = "Neither";

    ValidateIPAddress_468 vip;
/*
    string ip1 = "172.16.254.1";
    //assert(vip.validIPAddress(ip1) == IPV4);
    printIP(ip1, vip, IPV4);

    string ip2 = "172.16.254.01";
    //assert(vip.validIPAddress(ip2) == NEITHER);
    printIP(ip2, vip, NEITHER);

    string ip3 = "172.16..254.1";
    //assert(vip.validIPAddress(ip3) == NEITHER);
    printIP(ip3, vip, NEITHER);

    string ip4 = ".172.16.254.1";
    printIP(ip4, vip, NEITHER);

    //assert(vip.validIPAddress(ip4) == NEITHER);

    string ip5 = "272.16.254.1";
    printIP(ip5, vip, NEITHER);

    string ip6 = "072.16.254.1";
    printIP(ip6, vip, NEITHER);
*/

    string ip7 = "2001:0db8:85a3:0000:0000:8a2e:0370:7334";
    printIP(ip7, vip, IPV6);

    string ip8 = "02001:0db8:85a3:0000:0000:8a2e:0370:7334";
    printIP(ip8, vip, NEITHER);

    string ip9 = "2001:0db8:85a3:0010:0003:8a2e:0370:7334";
    printIP(ip9, vip, NEITHER);

    string ip10 = "2001:0db8:85a3:40000:0000:8a2e:0370:7334";
    printIP(ip10, vip, NEITHER);

    string ip11 = "2001:0Fb8:85a3:0000:0000:8a2E:0370:7334";
    printIP(ip11, vip, IPV6);

}
