#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
using namespace std;

int toInt(std::string str);

int main(){
    fstream myfile;
    string myline1, myline2, myline3;
    int line1_size, line2_size, line3_size;
    int sum = 0;
    bool done = false;

    //priority is index+1
    string item = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    myfile.open("input.txt");
    if(myfile.is_open()){
        while(getline(myfile, myline1)){
            getline(myfile, myline2);
            getline(myfile, myline3);

            line1_size = myline1.size();
            line2_size = myline2.size();
            line3_size = myline3.size();

            //first line
            for(int i=0; i<line1_size; i++){
                //second line
                for(int j=0; j<line2_size; j++){
                    //third line
                        if(myline1[i] == myline2[j]){
                            for(int k=0; k<line3_size; k++){
                                if(myline2[j] == myline3[k]){
                                    for(int l=0; l<item.size(); l++){
                                        if((myline3[k] == item[l]) && !done){
                                            sum += l+1;
                                            done = true;
                                    }
                                }
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
