//Valid Parentheses
#include <stack>

class Solution{
public:
	bool isValid(string s){
		stack<char> ch;
		for (int i=0; i<s.length(); i++)
			switch (s[i]){
				case '(':
				case '[':
				case '{': ch.push(s[i]);break;
				case ')':
					if (ch.empty() || (ch.top()!='(')) 
						return false;
					else 
						ch.pop();
						break;
				case ']':
					if (ch.empty() || (ch.top()!='[')) 
						return false;
					else 
						ch.pop();
						break;
				case '}': 
					if (ch.empty() || (ch.top()!='{')) 
						return false;
					else 
						ch.pop();
						break;

			}
		return ch.empty();

	}
};