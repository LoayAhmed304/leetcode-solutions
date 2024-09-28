class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<int, vector<string>>mp;
        for(int i = 0; i<list1.size(); i++){
            string str = list1[i];
            for(int j =0; j<list2.size(); j++){
                if (list2[j] == list1[i]){
                    mp[j+i].push_back(list2[j]);
                }
            }
        }
        int minimum = INT_MAX;
        for(auto& m: mp){
            minimum = min(minimum, m.first);
        }
        return mp[minimum];
    }
};
