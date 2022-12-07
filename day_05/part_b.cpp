#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    fstream myfile;
    string myline;
    unsigned delim1, delim2;
    string move, from, to;
    int movei, fromi, toi;
    stack<char> mystack[10];
    vector<string> initial_stack;
    bool scanning_stack = true;
    int stack_num = 0;
    stack<char> temp;
    temp.push('0');

    int toInt(std::string str);

    myfile.open("input.txt");
    if(myfile.is_open()){
        while(getline(myfile, myline)){
            //get initial stack
            if(scanning_stack)
                if(myline.empty())
                {
                    //cout << "initial stack height: " << initial_stack.size() << endl;
                    //fill stack
                    for(int k=initial_stack.size();k>=0; k--)
                    {
                        stack_num = 0;
                        //cout << "mystack: " << k << endl;
                        for(int j=1; j<37; j=j+4)//1 5 9 13 17 21 25 29 33
                        {
                            if(initial_stack[k][j] != ' '){
                                mystack[stack_num].push(initial_stack[k][j]);
                            }
                            stack_num++;
                            //cout << initial_stack[k][j] << endl;
                            //cout << "stacknum: " << stack_num << endl;
                        }
                    }
                    scanning_stack = false;
                    cout << "initial scanning done" << endl;

                    for(int l=0 ; l<9; l++)
                    {
                        cout << "Top Initial Stack: " << mystack[l].top() << endl;
                    }
                    
                }else
                {
                    initial_stack.push_back(myline);
                }
            else
            {
                //get instructions
                move = myline.substr(0, myline.find(" f"));
                move = move.substr(move.find("e ")+1);
                movei = toInt(move);
                from = myline.substr(0, myline.find(" t"));
                from = from.substr(from.find("m ")+1);
                fromi = toInt(from)-1;
                to = myline.substr(myline.find("o ")+1);
                toi = toInt(to)-1;

                //process instructions
                for(int i=0; i<movei; i++)
                {
                    //mystack[toi].push(mystack[fromi].top());
                    temp.push(mystack[fromi].top());
                    //cout << "fromi: " << fromi << endl;
                    //cout << "toi: " << fromi << endl;
                    mystack[fromi].pop();
                }
                
                for(int m=0; m<movei; m++)
                {
                    mystack[toi].push(temp.top());
                    temp.pop();
                }
            }
        }
        myfile.close();
    }else{
        cout << "unable to open file!";
    }

    for(int l=0 ; l<9; l++)
    {
        cout << "Top Stack: " << mystack[l].top() << endl;
    }
    cout << "done" << endl;

    myfile.close();
    return 0;
}

int toInt(std::string str)
{
    int num;
    std::stringstream ss(str);
    ss >> num;
    return num;
}
