#include <stack>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
stack<char> s;
queue<char> q;

public:
	void pushCharacter(char c){
		s.push(c);
	}
	void enqueueCharacter(char c){
		q.push(c);
	}
	char popCharacter(){
		char c = s.top();
		s.pop();
		return c;
	}
	char dequeueCharacter(){
		char c = q.front();
		q.pop();
		return c;
	}
};

int main(){
    string s;
    getline(cin, s);
    
    Solution obj;
    for (size_t i = 0; i < s.length(); i++){
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    for (size_t i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            break;
        }
    }
    
    if (isPalindrome)
        cout << "The word, " << s << ", is a palindrome.";
    else
        cout << "The word, " << s << ", is not a palindrome.";
    return 0;
}
