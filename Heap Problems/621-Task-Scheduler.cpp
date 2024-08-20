class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        priority_queue<int>maxHeap;
        
        unordered_map<char, int>mp;
        for(char& task: tasks){
            mp[task]++;
        }
        for(auto &entry: mp){
            maxHeap.push(entry.second);
        }
        queue<pair<int,int>>q;
        int time = 0;

        while(!q.empty() || !maxHeap.empty()){
            if(!q.empty() && time >= q.front().second){
                maxHeap.push(q.front().first);
                q.pop();
            }

            if(!maxHeap.empty()){
                int current = maxHeap.top()-1;
                maxHeap.pop();
                if(current > 0)
                    q.push({current, time + n + 1});
            }
            time++;
        }
        
        return time;
    }       
};
