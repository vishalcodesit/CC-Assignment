#include <iostream>
#include <stack>
using namespace std;

class MinMaxStack {
private:
    stack<int> mainStack;
    stack<int> minStack;
    stack<int> maxStack;

public:
   
    void push(int x) {
        mainStack.push(x);

       
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        } else {
            minStack.push(minStack.top());
        }

        
        if (maxStack.empty() || x >= maxStack.top()) {
            maxStack.push(x);
        } else {
            maxStack.push(maxStack.top());
        }
    }

  
    void pop() {
        if (mainStack.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        mainStack.pop();
        minStack.pop();
        maxStack.pop();
    }

    
    int top() {
        if (mainStack.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return mainStack.top();
    }

    
    int getMin() {
        if (minStack.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return minStack.top();
    }

    
    int getMax() {
        if (maxStack.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return maxStack.top();
    }
};


int main() {
    MinMaxStack s;
    s.push(10);
    s.push(20);
    s.push(5);
    s.push(30);

    cout << "Top: " << s.top() << endl;       
    cout << "Min: " << s.getMin() << endl;   
    cout << "Max: " << s.getMax() << endl;   

    s.pop();
    cout << "After pop:" << endl;
    cout << "Top: " << s.top() << endl;       
    cout << "Min: " << s.getMin() << endl;   
    cout << "Max: " << s.getMax() << endl;   

    return 0;
}
