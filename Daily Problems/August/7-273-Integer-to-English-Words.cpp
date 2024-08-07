class Solution {
public:
    string helper(int num){ 
        vector<string>digits = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string>tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> teen = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    string res="";
    if(num >= 100){
        res += digits[num/100] + " Hundred ";
    }
    num %= 100;
    if(num >= 20){
        res+= tens[num/10];
        string ind ="";
        if(tens[num/10] != "")ind=" ";

        num %= 10;
        if(num > 0){
            res += ind + digits[num];
        }
    }
    else if(num <20 && num >= 10){
        res += teen[num%10];
    }
    else{
        res += digits[num];
    }
    res.erase(res.find_last_not_of(" \n\r\t")+1);
    return trimLeadingWhitespace(res);
    }

    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string bigger[] = {"", "Thousand", "Million", "Billion"};
        string res="";
        for(int i =0; i<4 && num >0; i++){
            string temp = helper(num%1000) + " " + bigger[i];
            temp.erase(temp.find_last_not_of(" \n\r\t")+1);
            temp = trimLeadingWhitespace(temp);
            if(temp == bigger[i]) temp="";
            res = (temp + " " + res);
            num /= 1000;
            res.erase(res.find_last_not_of(" \n\r\t")+1);
            res = trimLeadingWhitespace(res);
        }
        return trimLeadingWhitespace(res);
    }
    std::string trimLeadingWhitespace(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    return (start == std::string::npos) ? "" : str.substr(start);
}
};