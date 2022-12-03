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
    int num_line = 1;
    int num_elf = 1;
    int sum = 0;
    int elf[300] = {0};

    myfile.open("input.txt");

    if(myfile.is_open()){
        while(getline(myfile, myline)){
            cout << myline << endl;
            sum += toInt(myline);
            //cout << "current sum: " << sum << endl;

            if(myline == ""){
                cout << "^^^Elf # " << num_elf << " with sum: " << sum-1 << endl;
                elf[num_elf] = sum-1;
                sum = 0;
                num_elf++;
            }
            num_line++;
        }

        myfile.close();
    }else{
        cout << "unable to open file!";
    }
  
    cout << num_line-1 << " lines" << endl;
    cout << num_elf-1 << " elves" << endl;
    myfile.close();

    int first, second, third;
    third = first = second = INT_MIN;
    int n = sizeof(elf) / sizeof(elf[0]);
  
    for(int i = 0; i < n; i++){
    if (elf[i] > first){
      third = second;
      second = first;
      first = elf[i];
    }else if (elf[i] > second && elf[i] != first){
      third = second;
      second = elf[i];
    }else if (elf[i] > third && elf[i] != second)
      third = elf[i];
    }
  
    cout << "Three largest elements are "
    << first << " " << second << " "
    << third << endl;

    int three_sum = first + second + third;
    cout << "three sum: " << three_sum << endl;

    return 0;
}

int toInt(std::string str)
{
    int num;
    std::stringstream ss(str);
    ss >> num;
    return num;
}
