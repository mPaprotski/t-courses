#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    
    stringstream ss(input);
    string token;
    stack<long long> s;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*") {
            long long b = s.top(); s.pop();
            long long a = s.top(); s.pop();

            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
        } else {
            s.push(stoll(token));
        }
    }

    cout << s.top() << endl;

    return 0;
}