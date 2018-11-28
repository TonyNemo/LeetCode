class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
    	vector<vector<int> > res;
		if (nums.size()<4) return res;
		sort(nums.begin(), nums.end());
		
		for (int j=0; j<nums.size()-3; j++){
			if (j>1 && nums[j]==nums[j-1]) continue;
	        for (int i=j+1; i<nums.size()-2; i++){
	        	if (i>j+1 && nums[i]==nums[i-1]) continue;
				int h=i+1, t=nums.size()-1;
	        	while(h<t){
	        		int sum = nums[i] + nums[h] + nums[t];
	        		if(sum > target-nums[j]){
	        			t--;
					}
					else if (sum < target-nums[j]) {
						h++;
					}
					else {//sum==target-nums[j]
						vector<int> temp;
						temp.push_back(nums[j]);
						temp.push_back(nums[i]);
						temp.push_back(nums[h]);
						temp.push_back(nums[t]);
						sort(temp.begin(), temp.end());
						if (find(res.begin(), res.end(), temp) == res.end()) res.push_back(temp);
						while (nums[h] == nums[h+1] && h+1<t) h++;
						while (nums[t] == nums[t-1] && t-1>h) t--;
						h++;
						t--;		
					}
				}
			}
		}
		return res;
	}
};