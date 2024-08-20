class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>uglies(n+1);
        uglies[1] = 1;
        int second=1, third=1, fifth=1;
        
        for(int i = 2; i<=n; i++){
            int secondM = uglies[second]*2;
            int thirdM = uglies[third]*3;
            int fifthM = uglies[fifth]*5;

            uglies[i] = min(secondM, min(thirdM, fifthM));
            
            second += secondM == uglies[i]?1:0;
            third += thirdM == uglies[i]?1:0;
            fifth += fifthM == uglies[i]?1:0;
        }

        return uglies[n];
    }
};
