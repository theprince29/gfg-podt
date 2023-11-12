// Problem Link: https://www.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1
// Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating (in any direction) string 'a' by exactly 2 places.

class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
   bool isRotated(string str1, string str2)
    {
        int n = str1.size(), m = str2.size();
        if(n!=m) return 0;
        string s1 = str1.substr(2,n-2)+str1.substr(0,2); 
        string s2 = str1.substr(n-2,2)+str1.substr(0,n-2);
        return str2==s1||str2==s2;
    }

};
