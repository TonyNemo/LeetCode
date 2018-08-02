// beats 10%
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0;
        int length = 0;
        map<char, int> mymap;
        
        for(int i=0; i<s.length(); i++){
            if(mymap.find(s[i]) == mymap.end()){//if s[i] not in map, put s[i] in map, store its index and length goes up.
                mymap[s[i]] = i;
                length++;
            }
            else{//if s[i] in map, updates maxlength, restart counting.
                if(maxlength < length){
                    maxlength = length;
                }
                vector<char> v;
                for(map<char,int>::iterator iter = mymap.begin(); iter!=mymap.end(); iter++){
                    if(iter->second < mymap[s[i]]){
                        v.push_back(iter->first);
                    }
                }
                for(int k=0;k<v.size();k++){
                    mymap.erase(v[k]);
                }
                length = i - mymap[s[i]];
                mymap[s[i]] = i;
            }
        }
        if(maxlength < length){
            maxlength = length;
        }
        
        return maxlength;
    }
};