
//Approach 1: Backtracking time exceeded.
class Solution {
public:
    bool canJumpFromPosition(vector<int>& nums, int from) {
        if (from + nums[from] >= nums.size()-1) {
            return true;
        }
        for (int i = from+nums[from]; i>from; i--) {
            if (canJumpFromPosition(nums, i)) {
                return true;
            }
        }
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        return canJumpFromPosition(nums, 0);
    }
};

// Approach 3: Dynamic Programming Bottom-up
// Top-down to bottom-up conversion is done by eliminating recursion. 
// In practice, this achieves better performance as we no longer have the method stack 
// overhead and might even benefit from some caching. More importantly, this step opens up 
// possibilities for future optimization. The recursion is usually eliminated by trying to reverse 
// the order of the steps from the top-down approach.

// The observation to make here is that we only ever jump to the right. 
// This means that if we start from the right of the array, every time we will query a 
// position to our right, that position has already be determined as being GOOD or BAD. 
// This means we don't need to recurse anymore, as we will always hit the memo table.
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(), 0);
        memo[nums.size()-1] = 1;
        
        for (int i = nums.size()-2; i>=0; i--) {
            for (int j = i+1; j<=min(i+nums[i], int(nums.size()-1)); j++) {
                if (memo[j] == 1) {
                    memo[i] = 1;
                    break;
                }
            }
        }
        
        return memo[0] == 1;
    }
Approach 4: Greedy
Once we have our code in the bottom-up state, we can make one final, important observation. From a given position, when we try to see if we can jump to a GOOD position, we only ever use one - the first one (see the break statement). In other words, the left-most one. If we keep track of this left-most GOOD position as a separate variable, we can avoid searching for it in the array. Not only that, but we can stop using the array altogether.

Iterating right-to-left, for each position we check if there is a potential jump that reaches a GOOD index (currPosition + nums[currPosition] >= leftmostGoodIndex). If we can reach a GOOD index, then our position is itself GOOD. Also, this new GOOD position will be the new leftmost GOOD index. Iteration continues until the beginning of the array. If first position is a GOOD index then we can reach the last index from the first position.

To illustrate this scenario, we will use the diagram below, for input array nums = [9, 4, 2, 1, 0, 2, 0]. We write G for GOOD, B for BAD and U for UNKNOWN. Let us assume we have iterated all the way to position 0 and we need to decide if index 0 is GOOD. Since index 1 was determined to be GOOD, it is enough to jump there and then be sure we can eventually reach index 6. It does not matter that nums[0] is big enough to jump all the way to the last index. All we need is one way.
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size()-1;
        for (int i = nums.size()-1; i>=0; i--) {
            if (i+nums[i]>=lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }