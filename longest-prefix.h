#include <string>
#include <vector>
#include <algorithm>

//easy
//https://leetcode.com/problems/longest-common-prefix/

using namespace std;


class Solution{
    public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        if(strs.size() == 1) return strs[0];
        vector<char> vec;
        sort(strs.begin(), strs.end());
        for(int i = 0; i < strs[0].length(); i ++)
        {
            for(int j = 1; j < strs.size(); j++)
            {
               if(strs[j][i] != strs[j - 1][i])
               {
                   string ans(vec.begin(), vec.end());
                   return ans;
               }
            }
            vec.push_back(strs[0][i]);
        }
        string ans(vec.begin(), vec.end());
        return ans;;  
    }
};