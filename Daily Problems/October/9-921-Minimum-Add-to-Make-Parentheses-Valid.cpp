class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int opened = 0;

        for(char& br: s){
            if(br == '(') st.push(br);
            else{
                if(!st.empty()){
                    st.pop();
                    continue;
                }else{
                    opened++;
                }
            }
        }
        if(opened)
            return opened + st.size();
        return st.size();
    }
};
