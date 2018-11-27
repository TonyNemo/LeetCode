#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void printVector(vector<int> & v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void printNestedVector(vector<vector<int> > & v){
	for(int i=0;i<v.size();i++){
		printVector(v[i]);
	}
}
// Time Limit Exceeded
//class Solution {
//public:
//    vector<vector<int> > threeSum(vector<int>& nums) {
//        vector<vector<int> > V;
//		
//		int l = nums.size();
//        for(int i=0; i<l-2; i++){
//        	for(int j=i+1; j<l-1; j++){
//        		for(int k=j+1; k<l; k++){
//        			if(nums[i]+nums[j]+nums[k]==0){
//        				vector<int> v;
//        				v.push_back(nums[i]);
//        				v.push_back(nums[j]);
//        				v.push_back(nums[k]);
//        				sort(v.begin(), v.end());
////        				printVector(v);
//        				if(find(V.begin(), V.end(), v) == V.end()){
//							V.push_back(v);	
//						}
//        			}
//				}
//			}
//		}
//		return V;
//    }
//};

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
		
		sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
        	if (i>0 && nums[i]==nums[i-1]) continue;
			int h=i+1, t=nums.size()-1;
        	while(h<t){
        		int sum = nums[i] + nums[h] + nums[t];
        		if(sum > 0){
        			t--;
				}
				else if (sum < 0) {
					h++;
				}
				else {//sum==0
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[h]);
					temp.push_back(nums[t]);
					res.push_back(temp);
					while (nums[h] == nums[h+1] && h+1<t) h++;
					while (nums[t] == nums[t-1] && t-1>h) t--;
					h++;
					t--;		
				}
			}
		}
		return res;
    }
};



int main(){
	int n[] = {-1,0,1,2,-1,-4};
	vector<int> nums(n,n+6);
	printVector(nums);
	Solution s;
	vector<vector<int> > V = s.threeSum(nums);
	printNestedVector(V);
}

