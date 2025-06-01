#include <iostream>
#include <stack>
#include <map>

using namespace std;

bool isValid(string s)
{
    map<char, char> parentheses{{')', '('}, {']', '['}, {'}', '{'}};
    stack<char> st;

    for (char c : s)
    {
        if (parentheses.count(c))
        {
            if (st.empty() || st.top() != parentheses[c])
                return false;
            st.pop();
        }
        else
        {
            st.push(c);
        }
    }

    return st.empty();
}

int main()
{
    bool is_valid = isValid("((()))");
    cout << "((())) is valid = " << is_valid << endl;
    // cout << "((()}) is valid = " << isValid("((()))") << endl;
}