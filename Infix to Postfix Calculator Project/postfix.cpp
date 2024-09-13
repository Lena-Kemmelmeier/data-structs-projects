// Author: Lena Kemmelmeier
// Date: 6/17/23
// Purpose: CS 302 HW 3

#include <iostream>
#include <string>
using namespace std;

#include "arrayStack.h"
#include "linkedStack.h"

string getInfixExpression(); //get infix expression from user
string infixToPostfix(string, StackInterface<char>&); // get postfix expression from infix expression
double evaluatePostFix(string); // evaluate the postfix expression
int getOperatorPrecedence(char); //get precedence (1, 2, or 3) of an operator - lower number = higher precededence


int main(){
    LinkedStack<char> operatorStack;
    string infixExpression, postfixExpression;
    double value;

    infixExpression = getInfixExpression();
    postfixExpression = infixToPostfix(infixExpression, operatorStack);
    cout << postfixExpression << endl;

    value = evaluatePostFix(postfixExpression);
    cout << value << endl;

    return 0;
}

string getInfixExpression(){
    string infixExpr;

    getline(cin >> ws, infixExpr);

    return infixExpr;
}

string infixToPostfix(string infix, StackInterface<char>& operators){
    string postFixExp = "", operands = ""; char oper;
    int prec, topPrec, operandIndx;
    bool foundClosedParenthesis = 1;

    //iterate over the characters in the infix expression
    for (int i = 0; i < infix.length(); i++){
        char curChar = infix[i];
    
        if (int(curChar) >= 48 && int(curChar) <= 57){ //this is an operand (0-9) - add to postfix expression
            postFixExp.push_back(curChar);

        }
        else if(int(curChar) == 40){ //an open parenthesis
            operators.push(curChar);
            foundClosedParenthesis = 0;

        }
        else if(int(curChar) == 41){ //a closed parenthesis

            while ((operators.peek() != '(')){
                oper = operators.peek(); //get top operator
                operators.pop(); //remove from top of operator stack
                postFixExp.push_back(oper); //add removed operator to postfix expression
            }
            operators.pop(); //removes the closed parenthesis off of top
            foundClosedParenthesis = 1;

        }
        else if(int(curChar) == 43 || int(curChar) == 45 || int(curChar) == 42 || int(curChar) == 47){ //a +,*,/ or - operator
            prec = getOperatorPrecedence(curChar);

                if (foundClosedParenthesis == 0){ // if this is from inside a (), just add to stack, don't pop off yet
                    operators.push(curChar);
                }
                else if (operators.isEmpty() == 1){ // operator stack is empty
                    operators.push(curChar);
                }
                else{ // operator stack is not empty

                    while (((getOperatorPrecedence(operators.peek()) <= prec) && (operators.peek() != '('))){ // topPrec < prec means that that topPrec is a higher precedence (ranked order)

                        oper = operators.peek(); //get top operator
                        operators.pop(); //remove from top of operator stack
                        postFixExp.push_back(oper); //add removed operator to postfix expression

                        operators.push(curChar);

                        if (operators.isEmpty() == 1){
                            break;
                        }
                    }
                }

            }
            else if (int(curChar) == 32){
                // this is a space - do nothing here
            }
            else{
                throw "invalid character entered!";
                break;
            }
    }

    // if there are any operators still in the stack, pop off and add to postfix
     if ((operators.isEmpty() == 0)){
        oper = operators.peek();
        operators.pop(); //remove from top of operator stack
        postFixExp.push_back(oper); //add removed operator to postfix expression
     }

    return postFixExp;
}

int getOperatorPrecedence(char oper){
    int sumMinPrec = 3, multDivPrec = 2, parPrec = 1;

    if (int(oper) == 43 || int(oper) == 45){
        return sumMinPrec;
    }
    if (int(oper) == 42 || int(oper) == 47){
        return multDivPrec;
    }
    return parPrec;
}

double evaluatePostFix(string postfix){
    double exprVal, operand1, operand2;
    char curChar;
    LinkedStack<double> operands; // stack storing operands (top of this after we have gone through postfix will be our final answer)

    for (int i = 0; i < postfix.length(); i++){
        curChar = postfix[i];

        //if the char is an operator
        if (int(curChar) == 43 || int(curChar) == 45 || int(curChar) == 42 || int(curChar) == 47){

            //pop last two operands from stack
            operand2 = operands.peek();
            operands.pop();
            operand1 = operands.peek();
            operands.pop();

            // evaluate
            if (int(curChar) == 43){ // addition
                exprVal = operand1 + operand2;
            }
            else if (int(curChar) == 42){ // multiplication
                exprVal = operand1 * operand2;
            }
            else if (int(curChar) == 45){ // subtraction
                exprVal = operand1 - operand2;
            }
            else if (int(curChar) == 47){ // divison
                exprVal = operand1/operand2;
            }

            // push result to stack so that it can be used as an operand
            operands.push(exprVal);
        }
        else{ // if the char is an operand, push to operands stack
            operands.push(double(int(curChar - 48)));
        }
    }
    return operands.peek(); // get the top value of operands stack (our final answer)
}