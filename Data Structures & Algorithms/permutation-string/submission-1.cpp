class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int m = s2.length();
        int k = s1.length();

        unordered_map<char,int>mp;

        for(int i=0; i<k; i++){
            mp[s1[i]]++;
        }

        int i=0,j=0;
        int count = mp.size();

        while(j<m){

            if(mp.find(s2[j]) != mp.end()){
                mp[s2[j]]--;
                if(mp[s2[j]] == 0) count--;
            }

            if(j-i+1 < k) j++;

            else if(j-i+1 == k){
                if(count == 0) return true;

                if(mp.find(s2[i]) != mp.end()){
                    if(mp[s2[i]] == 0) count++;
                    mp[s2[i]]++;
                }

                i++;
                j++;
            }
        }

        return false;
    }
};
