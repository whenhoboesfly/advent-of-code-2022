#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    fstream myfile;
    string myline;
    vector< vector<int> > forest;
    int y = 0;
    int visible_trees = 0;
    int perimeter = 0;
    bool clear_path[4] = {true, true, true, true};

    //scan forest
    myfile.open("input.txt");
    if(myfile.is_open()){
        while(getline(myfile, myline)){
            forest.push_back(std::vector<int>());
            for(int x = 0; x < myline.size(); x++){
                forest[y].push_back(x); 
                forest[y][x] = myline[x] - '0';
            }
            y++;
        }
    }
    cout << "Forest scanned..." << endl;
    myfile.close();

    //scan tree locations
    for(int h = 1; h < forest.size()-1; h++){ //updown, exclude edge
        for(int l = 1; l < forest[h].size()-1; l++) //leftright, exclude edge
        {
            //scan left
            for(int left = l-1; left >= 0; left--){
                if(forest[h][l] <= forest[h][left]){
                    clear_path[0] = false;
                }
            }
            //scan right
            for(int right = l+1; right < forest[l].size(); right++){
                if(forest[h][l] <= forest[h][right]){
                    clear_path[1] = false;
                }
            }
            //scan up
            for(int up = h-1; up >= 0; up--){
                if(forest[h][l] <= forest[up][l]){
                    clear_path[2] = false;
                }
            }
            //scan down
            for(int down = h+1; down < forest.size(); down++){
                if(forest[h][l] <= forest[down][l]){
                    clear_path[3] = false;
                }
            }
            //tree found
            if( clear_path[0] == true ||
                clear_path[1] == true ||
                clear_path[2] == true ||
                clear_path[3] == true ){
                visible_trees++;
            }
            //reset
            clear_path[0] = true;
            clear_path[1] = true;
            clear_path[2] = true;
            clear_path[3] = true;
        }
    }

    perimeter = (forest.size() * 2) + (forest[0].size() * 2) - 4;
    cout << "Visible trees: " << visible_trees + perimeter<< endl;

    return 0;
}
