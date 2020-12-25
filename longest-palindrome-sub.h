#include <iostream>
#include <stdio.h>

using namespace std;
//medium 
//https://leetcode.com/problems/longest-palindromic-substring/


class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() < 1)
        {
            cout << "enter" << endl;
            return "";
        }
  
        
        int start = 0;
        int end = 0;

        for(int i = 0 ;i < s.length(); i++)
        {
            int len1 = countfrommiddle(s, i, i);
            int len2 = countfrommiddle(s, i , i+1);
            int len = max(len1,len2);
            if(len > end - start)
            {
                start = i - (len - 1)/2;
                end = i + len / 2;
                //cout << start << " " << end << endl;
            }
        }
        cout << start << " " << end << endl;
        return s.substr(start, end - start + 1);
    }

    int countfrommiddle(string s, int left, int right)
    {
        if(left > right)
            return 0;
        while(left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

//abba
//bracecar