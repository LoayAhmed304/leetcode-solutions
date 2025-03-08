class Solution {
public:
    vector<bool> prime;
    void SieveOfEratosthenes(int n){
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.

  for (int p = 2; p * p <= n; p++) {


        if (prime[p] == true) {
            
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // // Print all prime numbers
    // for (int p = 2; p <= n; p++)
    //     if (prime[p])
    //         cout << p << " ";
  }
    vector<int> closestPrimes(int left, int right) {
        prime.assign(right + 1, true);
        SieveOfEratosthenes(right);
        vector<int>res;
        int cur = left;
        if(cur == 1) cur ++;
        while(cur <= right){
            if(prime[cur]) res.push_back(cur);
            cur++;
        }
        if(res.size() <= 1) return {-1, -1};
        
        int l = 0, r = 1;
        int finalLeft = res[0], finalRight = res[1];
        while(r < res.size()){
            if(res[r] - res[l] < finalRight - finalLeft){
                finalLeft = res[l];
                finalRight = res[r];
            }
            l++;
            r++;
        }
        return {finalLeft, finalRight};
    }
};
