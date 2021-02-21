#include <iostream>
#include <string>
#include "stack.h"
#include<sstream>
#include <math.h>// for the pow operation
#include "queue.h"
using namespace std;

// check function whether character is a digit or not
bool isDigit(char c)
{
    return (c>='0'&& c <= '9');
}

// check function whether character is a operator or not
bool isOp(char c)
{
    return(c=='+'||c=='-'||c=='*'||c=='/'||c=='%'||c=='^'||c=='('||c==')'||c=='['||c==']');
}

// determine function to get the precedence of an operator
// the precedence of operator except paranthesis like this:
// ^ > % > * = / > + = -
int getPrecedence (char c)
{
    switch (c)
    {
    case '+':
    case '-': return 1 ;
    case '*':
    case '/': return 2 ;
    case '%': return 3;
    case '[': return 0;
    case ']': return 5;
    case '(': return 0;
    case ')': return 5;
    case '^': return 4;
    default : return -1;


    }
}

// operation function to basically calculation operand1 (operator) operand2
int operate (int val1, int val2, char op)
{
    if (op=='+') return val1+val2;
    if (op=='-') return val1-val2;
    if (op=='*') return val1*val2;
    if (op=='/') return val1/val2;
    if (op=='%') return val1%val2;
    if (op=='^') return pow(val1,val2);
}

// A push function to use Queue as a stack and note
// that this push function has complexity of O(n)
void enqueue(Queue<int> Q1,int item)
{
    Q1.Qinsert(item);
    for(int i=0; i<(Q1.QLength()-1);i++)
    {
        Q1.Qinsert(Q1.QDelete());
    }

}

// A pop function to use Queue as a stack and note
// that this push function has complexity of O(1)
int dequeue(Queue<int> Q1)
{
return Q1.QDelete();
}


//evaluate given input string
int evaluateExpression (string s)
{
    Queue<int> val; // Values are stored in this Queue
    Stack<char> ops; // Operators(including paranthesis) are stored here

    int value=0;
    int pos=0;
    while (pos < s.length())
    {
        char current=s[pos];
        if(isDigit(current))
        {
            value=(value*10)+(int)(current-'0');
        }
        else if (isOp(current))
        {
          if(current=='(')
          {
              ops.push(current);
              value=0;
          }

          else if(current=='[')
          {
              ops.push(current);
              value=0;
          }



           else if(val.QEmpty())
           {
               enqueue(val,value);
               ops.push(current);
               value=0;
           }

           else if(current==')')
           {
               enqueue(val,value);
               while(ops.peek()!='(')
               {
                   current=ops.pop();
                   value=dequeue(val);
                   int prev = dequeue(val);
                   value= operate(prev,value,current);
                   enqueue(val,value);
               }
               ops.pop();
               dequeue(val);
           }


           else if(current==']')
           {
               enqueue(val,value);
               while(ops.peek()!='[')
               {
                   current=ops.pop();
                   value=dequeue(val);
                   int prev = dequeue(val);
                   value= operate(prev,value,current);
                   enqueue(val,value);
               }
               ops.pop();
               dequeue(val);
           }


           else
           {
               char prev = ops.peek();
               if (getPrecedence(current)>getPrecedence(prev))
               {
                   enqueue(val,value);
                   ops.push(current);
                   value=0;
               }
               else
               {
                   int prevval=dequeue(val);
                   int prevop=ops.pop();
                   prevval=operate(prevval,value,prevop);

                    while (!ops.isEmpty()&& (getPrecedence(current)<=getPrecedence(ops.peek())))
                    {
                        prevval=operate(dequeue(val),prevval,ops.pop());

                    }
                    enqueue(val,prevval);
                   ops.push(current);
                   value=0;
               }
           }
        }
        pos++;
    }

    while(!ops.isEmpty())
    {
        int prev = dequeue(val);
        char current = ops.pop();
        value=operate(prev,value,current);
    }

    return value;
}

// check function whether given input string is valid expression or not
int checkExpression(string str)
{

    int length = str.length();
    Stack<char> Sc;
    char s[length];

    str.copy(s,length);
    char c; int i=0;

    for(i=0;i<length;i++)
 {
        if(!isdigit(s[i]))
      {

          if((s[i]!='+')&&(s[i]!='-')&&(s[i]!='*')&&(s[i]!='/')&&(s[i]!='%')&&(s[i]!='^')&&(s[i]!='(')&&(s[i]!='[')&&(s[i]!=')')&&(s[i]!=']'))
          {
              return 0;
          }
      }


      if (s[i] == '(')
            {
            Sc.push(s[i]);
            }

 else if (s[i] == '[')
        {
        Sc.push(s[i]);
        }
 else if (s[i] == '{')
        {
        Sc.push(s[i]);
        }

 else if (s[i] == ')')
    {
 if (Sc.isEmpty())
 {
     return 0;
 }
 else {
        c=Sc.pop();

 if (c=='(') {return 1;}
 else {return 0;}}
 }


 else if (s[i] == ']')
    {
 if (Sc.isEmpty())
 {
     return 0;
 }
 else {
        c=Sc.pop();

 if (c=='[') {return 1;}
 else {return 0;}}
 }


 else if (s[i] == '}')
    {
 if (Sc.isEmpty())
 {
     return 0;
 }
 else {
        c=Sc.pop();

 if (c=='{') {return 1;}
 else {return 0;}
 }
   i++;
 }

 }
 }




int main()
{

    int a=0;
    int flag=0; // when the input written this flag will be 1
    int valid=0;  // when the expression is valid, this will be 1
    int option;
    int reset=0;  // when reset is called by client, this will be 1
    string inputstring;
    cout<< "Queue and Stack Based Calculator"<<endl;
    cout<<""<<endl;
    cout<< "MENU"<<endl;
    cout<< "1-) Enter an Expression"<<endl;
    cout<< "2-) Check the Expression"<<endl;
    cout<< "3-) Calculate"<<endl;
    cout<< "4-) Reset"<<endl;
    cout<< "5-) Exit"<<endl;

    while(1)
    {

        cout<<""<<endl;
        string option;
        cout<< "Enter Your Option"<<endl;
        cin>>option;
        stringstream opt(option);

        opt>>a;
        if(a==1)
        {

            cout<< "Enter an expression"<<endl;

            cin.clear();
            cin.ignore();
            getline(cin, inputstring);
            flag=1;
            reset=0;

        }
        else if(a==2)
        {
            if(reset)  {
            cout<<"You had reseted the calculator ?!"<<endl;
            cout<<""<<endl;
            }
            else if(!flag)
                {
                    cerr<< "Please Enter an expression First"<<endl;
                    cout<<""<<endl;
                }
            else
            {
                valid=(checkExpression(inputstring));
                if(valid)
                {
                cout<< "Valid expression!"<<endl;

                }
                else
                cout<< "Invalid expression!"<<endl;

            }
        }
        else if(a==3)
        {
            if(reset) {
            cout<<"You had reseted the calculator ?!"<<endl;
            cout<<""<<endl;
            }
            else if((!flag))
                {
                cerr<< "Please Enter an expression First"<<endl;
                cout<<""<<endl;
                }
            else if(valid)
            {
                int result=evaluateExpression(inputstring);
                cout<< "Result of the expression is "<<result<<"."<<endl;

            }
        }

        else if(a==4)
        {

            //ops.~Stack();
            //val.~Queue(); // I did not use them because i created them in the evaluateExpression
            // and after the evaluateExpression function finished they are already destructed in the last
            // '}' paranthesis. If the homework was given as " We must use the last calculated answer,
            // I should have created global variables as ops Stack and val Queue. and then in this case
            // i should have destructed them and when client press the enter the expression button i should have
            // recreated them.

            cout <<"Reset is successful!"<<endl;
            reset = 1;

        }

        else if(a==5)
        {
            cout<<"Thank you again for the good grades ! =)"<<endl;

            return 0;
        }

        else cerr<< "Please Enter a Valid Option"<<endl;

    }
    return 0;
}
