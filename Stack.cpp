
#include <iostream>
using namespace std;
class Stack {
protected:
    static const int SIZE = 3;
    int top;
    int st[SIZE];
public:
    Stack() { top = -1; };
    void push(int num) { st[++top] = num; }
    int pop() { return st[top--]; }
};
class Safe_Stack :protected Stack {
public:
    void push(int num) {
        if (top >= SIZE) { cout << "Stack is overflowed." << endl; }
        else Stack::push(num);
    }
    int pop() {
        if (top < 0) { cout << "Stack is empty." << endl; return 1111; }
        else Stack::pop();
    }
};

int main()
{
	
}