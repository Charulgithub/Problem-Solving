class Solution {
public:
    string fractionAddition(string expr) {
        int n = expr.size();
        int num = 0;
        int deno = 1;

        int i = 0;
        while( i < n){
            int currNum = 0;
            int currDeno = 0;

            bool isNeg = (expr[i] == '-');

            if(expr[i] == '+' || expr[i] == '-'){
                i++;
            }
            
            //building curr numerator
            while( i < n && isdigit(expr[i])){
                int val = expr[i] - '0';
                currNum = (currNum * 10) + val;
                i++;
            }

            i++;  // num/deno  --->skipping the '/' char

            if(isNeg){
                currNum *= -1;
            }

            //building curr denominator
            while(i < n && isdigit(expr[i])){
                int val = expr[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            num = num * currDeno + currNum * deno;
            deno = deno * currDeno;
        }

        int GCD = abs(__gcd(num, deno));

        num /= GCD;
        deno /= GCD;

        return to_string(num) + "/" + to_string(deno);
    }
};