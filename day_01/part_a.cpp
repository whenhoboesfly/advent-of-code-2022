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

    int n = sizeof(elf) / sizeof(elf[0]);
    int max = INT_MIN;
    int index = -1;

    for(int i=0;i<n;i++)
    {
        if(elf[i]>max)
        {
            max = elf[i];
            index = i;
        }
    }
    cout << "max value is: " << max;
    cout << " and index is: "<< index <<endl;

    return 0;
}

int toInt(std::string str)
{
    int num;
    std::stringstream ss(str);
    ss >> num;
    return num;
}
