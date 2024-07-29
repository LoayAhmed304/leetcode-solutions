class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count =0;
        int n = rating.size();
        for(int i =0; i<n-1; i++)
        {
            for(int j = i+1; j<n-1; j++){
                if(rating[j] > rating[i])
                {
                    for(int x=j+1; x< n; x++)
                    {
                        if(rating[x] > rating[j]) count++;
                    }
                }else if(rating[j]< rating[i])
                {
                    for(int x = j+1; x<n; x++)
                    {
                        if(rating[x] < rating[j]) count++;
                    }
                }
            }
        }
        return count;
    }
};