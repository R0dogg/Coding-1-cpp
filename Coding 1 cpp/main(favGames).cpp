#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cout << "Hello! Welcome to Roman's Favorite Games. Select an option below.\n";
        vector<string> favGames;
        favGames.push_back("Mario Kart");
        favGames.push_back("Skyrim");
        favGames.push_back("Fall Guys");
        favGames.push_back("War of the Monsters");
        favGames.push_back("Fallout");

    while(true){
        cout << "Press 1 to show Roman's favorite Games.\n";
        cout << "Press 2 to add to the games list.\n";
        cout << "Press 3 to quit.\n";
        int input = 0;
        string addedGame = "";
        cin >> input;
        if(input == 1){
            cout << "Roman has " << favGames.size() << " favorite games!\n";

            cout << "Here is a list of Roman's favorite games:\n";

            for(int i = 0; i < favGames.size(); i++)
                cout << i + 1 << "." << favGames[i] << "\n";
        }
        else if(input == 2){
            cout << "What game would you like to add?\n";
            cin >> addedGame;
            favGames.push_back(addedGame);
            cout << "Thank you for adding " << addedGame << " to the list!\n";
        }
        else if(input == 3){
            cout << "Thank you for playing. Have a good day!\n";
            break;
        }
        
        
    }
       
    }
    