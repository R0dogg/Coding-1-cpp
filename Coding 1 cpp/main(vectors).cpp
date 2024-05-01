#include <iostream>     // for cout and cin
#include <string>
#include <ctime>    // for time
#include <cstdlib>    // for rand() and srand()
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    srand(time(0));

    cout << "Here is your random number: " << rand() % 2000 << ".\n";

    cout << "What program would you like to run?\n";
    cout << "Press 1 for vector exploration.\n";
    cout << "Press 2 for iterator nonsense.\n";
    cout << "Press 3 for algorithms.\n";
    int numInput = 0;
    cin >> numInput;

    if(numInput == 1){
        cout << "Let's talk about vectors!\n";
        
        // build a vector of strings named "inventory" with a size of zero
        vector<string> inventory;

        cout << "There are " << inventory.size() << " items in my bag.\n";

        inventory.push_back("Sword");
        inventory.push_back("Shield");
        inventory.push_back("Axe");

        cout << "There are " << inventory.size() << " items in my bag.\n";
        
        cout << "The first item in my inventory is a " << inventory[0] << ".\n";

        for(int i = 0; i < inventory.size(); i += 1){
            if(inventory[i] == "") continue;
            cout << inventory[i] << ".\n";
        }
        // Lets replace an item, then let's remove an item with pop.back()

        cout << "We don't need a shield, let's get a gun.\n";
        inventory[1] = "gun";

        cout << "Also, our axe breaks!!\n";

        inventory.pop_back();

        for(int i = 0; i < inventory.size(); i += 1){
            if(inventory[i] == "") continue;
            cout << inventory[i] << ".\n";
        }
         
        
    }    // end of program 1

    else if(numInput == 2){
        cout << "Let's talk about iterators!\n";
        // iterators point at a spot in the list (vector)


        vector<string> shoppingList {"Milk", "Eggs", "Candy", "Broccoli", "Flour"};

        vector<string>::iterator iter = shoppingList.begin();

        cout << "Here's the first item in the shopping list: " << *iter << ".\n";

        
        cout << "Here is our shopping list: \n";
        for(vector<string>:: const_iterator iter = shoppingList.begin(); iter != shoppingList.end(); ++iter){
            cout << *iter << "\n";
        }
        cout << "Here is the last item: " << *(shoppingList.end()) << ".\n";
    }

    else if(numInput == 3){
        // lets create a vector of scores
        vector<int> scores;

        
        cout << "Adding scores\n";
        for(int i = 0; i < 10; i++){
            scores.push_back(rand() % 100 +1);
        }

        cout << "Here are the scores:\n";
        for(int i = 0; i < scores.size(); i++){
            cout << scores[i] << ".\n";
        }

       
        
        
        
        
    }
    
    else{
        cout << numInput << " wasn't one of the options.\n";
    }

    
}