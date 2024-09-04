class Solution {
public:
    void advance(vector<int>& pos, unordered_map<int, int>& obs, int cmd, int i, int n){
        for(int j = 0; j < cmd; j++){
            if(n == 1)
                pos[i] += 1;
            else
                pos[i]--;

            // Check if the new position is an obstacle: undo
            long long hash = (static_cast<long long>(pos[0])  + 30000) * 60001 + pos[1] + 30000;
            if(obs.count(hash)) {
                if(n == 1)
                    pos[i] -= 1;
                else
                    pos[i]++;
                break;
            }
        }
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, int> obs;
        for(auto obstacle : obstacles){
            long long hash = (static_cast<long long>(obstacle[0])  + 30000) * 60001 + obstacle[1] + 30000;
            obs[hash]++;
        }

        int index = 0;
        vector<int> currentState = {0, 1, 2, 3}; // 0-up, 1-right, 2-down, 3-left
        vector<int> position = {0, 0};
        int maxSquared = 0;

        for(auto cmd : commands){
            if(cmd == -1) 
                index = (index + 1) % 4; // Turn right
            else if(cmd == -2) 
                index = (index + 3) % 4; // Turn left
            else{
                if(currentState[index] == 0) 
                    advance(position, obs, cmd, 1, 1); // Move up
                else if(currentState[index] == 1) 
                    advance(position, obs, cmd, 0, 1); // Move right
                else if(currentState[index] == 2) 
                    advance(position, obs, cmd, 1, 0); // Move down
                else 
                    advance(position, obs, cmd, 0, 0); // Move left
            }
            maxSquared = max(maxSquared, position[0] * position[0] + position[1] * position[1]);
        }
        return maxSquared;
    }
};
