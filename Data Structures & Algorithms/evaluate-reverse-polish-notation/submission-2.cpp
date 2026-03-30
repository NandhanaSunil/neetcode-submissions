class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res;
        res = stoi(tokens[0]);
        stack <int> num;
        num.push(res);
        for (int i=1; i<tokens.size(); i++){
            string s = tokens[i];
            // cout << s << endl;
            if (isdigit(s[0]) || (s.size()>1 && isdigit(s[1]))) {
                num.push(stoi(s));
            }
            else{
                int num1 = num.top();
                num.pop();
                int num2 = num.top();
                num.pop();
                switch(s[0]){
                    case '+' : res = num2 + num1; break;
                    case '-' : res = num2 - num1; break;
                    case '*' : res = num2* num1; break;
                    case '/' : res = num2 / num1; break;
                }
                num.push(res);
            }
        }
        return num.top();
    }
};
