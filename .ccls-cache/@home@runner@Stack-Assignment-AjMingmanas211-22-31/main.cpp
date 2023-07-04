#include <iostream>
using namespace std;
#include "stack.h"
#include <cstring>

int main(int argc, char *argv[]) {
    char data;  
    for(int j=1;j<argc;j++){
      cout<<"******************"<<endl;
      Stack s;
      bool match=1;
      bool tooManyClose = 0;
        for (int i=0; i<strlen(argv[j]);i++){
            switch(argv[j][i]){
                case '[':
                     s.push(argv[j][i]);
                     break;
                case '{':
                    s.push(argv[j][i]);
                    break;
                case ']':
                    data=s.pop();
                    if (data != '[' ) match=0;
                    if (data == 0 ) tooManyClose=1;
                    break;
                case '}':
                    data=s.pop();
                    if (data != '{' ) match=0;
                    if (data == 0 ) tooManyClose=1;
                    break;
                default: break;
            }//end switch
          if (match==0) break;
        }//end i loop
        if(s.getSize()>0){
          match=0;  
        }
        if (match==0){
            cout<<"Parenthesis do not match ";
            if(tooManyClose==1)
              cout<<"too many close parenthesis"<<endl;
            else if(s.getSize()>0)
              cout<<"too many open parenthesis"<<endl;
            else cout<<endl;
        }
        else
            cout<<"Parentheses match"<<endl;
    }//end j loop
}