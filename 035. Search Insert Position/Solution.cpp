class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0;
        while (index < nums.size()) {
            if (nums[index] < target) {
                index++;
            } else {
                return index;
            }
        }
        return index;
    }
};
// binary search 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        if (target <= nums[l]) return l;
        if (target >= nums[r]) return r;
        
        while (l<=r) {
        	int mid = l + (r-l)/2;
        	
        	if (nums[mid] < target) {
        		l = mid + 1;
			} else {
				r = mid - 1;
			}
        }
        return l;
    }
};


//fastest and my first attempt.
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(target <= nums[i]) return i;
        }
        return nums.size();
    }
};