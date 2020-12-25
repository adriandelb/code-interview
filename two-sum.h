#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

//easy
//https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>numMap;
        vector<int>solution;
        
        for(int i = 0; i < nums.size(); i++)
        {
          numMap[nums[i]] = i;
        }
         for(int i = 0; i < nums.size(); i++)
        {
             int numfind = target - nums[i];
             auto search = numMap.find(numfind);
             if(search != numMap.end())
             {
                 if(numMap[numfind] != i)
                 {
                    solution.push_back(i);
                    solution.push_back(numMap[numfind]);
                    break;
                 }
             }
         }
         return solution;
    }
};