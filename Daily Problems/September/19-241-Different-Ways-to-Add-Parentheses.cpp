class Solution {
public:

    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        if (!expression.size()) return res;
        if(expression.size() == 1){
            res.push_back(stoi(expression));
            return res;
        }
        if(expression.size() == 2 && isdigit(expression[0])){
            res.push_back(stoi(expression));
            return res;
        }
        for (int i = 0; i < expression.size(); i++){
            char ch = expression[i];
            if(isdigit(ch)) continue;

            vector<int> leftResults = diffWaysToCompute(expression.substr(0,i));
            vector<int> rightResults = diffWaysToCompute(expression.substr(i+1));

            for(int leftValue: leftResults){
                for(int rightValue: rightResults){
                    int compRes = 0;
                    switch(ch){
                        case '+':
                            compRes = leftValue + rightValue;
                            break;
                        case '-':
                            compRes = leftValue - rightValue;
                            break;
                        case '*':
                            compRes = leftValue * rightValue;
                            break;
                    }
                    res.push_back(compRes);
                }
            }
        }
        return res;
    }
};
