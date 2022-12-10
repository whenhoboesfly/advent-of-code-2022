#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
using namespace std;

int main(){
    fstream myfile;
    string myline;
    string temp = "xxxx";
    bool result;

    bool isUnique(string str);

    myfile.open("input.txt");
    if(myfile.is_open()){
        while(getline(myfile, myline)){
            cout << "start" << endl;
            for(int i=0; i<myline.size()-3; i++){
                temp[0] = myline[i];
                temp[1] = myline[i+1]; 
                temp[2] = myline[i+2];
                temp[3] = myline[i+3];

                result = false;
                result = isUnique(temp);

                if(result){
                    cout << "First SOP Marker at: " << i+4 << endl;
                    break;
                }
            }
        }
        myfile.close();
    }else{
        cout << "unable to open file!";
    }

    myfile.close();
    return 0;
}

bool isUnique(string str){
    for (int j = 0; j < str.length() - 1; j++) {
        for (int k = j + 1; k < str.length(); k++) {
            if (str[j] == str[k]) {
                return false;
            }
        }
    }
    return true;
}
