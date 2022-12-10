#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <stack>
using namespace std;

int toInt(std::string str);

int main(){
    fstream myfile;
    string myline;
    stack<int> cd;
    int cd_sum = 0;
    int total_sum = 0;
    string cmd_cd = "$ cd ";
    string cmd_up = "$ cd ..";
    string cmd_ls = "$ ls";
    string lbl_dr = "dir";

    myfile.open("input.txt");
    if(myfile.is_open()){
        while(getline(myfile, myline)){
            //ls
            if(myline.find(cmd_ls) != std::string::npos){
            //dir
            }else if(myline.find(lbl_dr) != std::string::npos){ 
            //up
            }else if(myline.find(cmd_up) != std::string::npos){ 
                if(cd_sum <= 100000){
                    total_sum += cd_sum;
                }
                cd_sum += cd.top();
                cd.pop();
            //down
            }else if(myline.find(cmd_cd) != std::string::npos){ 
                cd.push(cd_sum);
                cd_sum = 0;
            //size
            }else{             
                cd_sum += toInt(myline.substr(0, myline.find(" "))); 
            }
        }
    }
    cout << "Total size to be cleared: " << total_sum  << endl;
    myfile.close();
    return 0;
}

int toInt(std::string str){
    int num;
    std::stringstream ss(str);
    ss >> num;
    return num;
}
