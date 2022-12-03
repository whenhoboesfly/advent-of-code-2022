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
    int line_size;
    int sum = 0;
    bool done = false;

    //priority is index+1
    string item = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    myfile.open("input.txt");
    if(myfile.is_open()){
        while(getline(myfile, myline)){
            line_size = myline.size();
            //first half
            for(int i=0; i<line_size/2; i++){
                //second half
                for(int j=line_size/2; j<line_size; j++){
                    if(myline[i] == myline[j]){
                        for(int k=0; k<item.size(); k++){
                            if((myline[i] == item[k]) && !done){
                                sum += k+1;
                                done = true;
                            }
                        }
                    }
                }
            }
            done = false;
            cout << "endline" << endl;
        }

        myfile.close();
    }else{
        cout << "unable to open file!";
    }

    cout << "Sum is: " << sum << endl;

    myfile.close();
    return 0;
}
