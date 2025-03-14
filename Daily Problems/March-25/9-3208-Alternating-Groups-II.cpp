// [0, 0, 1, 1, 1, 0, 1], k = 3
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int l = 0, r = k - 1;
        int res = 0;
        bool found = false;
        for(int i = 0; i < k - 1; i++){
            colors.push_back(colors[i]);
        }
        int n = colors.size();
        int i = 1;
        l = 0;
        r = 1;

        while(r < n){
            if(colors[r] == colors[r - 1]){
                l = r;
                r++;
            }else{
                r++;
                if(r - l < k) continue;
                res++;
                l++;
            }
        }
        return res;
    }
};
