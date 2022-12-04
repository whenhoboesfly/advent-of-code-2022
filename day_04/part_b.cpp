#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
using namespace std;

int main(){
    fstream myfile;
    string myline;
    int pair_count = 0;
    string elf1, elf2;
    string elf1_low, elf1_high;
    string elf2_low, elf2_high;
    int e1_low, e1_high;
    int e2_low, e2_high;

    int toInt(std::string str);

    myfile.open("input.txt");
    if(myfile.is_open()){
        while(getline(myfile, myline)){
            //elf1 range
            elf1 = myline.substr(0, myline.find(","));
            elf1_low = elf1.substr(0, elf1.find("-"));
            elf1_high = elf1.substr(elf1.find("-")+1);
            e1_low = toInt(elf1_low);
            e1_high= toInt(elf1_high);
            cout << "elf 1: " << e1_low << " to " << e1_high << endl;

            //elf2 range
            elf2 = myline.substr(myline.find(",")+1);
            elf2_low = elf2.substr(0, elf2.find("-"));
            elf2_high = elf2.substr(elf2.find("-")+1);
            e2_low = toInt(elf2_low);
            e2_high= toInt(elf2_high);
            cout << "elf 2: " << e2_low << " to " << e2_high << endl;

            if( ((e1_low <= e2_low)  && (e2_low  <= e1_high)) ||
                ((e1_low <= e2_high) && (e2_high <= e1_high)) ||
                ((e2_low <= e1_low)  && (e1_low  <= e2_high)) ||
                ((e2_low <= e1_high) && (e1_high <= e2_high))
            ){
                pair_count += 1;
            }
          
        }
        myfile.close();
    }else{
        cout << "unable to open file!";
    }

    cout << "Number of pairs: " << pair_count << endl;

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
