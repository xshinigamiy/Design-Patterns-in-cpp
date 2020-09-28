#include <bits/stdc++.h>
using namespace std;

//Function to get Random Values in the range from 1 - X
int getRandom(int X) {
   srand(time(0));
   return int((rand() % X) + 1);
}


//An Abstract Class that defines the behaviour of each Attack
class EnemyAttacker {
   public:
      virtual void fireGun() = 0;
      virtual void moveForward() = 0;
      virtual void driveCar(const string &s) = 0;
};

//Concrete Class the inherites from Enemy Attacker class
//And implements needed functionalities
class EnemyTank: public EnemyAttacker {
   public:
      void fireGun() {
         cout << "Damage Given: " << getRandom(10) << " by Enemy Tank" << '\n';
      }
      void moveForward() {
         cout << "Enemy Tank moved Forward: " << getRandom(5) << '\n';  
      }
      void driveCar(const string &s) {
         cout << s << " driving the Tank\n";  
      }
};

//EnemyRobot class is not compatible with the EnemyTank class
class EnemyRobot {
   public:
      void fightWithHands() {
         cout << "Damage given by hands: " << getRandom(3) << '\n';
      }

      void moveSlowly() {
         cout << "Robot moved by " << getRandom(2) << " steps\n";
      }

      void driveCar(const string &s) {
         cout << "Robot Can't Drive a car\n";
      }
};



//This class behaves as an Adapter class to EnemyRobot class.
//It gives an abstraction to the client that It is behaving in the same 
//way as the EnemyTank Class
class EnemyRobotAdaptor: public EnemyAttacker {
   private:
      EnemyRobot* robot;
   public:
      EnemyRobotAdaptor(EnemyRobot* robot) {
         this->robot = robot;
      }

      void fireGun() {
         this->robot->fightWithHands();
      }

      void moveForward() {
         this->robot->moveSlowly();
      }

      void driveCar(const string &s) {
         this->robot->driveCar(s);
      }
};


//Driver Function
int main(){
   EnemyRobot *robot = new EnemyRobot();

   cout << '\n';
   cout << "Enemy Robot\n";
   robot->fightWithHands();
   robot->moveSlowly();
   robot->driveCar("AJAY");

   cout << '\n';
   cout << "Enemy Tank\n";


   EnemyTank *enemyTank = new EnemyTank();
   enemyTank->fireGun();
   enemyTank->moveForward();
   enemyTank->driveCar("KUMAR");

   cout << '\n';
   cout << "Enemy Robot with Adapter\n";

   EnemyAttacker *enemyRobotAdaptor = new EnemyRobotAdaptor(robot);
   enemyRobotAdaptor->fireGun();
   enemyRobotAdaptor->moveForward();
   enemyRobotAdaptor->driveCar("AJAy");
   cout << '\n';
   return 0;
}