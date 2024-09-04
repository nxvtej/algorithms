#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string ss)
    {

        if (ss.length() < 2)
            return false;

        stack<char> s;
        if (ss[0] == ')' || ss[0] == ']' || ss[0] == '}')
            return false;

        for (auto it : ss)
        {                  // [
            if (it == '(') // s
                s.push(')');
            else if (it == '[')
                s.push(']'); // S ]
            else if (it == '{')
                s.push('}');

            else if (s.empty())
                return false;

            else
            {
                if (it == s.top())
                    s.pop(); // poped

                else
                    return false;
            }
        }

        return s.empty();
    }
};

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid
An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/