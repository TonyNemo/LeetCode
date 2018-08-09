// DP time O(n^2) space O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2) return s;
        
        int length = s.length();
        bool table[length][length];
        memset(table, 0, sizeof(table));
        
        int maxlength = 1;
        int start = 0;
        for(int i=0;i<length;i++){
            table[i][i]=1;
            if(i+1<length && s[i]==s[i+1]){
                table[i][i+1] = 1;
                start = i;
                maxlength = 2;
            }
        }
        
        // k is the length of the substring
        for(int k=3; k<=length; k++){
            // starting index
            for(int i=0; i<length-k+1;i++){
                // ending index
                int j = i+k-1;
                
                if(table[i+1][j-1]==1 && s[i]==s[j]){
                    table[i][j]=1;
                    
                    if(k>maxlength){
                        start = i;
                        maxlength=k;
                    }
                }
            }
        }
        
        return s.substr(start, maxlength);
    }
};