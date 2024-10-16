class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
    priority_queue<pair<int, char>>pq;
    pq.push({a-1, 'a'});
    pq.push({b-1, 'b'});
    pq.push({c-1, 'c'});
    string res = "";
    int i = 0;

    while(pq.top().first >=0){
        pair<int, char> let = pq.top();
        if(i >= 2 && res[i-1] == let.second && res[i-2] == let.second){
            pq.pop();
            if(pq.top().first < 0) break;
            pair<int, char> new_let = pq.top();
             
            pq.pop();
            res += new_let.second;
            new_let.first -= 1;
            pq.push(new_let);
            pq.push(let);
        }
        else{
            pq.pop();
            res += let.second;
            let.first -= 1;
            pq.push(let);
        }
        i++;
    }
    return res;
    }
};
