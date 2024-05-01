#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

void sayHello(){
    cout << "Hello!\n";
}

void ShowVector(vector<string> vec){
    for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << "\n";
    }
}

int CastDamage(int min, int max){

    int damage = rand() % (max - min) + min;

    int critRoll = rand() % 5;
    if(critRoll == 4){
        damage += damage;
        cout << "CRITICAL HIT!\n";
    }
    return damage;
}


// create a function that returns a string. (dead or alive)
// it needs no input paramaters
// it will ask the player how much health they have
// assign that to a variable named "int health"
// and then call CastDamage() with the min being 5 and the max being health
// subtract CastDamage() from health
// if health is less than or equal to zero, return "dead"
// else, return "alive"

string BossFight(){
    cout << "How much health do you have?\n";
    int health = 0;
    cin >> health;

    health -= CastDamage(5, health);

    if(health > 0){
        return "alive";
    }
    else{
        return "dead";
    }
}





int main() {
    srand(time(0));
    sayHello();

    string playerState = BossFight();
    cout << "The player is " << playerState << ".\n";
    
    cout << "Here are some of the foods I don't like.\n";
    
    vector<string> badFoods = {"Carrots", "Fish", "Greek Yogurt", "Blue Cheese", "Mushrooms"};
    
    ShowVector(badFoods);

    cout << "Those are the foods I hate. Oh, I forgot! I don't like onion rings.\n";
    badFoods.push_back("Onion Rings");

    ShowVector(badFoods);

    for(int i = 0; i < 10; i++){
        cout << "The enemy has done " << CastDamage(5, 10) << " damage!!\n";
    }
    
    
    
    
}