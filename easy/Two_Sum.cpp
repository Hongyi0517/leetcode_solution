// 1.Two_Sum
//Hash 解法
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution{
    public:
        vector<int> twoSum (vector<int>& nums, int target){
            unordered_map<int,int> mp;
            for(int i = 0; i < nums.size(); i++){
                int need = target - nums[i];
                if(mp.count(need)){
                    return {mp[need],i};
                }
                mp[nums[i]] = i;
            }
            return {};
        }
};

int main(){
    Solution solution;
    vector<int> nums = {2,5,18,64,98};
    int target = 82;
    vector<int> result = solution.twoSum(nums,target);
    
    if(result.empty()){
        cout << "No answer find." << endl;
    }else{
        cout << "answer:[" << result[0] << "," << result[1] <<"]" << endl;
    }
    
    cin.get();
    return 0;
}
//暴力解法
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution{
    public:
        vector<int> twoSum (vector<int>& nums, int target) {
            for (int i = 0; i < nums.size(); i++) {
                for(int j = i+1; j < nums.size(); j++){
                    if (nums[i] + nums[j] == target) {
                        return {i,j};
                    }
                }
            }
            return{};
        }
};

int main(){
    Solution solution;
    vector<int> nums = {2,5,18,64,98};
    int target = 82;
    vector<int> result = solution.twoSum(nums,target);
    
    if(result.empty()){
        cout << "No answer find." << endl;
    }else{
        cout << "answer:[" << result[0] << "," << result[1] <<"]" << endl;
    }
    
    cin.get();
    return 0;
}
*/