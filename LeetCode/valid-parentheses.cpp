class Solution
{
public:
    bool isValid(string s)
    {

        stack<char> myStack;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                myStack.push(s[i]);
            else
            {
                if (myStack.size() > 0)
                {

                    if (
                        (s[i] == ')' && myStack.top() == '(') ||
                        (s[i] == '}' && myStack.top() == '{') ||
                        (s[i] == ']' && myStack.top() == '['))
                        myStack.pop();
                    else
                        myStack.push(s[i]);
                }
                else
                {
                    return false;
                }
            }
        }

        if (myStack.size() == 0)
            return true;
        else
            return false;
    }
};