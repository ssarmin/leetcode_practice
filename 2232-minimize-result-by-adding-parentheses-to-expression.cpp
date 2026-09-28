//https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression
class Solution {
public:
    string minimizeResult(string expression) {
        istringstream ss(expression);
        char delim = '+';
        vector<string> num;
        string word;
        while (getline (ss, word, delim)) {
            num.push_back(word);
        }
        int res = stoi(num[0]) + stoi(num[1]);
        unordered_map<int, string> m;
        m[res] = "(" + num[0] + "+" + num[1] + ")";

        for(int i=0; i<num[0].size(); i++){
            string n1_1 = "1";
            string n1_2 = num[0];
            if(i != 0){
                n1_1 = num[0].substr(0, i);
                n1_2 = num[0].substr(i);
            }
            int num1_1 = stoi(n1_1);
            int num1_2 = stoi(n1_2);

            for(int j=num[1].size()-1; j>=0; j--){
                string n2_1 = num[1];
                string n2_2 = "1";
                if(j < num[1].size()-1){
                    n2_1 = num[1].substr(0, j+1);
                    n2_2 = num[1].substr(j+1);
                }
                int num2_1 = stoi(n2_1);
                int num2_2 = stoi(n2_2);
                int val = num1_1 * (num1_2 + num2_1) * num2_2;

                // cout << n1_1 << " " << n1_2 << "+" << n2_1 << " " << n2_2 << endl;                
                if(res > val){
                    res = val;
                    string temp = "";
                    if(i != 0){
                        temp = n1_1;
                    }
                    temp += "(" + n1_2 + "+" + n2_1 + ")";
                    if(j < num[1].size()-1){
                        temp += n2_2;
                    }
                    // cout << res << " " << temp << endl;
                    m[res] = temp;
                }
            }
        }
        return m[res];
    }
};

/*
"247+38"
"12+34"
"999+999"
"1+1"
"9+9"
"1+23"
"12+3"
"99+99"
*/
