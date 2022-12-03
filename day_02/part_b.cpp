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
    int player_score = 0;
    int player_total_score = 0;

    myfile.open("input.txt");
    if(myfile.is_open()){
        while(getline(myfile, myline)){
            computer = myline[0];
            player = myline[2];

            //manipulate
            if(player == "X"){             //lose
                if(computer == "A"){       //rock
                    player = "Z";          //scissors
                }else if(computer == "B"){ //paper
                    player = "X";          //rock
                }else if(computer == "C"){ //scissors
                    player = "Y";          //paper
                }
            }else if(player == "Y"){       //draw
                if(computer == "A"){       //rock
                    player = "X";          //rock
                }else if(computer == "B"){ //paper
                    player = "Y";          //paper
                }else if(computer == "C"){ //scissors
                    player = "Z";          //scissors
                }
            }else if(player == "Z"){       //win
                if(computer == "A"){       //rock
                    player = "Y";          //paper
                }else if(computer == "B"){ //paper
                    player = "Z";          //scissors
                }else if(computer == "C"){ //scissors
                    player = "X";          //rock
                }
            }

            //calculate score
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
