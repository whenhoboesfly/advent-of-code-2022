#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
using namespace std;

int toInt(std::string str);

int main(){
    fstream myfile;
    string myline;
    int X = 1;
    int cycle = 0;
    int ss = 0;
    int ss_total = 0;

    myfile.open("input.txt");
    if(myfile.is_open()){
        while(getline(myfile, myline)){
          
            if(myline[0] == 'a'){ //addx
                for(int i = 0; i < 2; i++){
                    cycle += 1;
                    ss = cycle * X;
                    if( cycle == 20  || cycle == 60 || cycle == 100 ||
                        cycle == 140 ||cycle == 180 || cycle == 220){
                        ss_total += ss;
                        cout << "Cycle: " << cycle << " X: " << X << " Sum: " << ss_total<< endl;
                    }
                }
                X += toInt(myline.substr(myline.find(" ")+1));
              
            }else{ //noop
                cycle += 1;
                ss = cycle * X;
                if( cycle == 20  || cycle == 60  || cycle == 100 ||
                    cycle == 140 || cycle == 180 || cycle == 220){
                    ss_total += ss;
                    cout << "Cycle: " << cycle << " X: " << X << " Sum: " << ss_total<< endl;
                }
            }
          
        }
    }else{
        cout << "unable to open file!";
    }

    cout << "Sum of six signal strengths: " << ss_total;
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
