#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int DiceRollAttack(int sides = 6){
    int rollAttack = rand() % sides + 1;
    return rollAttack;
}


enum itemType{
    weapon, consumable
};

class item {
public:
    itemType type = weapon;
    int damage = 0;
    string name = "";
    int remainingUses = 0;
    int healingAmount = 0;

    item(string n, itemType t){
        name = n;
        type = t;

        if(type == weapon){
            damage = rand() % 5 + 3;
        }
        else if(type == consumable) {
            healingAmount = rand() % 5 +1;
            damage = -healingAmount;
            remainingUses = 1;
        }
    }    // end of item constructor
    string typeToString(itemType type) {

        switch(type){
            case weapon:
                return "weapon";
                break;
            case consumable:
                return "consumable";
                break;
        }
    }

};

 

class enemy {
public:

    string name;
    int health;
    item heldItem;

enemy(string randomName = "Johnny", int givenHealth = 10) : heldItem("DefaultWeapon", weapon) {
name = randomName;
health = givenHealth;
heldItem = item("DefaultWeapon", weapon);    
};

    
    void setName(string randomName){
        name = randomName;
    }
    void setCharge(int givenHealth){
        if(givenHealth > 0){
            health = givenHealth;
        }
        else{
            health = 1;
        }
    }
    void setItem(item weapon){
        heldItem = weapon;
    }
    string GetName(){return name;}
    int GetCharge(){return health;}
    item GetItem(){return heldItem;}
};


int main() {
    srand(time(0));
    int response = 0;
    int attack = DiceRollAttack();
    int enemyAttack = DiceRollAttack();

    vector<string> enemyNames = {"Cookie Monster", "King Kong", "Gary", "Godzilla", "Milk Man"};
    vector<string> weaponNames = {"Ultra Hammer", "Rancor", "Hot Coffee", "Fire Sword", "Lightsaber" };
    vector<string> consumableNames = {"Apple", "Healing Potion", "Grandma's Hug"};

    string consumable = consumableNames[rand() % consumableNames.size()];

    enemy botOne;
    botOne.setName(enemyNames[rand() % enemyNames.size()]);
    botOne.setCharge(10);
    item weaponItem(weaponNames[rand() % weaponNames.size()], weapon);
    botOne.setItem(weaponItem);

      
    cout << "Howdy Stranger! This is Enemy Class Adventure!\n";
    cout << "Press 1 to continue. Press 2 to end game.\n";
    cin >> response;

    if(response == 1){
        cout << "After a long days work, you are heading back to your castle through a wooded area.\n";
        cout << "Suddenly, " << botOne.GetName() << " jumps out from the bushes!\n";
        cout << "The crazy monster is carrying " << botOne.GetItem().name << " and has " << botOne.GetCharge() << " points of health\n";
        cout << "Press 3 to attack or Press 4 to take a mystery consumable.\n";
        cin >> response;
        if(response == 3){
            cout << "You have chosen to attack!\n";
            cout << "Your cheeto chop does " << attack << " damage points!\n";
            cout << "But, " << botOne.GetName() << " does " << enemyAttack << " points of damage against you!\n";
            if (attack > enemyAttack){
                cout << "Victory! You have won!\n";
            }
            else if (attack < enemyAttack){
                cout << "Oh no! You have lost and now must take the walk of shame!\n";
            } 
            else{
                cout << "Yay, kinda...\n";
                cout << "Your attacks matched in damage.\n";
                cout << "Because of this, you both have gained a new heartwarming friendship!\n";
                cout << "Good game and smiles all around!\n";     
            }
        } else if(response == 4){
            cout << "You reach into your pouch and take out the golden " << consumable << ".\n";
            cout << "You now must attack!\n";
            cout << "Your cheeto chop does " << attack << " damage points!\n";
            cout << "But, " << botOne.GetName() << " does " << enemyAttack << " points of damage against you!\n";
            if (attack > enemyAttack){
                cout << "Victory! You have won and defeated " << botOne.GetName() << ".\n";
            }
            else if (attack < enemyAttack){
                cout << "Oh no! You have lost and now must take the walk of shame!\n";
            } 
            else{
                cout << "Yay, kinda...\n";
                cout << "Your attacks matched in damage.\n";
                cout << "Because of this, you both have gained a new heartwarming friendship!\n";
                cout << "Good game and smiles all around!\n";     
            }
        } else{
            cout << "That wasn't an option. The game is now over.\n";
        }        
    } else if(response == 2){
        cout << "Thank you for playing!\n";   
    } else{
        cout << "That wasn't an option! The game is over.\n";
    }
    
  
}