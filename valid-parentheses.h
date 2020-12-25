#include <string>
#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

//easy
//https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    
    unordered_map<char,char> charmap = {
        {'}','{'},
        {')','('},
        {']','['}
    };

    stack<char>charstack;

    bool isValid(string s) {
       for(int i = 0; i < s.length();i++)
       {
           char input = s[i];
           if(charmap.count(input))
           {
               char stacktop = charstack.empty() ? '#' : charstack.top();
                if(stacktop != charmap[s[i]])
                {
                    return false;
                }
                charstack.pop();
           }
           else
           {
               charstack.push(s[i]);
           }
       }  
    return charstack.empty();
    }
};