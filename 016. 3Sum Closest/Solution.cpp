class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        
		sort(nums.begin(), nums.end()); 
        
        for (int i=0; i<nums.size()-2; i++){
        	if (i>0 && nums[i]==nums[i-1]) continue;
			int h=i+1, t=nums.size()-1;

			while (h<t) {
				int sum = nums[i] + nums[h] + nums[t];
				if (sum - target == 0) return sum;
				if (abs(target - sum) < abs(target - closest)) {
					closest = sum;
				}
				if (sum > target) {
					t--;
				} else {
					h++;
				}
			}
		}
		
		return closest;
		 
    }
};