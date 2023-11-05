// Date : 05-11-2023
// Problem Link: https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1


// Given a non-empty array nums[] of integers of length N, find the top k elements which have the highest frequency in the array. If two numbers have same frequencies, then the larger number should be given more preference.

class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        
        map<int, int >freq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto x: freq){
            pq.push(make_pair(x.second, x.first));
        }
        while(k--){
            auto x = pq.top();
            pq.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
    
};
