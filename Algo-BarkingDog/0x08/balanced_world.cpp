//
//  balanced_world.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/17.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    while (1) {
        getline(cin, str);
        if (str == ".") {
            break;
        }

        stack<char> st;
        bool flag = false;
        for(auto s : str){
            if(s=='(' || s=='['){
                st.push(s);
            }
            else if(s==')'){
                if(st.empty() || st.top()!='('){
                    flag=true;
                    break;
                }
                st.pop();
            }
            else if(s==']'){
                if(st.empty() || st.top()!='['){
                    flag=true;
                    break;
                }
                st.pop();
            }
        }
        if(!st.empty()){
            flag=true;
        }
        
        if(flag){
            cout<<"no\n";
        }
        else{
            cout<<"yes\n";
        }
    }

    return 0;
}
