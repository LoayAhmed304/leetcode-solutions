class Solution {
public:
    int minimumDeletions(string s) {
        int bCount=0;
        int aCount=0;
        int res=0;
        int n = s.size();
        for(int i =0; i<n; i++){
            if(s[i] == 'b'){
                bCount++;
            }
            if(s[i] == 'a'){
                if(bCount>0){
                    res++;
                    bCount--;
                }
                aCount++;
            }
        }
        return res;
    }
};