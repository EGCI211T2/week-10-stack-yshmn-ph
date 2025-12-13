#include<iostream>
using namespace std;

#include "stack.h"

int main(int argc, char **argv){
    Stack s;
    int i, j;
    int mismatch; 
    char c;     

    printf("Checking the parentheses in argv arguments\n");

    for (i = 1; i < argc; i++) {
        mismatch = 0; 
        
       
        while(s.getSize() > 0) s.pop(); 

        cout << "\nChecking argument: " << argv[i] << endl;

        for (j = 0; j < strlen(argv[i]); j++) {
            
            if (argv[i][j] == '[' || argv[i][j] == '{' || argv[i][j] == '(') {
                s.push(argv[i][j]);
            }
            
            else if (argv[i][j] == ']' || argv[i][j] == '}' || argv[i][j] == ')') {
                
                
                if (s.getSize() == 0) {
                    cout << "Error: Too many closing parentheses." << endl;
                    mismatch = 1;
                    break;
                }

                
                c = s.pop(); 

               
                if (argv[i][j] == ']' && c != '[') {
                    cout << "Error: Mismatch detected at index " << j << endl;
                    mismatch = 1;
                    break;
                }
                if (argv[i][j] == '}' && c != '{') {
                     cout << "Error: Mismatch detected at index " << j << endl;
                     mismatch = 1;
                     break;
                }
                if (argv[i][j] == ')' && c != '(') {
                     cout << "Error: Mismatch detected at index " << j << endl;
                     mismatch = 1;
                     break;
                }
            }
        }

        
        if (mismatch == 0 && s.getSize() > 0) {
            cout << "Error: Too many opening parentheses (Stack not empty)." << endl;
            mismatch = 1;
            
            while(s.getSize() > 0) s.pop();
        }

        if (mismatch == 0) {
            cout << "Result: Parentheses match correctly!" << endl;
        }
    }
   
/*
  Exercise 2
 printf("Checking the parentheses in argv arguments\n");

   */

    /*
     for(j=0;j<strlen(argv[i]);j++){
       // Use stack to help with the parentheses





  }

  */


   return 0;
}
