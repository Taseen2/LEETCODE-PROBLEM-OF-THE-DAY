class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int,int> freq; //create a hash map 
        for(int num : nums) // loop through every number, inc its freq count in map
            freq[num]++;

        int maxFreq = 0;
        for(auto& it : freq)
            maxFreq = max(maxFreq,it.second); // to find max value in loop 
        
        // add freq
        int total = 0;
        for(auto &it :freq){
            if(it.second == maxFreq)
                total += it.second;
        }
        return total;
    }
};