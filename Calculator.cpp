#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#include"stack.h"
using namespace std;

Stack<char> myStack1;
Stack<float> myStack2;

int periority_check(char s)
{
    switch(s)
    {
     case '+':return 1;
     case '-':return 1;
     case 'x':return 2;
     case '/':return 2;
    }
}

float evaluate(float x,float y,char z)
{

    switch(z)
    {
        case '+':return x+y;
        case '-':return x-y;
        case 'x':return x*y;
        case '/':return x/y;
    }


}

float toFloat(char u)
{
    float w =float(u-'0');
    return w;
}




int main( int argc, char *argv[])
{   //string c;

    float final_result;
    if(argc==2) {

    char q,q1;
    char operation;

    float op1,op2;
    int count2=strlen(argv[1]);

    float num;
    float result;


    int num_of_openedbracket=0;
    int num_of_closedbracket=0;

     for(int i=0;i<strlen(argv[1])-1;i++) //string analyzer
		{
			if((argv[1][i]=='x'||argv[1][i]=='/'||argv[1][i]=='+'||argv[1][i]=='('||argv[1][i]=='-')&&(argv[1][i+1]==')'||argv[1][i+1]=='x'||argv[1][i+1]=='/'||argv[1][i+1]=='+'))
			{
				cout<<"Invalid Expression";
				return 0;
			}
		}


    for(int k=0;k<count2;k++)
    {
        if(argv[1][k]=='(') num_of_openedbracket++;
        if(argv[1][k]==')') num_of_closedbracket++;
    }

     if(num_of_openedbracket==num_of_closedbracket) {
      for (int i=0;i<count2;i++)
        {


        /* if((argv[1][i]=='-'&&i=0&&isdigit(argv[1][i+1]))||(argv[1][i]=='-'&&argv[1][i-1]=='('&&isdigit(argv[1][i+1])))
         {

         }*/

    //---------------------------
         if(argv[1][i]=='('){myStack1.push(argv[1][i]); continue;}
   //-----------------------------
         if(isdigit(argv[1][i]))
        {   int p=0;
            num=0;
            float w;
           while(isdigit(argv[1][i+p]))
           {  w=toFloat(argv[1][i+p]);
              myStack2.push(w);
               p++;
           }

        for(int r=0;r<p;r++)
        {
            myStack2.pop(w);
            num=num+w*pow(10,r);
        }

        //num=toFloat(argv[1][i]);
        myStack2.push(num);  i=i+p-1; continue; }


    //-----------------------------
    if((argv[1][i]=='-'&&isdigit(argv[1][i+1])&&i==0)||(i!=0&&argv[1][i]=='-'&&isdigit(argv[1][i+1])&&!isdigit(argv[1][i-1])&&argv[1][i-1]!=')'))
        {   int n=0;
            num=0;
            float w;
           while(isdigit(argv[1][i+n+1]))
           {  w=toFloat(argv[1][i+n+1]);
              myStack2.push(w);
               n++;
           }

        for(int r=0;r<n;r++)
        {
            myStack2.pop(w);
            num=num+w*pow(10,r);
        }
        num=num*-1;
        //num=toFloat(argv[1][i]);
        myStack2.push(num);  i=i+n; continue; }

    //--------------------------------
           if(argv[1][i]=='+'||argv[1][i]=='-'||argv[1][i]=='x'||argv[1][i]=='/')
           {
             if(myStack1.top(q)&&(q=='+'||q=='-'||q=='x'||q=='/'))
             {
                   if (periority_check(q)>=periority_check(argv[1][i]))
                   {
                      myStack1.pop(operation);
                      if (myStack2.num_of_elem()>=2)
                      {
                         myStack2.pop(op2);
                         myStack2.pop(op1);
                         if(operation=='/'&&op2==0)
                         {
                        cout<<"Invalid Expression";
				         return 0;
		               	}
                         result=evaluate(op1,op2,operation);
                         myStack2.push(result);
                         myStack1.push(argv[1][i]);
                      }else {cout << "Invalid Expression" <<endl; goto E;}
                  }else {   myStack1.push(argv[1][i]); continue;}


             } else{myStack1.push(argv[1][i]); continue;}
           }

   //--------------------------------------------
           if(argv[1][i]==')')
           {  L: myStack1.pop(q1);
              if(!myStack1.isEmpty())
              {
               if(q1=='(')
               {continue;}
               else { operation=q1;
                      myStack2.pop(op2);
                      myStack2.pop(op1);
                      if(operation=='/'&&op2==0)
                         {
                        cout<<"Invalid Expression";
				         return 0;
		               	}
                      result=evaluate(op1,op2,operation);
                      myStack2.push(result);
                       goto L;  }
              } else {continue;}
           }
}

  if(myStack2.num_of_elem()>myStack1.num_of_elem()) {
    while(!myStack1.isEmpty())
    {
    myStack1.pop(operation);
    myStack2.pop(op2);
    myStack2.pop(op1);
    if(operation=='/'&&op2==0)
        {
        cout<<"Invalid Expression";
        return 0;
        }
    result=evaluate(op1,op2,operation);
    myStack2.push(result);
    }
    } else {cout << "Invalid Expression" <<endl; goto E;}


    if(myStack2.num_of_elem()==1)
   {myStack2.pop(final_result); }
   else {cout << "Invalid Expression" <<endl; goto E;}


    cout<<fixed<<setprecision(2)<<final_result;
    } else {cout << "Invalid Expression" <<endl;}
    } else {final_result=0; cout<<fixed<<setprecision(2)<<final_result; }

   E: return 0;
}
