#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;


// classes are our own variable type

class robot {
private:
    // define variables and functions
    // data members
    string name;
    int charge;
public:
    // member functions
    void status(){
        cout << "[robot: " << name << ", charge: " << charge << ".]\n";
    }
    // constructors (like beginPlay)
    // a constructor runs when a new instance is created.
    robot(string givenName = "Johnny", int givenCharge = 25){
        cout << "The constructor has been called!\n";
        name = givenName;
        charge = givenCharge;
        status();
    }
    // getters and setter
    void setName(string givenName){
        name = givenName;
    }
    void setCharge(int givenCharge){
        if(givenCharge > 0){
            charge = givenCharge;
        }
        else{
            charge = 0;
        }
    }
    // getters
    string GetName(){return name;}
    int GetCharge(){return charge;}



};

int main() {
    srand(time(0));
    cout << "Let's make some classes!\n";
    // creating a new variable of the type "robot" named "bob"
    robot bob;    // this is where the constructor function is called
    bob.setName("Big Bob");
    bob.setCharge(10);
    cout << "My robot's name is " << bob.GetName() << ".\n";
    cout << "My robot's charge is equal to " << bob.GetCharge() << ".\n";

    bob.status();

    // create a new robot instance and use the constructor to give it a custom name and charge.
    robot Harry("Harry", 30);


    vector<robot> bots;
    vector<string> names {"George", "Willa", "Peanut", "Moose", "Maggie"};

    for(int i = 0; i < 5; i++){
        string tempName = names[rand() % 5];    // pick a random name
        int tempCharge = rand() % 5 + 5;    // pick a random charge (random of 5-10)
        bots.push_back(robot(tempName, tempCharge));    // create a new robot
    }
    
    
}