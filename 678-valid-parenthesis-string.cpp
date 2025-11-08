//https://leetcode.com/problems/valid-parenthesis-string
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stack_par;
        stack<int> stack_star;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                stack_par.push(i);
            }else if(s[i] == '*'){
                stack_star.push(i);
            }else{
                if(!stack_par.empty()){
                    stack_par.pop();
                }else if(!stack_star.empty()){
                    stack_star.pop();
                }else{
                    return false;
                }
            }
        }
        while(!stack_par.empty() && !stack_star.empty()){
            if(stack_par.top() < stack_star.top()){
                stack_par.pop();
                stack_star.pop();
            }else{
                return false;
            }
        }
        return stack_par.empty();
    }
};


"*"
"(**(*()**()**((**(*)"
"((*)(*))()*(*)****((*(*)())*()((()**(**)"
")(*()(**(*)())*))())())*)()()*(((*)()))(**()*)**(*"
")))(*)**)))*)))))*)*(((()(((*())(***)**(**((()))()((*((()((("
"()))))**)(()*()**)))()*)()())*(*)())**()*)))(**())))()**))*)*()**((*(*"
"*(*)(*))((*)*)))(*)())*())()(()*)*)****)())(()()*(*(*())()((())))*()****)(*(()))((*()*(**(*()*)*()"
"(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"
"(((((*)))**"
