class Solution {
public:
    char OR(vector<char>signs){
        for(char & sign: signs){
            if (sign == 't')
                return 't';
        }
        return 'f';
    }

    char AND(vector<char>signs){
        for(char & sign: signs){
            if (sign == 'f')
                return 'f';
        }
        return 't';
    }

    char NOT(vector<char>signs){
        return signs[0] == 't' ? 'f' : 't';
    }

    bool parseBoolExpr(string expression) {
        stack<char>op;
        stack<vector<char>>chars;

        for(int i = 0; i < expression.size(); i++){
            int x =0;
            if (expression[i] == '&' || expression[i] == '|' || expression[i] == '!')
                op.push(expression[i]);
            
            else if(expression[i] == 't' || expression[i] == 'f')
                chars.top().push_back(expression[i]);

            else if(expression[i] == '(')
                chars.push(vector<char>());

            else if(expression[i] == ')'){
                char option = op.top();
                op.pop();
                vector<char>signs = chars.top();
                chars.pop();
                char res;
                if(option == '|')
                    res = OR(signs);
                else if (option == '&')
                    res = AND(signs);
                else
                    res = NOT(signs);
                if(!chars.empty())
                    chars.top().push_back(res);
                else
                    chars.push({res});
            }
        }
        
        return chars.top()[0] == 't' ? true : false;
    }
};
