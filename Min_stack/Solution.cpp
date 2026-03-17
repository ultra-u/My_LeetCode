#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> minStack;
public:
    MinStack(){

    }
    void push(int x) {
        if (s.empty()) {
            s.push(x);
            minStack.push(x);
        } else {
            s.push(x);
            if (x < minStack.top()) {
                minStack.push(x);
            } else {
                minStack.push(minStack.top());
            }
        }
    }
    void pop() {
        s.pop();
        minStack.pop();
    }
    int top(){
        return s.top();
    }
    int getMin() {
        return minStack.top();
    }
};

int main(){
    string line;
    cout<<"Enter commands (push x, pop, top, getMin): " << endl;
    getline(cin, line);
    vector<string> operations;
    stringstream ss(line);
    string op;
    while (ss >> op) {
        if (op.front() == '"' || op.front() == '\'') {
            op = op.substr(1, op.length() - 2);
        }
        if (op.back() == ',') {
            op.pop_back();
        }
        operations.push_back(op);
    }
    cout << "Params: " << endl;
    getline(cin, line);
    vector<vector<int>> params;
    stringstream ssParams(line);
    string param;
    while (ssParams >> param) {
        if (param.front() == '"' || param.front() == '\'') {
            param = param.substr(1, param.length() - 2);
        }
        if (param.back() == ',') {
            param.pop_back();
        }
        vector<int> paramVec;
        stringstream ssParam(param);
        int num;
        while (ssParam >> num) {
            paramVec.push_back(num);
        }
        params.push_back(paramVec);
    }
    cout << "Params: " << endl;
    for (const auto& paramVec : params) {
        cout << "[";
        for (size_t i = 0; i < paramVec.size(); ++i) {
            cout << paramVec[i];
            if (i < paramVec.size() - 1) {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
    MinStack minStack;
    for (size_t i = 0; i < operations.size(); ++i) {
        const string& operation = operations[i];
        const vector<int>& paramVec = params[i];
        if (operation == "push") {
            minStack.push(paramVec[0]);
        } else if (operation == "pop") {
            minStack.pop();
        } else if (operation == "top") {
            cout << "Top: " << minStack.top() << endl;
        } else if (operation == "getMin") {
            cout << "Min: " << minStack.getMin() << endl;
        }
    }
}