/*

Lab 7 - Post Fix

11/03/24

@ AJ Enrique Arguello 

Objectives: Using Stacks, create a program to evaluate postfix algebra (and display the result)

*/

#include <iostream>
#include <string>
#include <stack>
#include <cctype>  // For isdigit()

using namespace std;

int postFixEvaluation(const string &expression);  // user input expression is passed through

int main() {
    string expression;

    cout << "Please enter a postfix expression: ";  
    cin >> expression;

    int result = postFixEvaluation(expression);

    if (result != -1) {  // only prints result if there's no error
        cout << "Result: " << result << endl;
    }

    return 0;
}

int postFixEvaluation(const string &expression) {  
    stack<int> expressionStack;

   
    for (int i = 0; i < expression.length(); ++i) { // iterate through the expression 
        char chctr = expression[i];

        // if the character is a digit, push it to the stack
        if (isdigit(chctr)) {
            expressionStack.push(chctr - '0');  // convert char to int and push
        } else {
            // makes sure there are at least two numbers to perform the operation
            if (expressionStack.size() < 2) {
                cout << "Error: Invalid postfix expression!" << endl;
                return -1;
            }

            // pop two operands
            int b = expressionStack.top();  // b is the second operand
            expressionStack.pop();

            int a = expressionStack.top();  // a is the first operand
            expressionStack.pop();

            // apply switch statement based on operator
            switch (chctr) {
                case '+': 
                    expressionStack.push(a + b);  // add
                    break;
                case '-':
                    expressionStack.push(a - b);  // subtract
                    break;
                case '*':
                    expressionStack.push(a * b);  // mulitply
                    break;
                case '/':
                    if (b == 0) {
                        cout << "Error: Division by zero!" << endl;
                        return -1;
                    }
                    expressionStack.push(a / b);  //  divide
                    break;
                default:
                    cout << "Error: Invalid operator!" << endl;
                    return -1;  // Return -1 for invalid operator
            }
        }
    }

    // the result should be the only item left in the stack
    if (expressionStack.size() != 1) {
        cout << "Error: Invalid postfix expression!" << endl;
        return -1;
    }

    return expressionStack.top();  // return the result 
}

