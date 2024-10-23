#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    char solve(char op, vector<char> &val)
    {

        switch (op)
        {
        case '!':
            return val[0] == 't' ? 'f' : 't';

        case '|':
            return any_of(begin(val), end(val), [](char ch)
                          { return ch == 't'; })
                       ? 't'
                       : 'f';

        case '&':
            return any_of(begin(val), end(val), [](char ch)
                          { return ch == 'f'; })
                       ? 'f'
                       : 't';
        }

        return 't';
    }

public:
    bool parseBoolExpr(string expression)
    {
        stack<char> stk;
        int size_ = expression.size();
        for (int i = 0; i < size_; i++)
        {
            if (expression[i] == ',')
                continue;

            if (expression[i] != ')')
            {
                stk.push(expression[i]);
            }
            else
            {

                vector<char> values;
                while (stk.top() != '(')
                {
                    char val = stk.top();
                    stk.pop();
                    values.push_back(val);
                }
                stk.pop();
                char op = stk.top();
                char eval = solve(op, values);

                stk.push(eval);
            }
        }

        return stk.top() == 't' ? true : false;
    }
}; /*
 1106. Parsing A Boolean Expression
 Solved
 Hard
 Topics
 Companies
 Hint
 A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

 't' that evaluates to true.
 'f' that evaluates to false.
 '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
 '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
 '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
 Given a string expression that represents a boolean expression, return the evaluation of that expression.

 It is guaranteed that the given expression is valid and follows the given rules.



 Example 1:

 Input: expression = "&(|(f))"
 Output: false
 Explanation:
 First, evaluate |(f) --> f. The expression is now "&(f)".
 Then, evaluate &(f) --> f. The expression is now "f".
 Finally, return false.
 Example 2:

 Input: expression = "|(f,f,f,t)"
 Output: true
 Explanation: The evaluation of (false OR false OR false OR true) is true.
 Example 3:

 Input: expression = "!(&(f,t))"
 Output: true
 Explanation:
 First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
 Then, evaluate !(f) --> NOT false --> true. We return true.


 Constraints:

 1 <= expression.length <= 2 * 104
 expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.
 */
