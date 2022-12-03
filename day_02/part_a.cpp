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
    string computer;
    string player;
    int computer_score = 0;
    int player_score = 0;

    int computer_total_score = 0;
    int player_total_score = 0;

    myfile.open("input.txt");
    if(myfile.is_open()){
        while(getline(myfile, myline)){
            computer = myline[0];
            player = myline[2];

            if( (computer == "A" && player == "X") ||
                (computer == "B" && player == "Y") ||
                (computer == "C" && player == "Z") ){ //tie
                player_score += 3;
                if(player == "X"){       //rock
                    player_score += 1; 
                }else if(player == "Y"){ //paper
                    player_score += 2;
                }else if(player == "Z"){ //scissors
                    player_score += 3;
                }
            }else if(computer == "A"){   //rock
                if(player == "Y"){       //paper
                    player_score += 2;   //win
                    player_score += 6;
                }else if(player == "Z"){ //scissors
                    player_score += 3;   //lose
                }
            }else if(computer == "B"){   //paper
                if(player == "X"){       //rock
                    player_score += 1;   //lose
                }else if(player == "Z"){ //scissors
                    player_score += 3;   //win
                    player_score += 6;
                }
            }else if(computer == "C"){    //scissors
                if(player == "X"){        //rock
                    player_score += 1;    //win
                    player_score += 6;
                }else if(player == "Y"){  //paper
                    player_score += 2;    //lose
                }
            }

            player_total_score += player_score;
            player_score = 0;
        }

        myfile.close();
    }else{
        cout << "unable to open file!";
    }

    cout << "Player Total: " << player_total_score << endl;

    myfile.close();
    return 0;
}
