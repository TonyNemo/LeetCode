// Runtime: 1196 ms, faster than 5.78% of C++ online submissions for Container With Most Water.
// brute force 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = height.size();
        int maxV=0;
        for(int i=0; i<l; i++){
            for(int j=0; j<l; j++){
                int V = min(height[i], height[j]) * (j-i);
                if(V>maxV){
                    maxV = V;
                }
            }
        }
        return maxV;
    }
};

// Runtime: 20 ms, faster than 48.88% of C++ online submissions for Container With Most Water.
// twp-pointer approach, move the shorter one.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int maxV = 0;
		while(i<=j){
			int V = min(height[i], height[j]) * (j-i);
			maxV = max(maxV, V);
			
			if(height[i]<=height[j]){
				i++;
			}else j--;
			
		}
		return maxV;
    }
};


