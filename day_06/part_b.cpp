#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
using namespace std;

int main(){
    fstream myfile;
    string myline;
    string temp = "xxxxxxxxxxxxxx";
    bool result;

    bool isUnique(string str);

    myfile.open("input.txt");
    if(myfile.is_open()){
        while(getline(myfile, myline)){
            cout << "start" << endl;
            for(int i=0; i<myline.size()-13; i++){
                for(int y = 0; y<14; y++){
                    temp[y] = myline[i+y];
                }
                result = false;
                result = isUnique(temp);

                if(result){
                    cout << "First SOP Marker at: " << i+14 << endl;
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
