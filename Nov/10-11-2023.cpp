// Problem Link:  https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1


// Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. Digits from 1-9 and digits can't repeat.



class Solution{   
public:
    string printMinNumberForPattern(string S){
        stack<int> s;
        string ans = "";
        for(int i =0; i<=S.length(); i++){
            if(S[i] == 'D'){
                s.push(i+1);
            }
            else{
                s.push(i+1);
                while(!s.empty()){
                    string top = to_string(s.top());
                    ans = ans+top;
                    s.pop();
                }
            }
        }
        return ans;
    }
};
