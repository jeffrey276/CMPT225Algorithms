#include "char_stack.h"
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

char matchingChar(char c)
{
    if (c == '{')
    {   
        return '}';
    }
    else if (c == '[')
    {
        return ']';
    }
    else if (c == '(')
    {

        return ')';
    }
    return 0;
}

int main()
{
    char_stack st1;
    bool Error = false;
    int line = 0;
    char tmp[250*1000];
    while (cin.getline(tmp, 250*1000))
    {
        line = line + 1;
        int length = cin.gcount();
        for (int i=0; i<length; ++i)
        {
            if (tmp[i] == '(' || tmp[i] == '{' || tmp[i] == '[')
            {
                st1.push(tmp[i]);
            }
            else if (tmp[i] == ')' || tmp[i] == '}' || tmp[i] == ']')
            {
                if (st1.empty())
                {
                    string error = " Too many ";
                    cout << "Error on line " << line<<": ";
                    cout << error << tmp[i]<< endl;
                    
                    
                    	for (int k=0; k<=i; k++){
				cout<<tmp[k];
                    	}
			cout<<endl;
			for (int b=0; b<=i;b++){
			if (tmp[b]=='\t')
				cout <<'\t';
			else
				cout<<' ';
		    	}
				    
			for (int k=i+1; k<length; k++){
				cout<<tmp[k];
			}

                    cout<<endl;
                    Error = true;
                    return 0;
                    
                }
                char put = st1.pop();
                char matching = matchingChar(put);
                if (tmp[i] != matching)
                {
                    string error = "Read ";
                    cout << "Error on line " << line << ": ";
                    cout << error <<tmp[i]<<", expected "<<matching<< endl;

                    for (int k=0; k<=i; k++){
			cout<<tmp[k];
                    }

			cout<<endl;
		    for (int b=0; b<=i;b++){
			if (tmp[b]=='\t')
				cout <<'\t';
			else
				cout<<' ';
		    }
				    
		    for (int k=i+1; k<length; k++){
			cout<<tmp[k];
		    }

				    
			cout<<endl;
                    	Error=true;
                    	return 0;
                    

                }
            }
        }
         
        char c = cin.peek();
        if (c == EOF || Error )
        {
            break;
        }
    }
    if (!st1.empty())
    {
        char put = st1.pop();
        string error = "Too many ";
        cout << "Error on line " << line<<": ";
        cout << error << put<<endl ;
        cout<<tmp;
        cout<<endl;
    }
    else if (!Error)
    {
        cout << "No Errors Found "<< endl;
    }  
   
    return 0;
}
