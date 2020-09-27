#include <bits/stdc++.h>
using namespace std;

//We'regoing to implement
//builder design pattern
//What it does, It basicallly separates out the complex object creation logic
//from Client. Builder Class is responsible for creating Complex objects
//RobotPlan is an Abstract Class that defines What/How and Actual Robot is going to look like.

class RobotPlan {
   public:
      virtual void setRobotHead(string robotHead) = 0;
      virtual void setRobotLegs(string robotLegs) = 0;
      virtual void setRobotHands(string robotHands) = 0;
};

//Robot Class is a concrete class that Actuall implements all the menthos

class Robot: public RobotPlan {
   private:
      string robotHead;
      string robotLegs;
      string robotHands;
   public:
      void setRobotHead(string robotHead) {
         this->robotHead = robotHead;
      }

      string getRobotHead() {
         return this->robotHead;
      }

      void setRobotLegs(string robotLegs) {
         this->robotLegs = robotLegs;
      }

      string getRobotLegs() {
         return this->robotLegs;
      }

      void setRobotHands(string robotHands) {
         this->robotHands = robotHands;
      }

      string getRobotHands(){
         return this->robotHands;
      }
};

//RobotBuilder Class is also an abstract class which
//knows exactly what type of Robots can be built. It has to know all the 
//Robot Types that are being built into the factory

class RobotBuilder {
   public:
      virtual void buildRobotHead() = 0;
      virtual void buildRobotHands() = 0;
      virtual void buildRobotLegs() = 0;
      virtual Robot* getRobot() = 0; 
};

//OldRobotBuilder is a concrete class that builds separate parts of the 
//actual Robot


class OldRobotBuilder: public RobotBuilder {
   private:
      Robot *robot;
   public:
      OldRobotBuilder(){
         robot = new Robot();
      }
      void buildRobotHead() {
         robot->setRobotHead("Tin Head");
      }
      
      void buildRobotHands() {
         robot->setRobotHands("Tin Hands");
      }

      void buildRobotLegs() {
         robot->setRobotLegs("Tin Legs");
      }
      Robot* getRobot(){
         return this->robot;
      }
};

//And Final RobotEngineer is responsible for creating robots
//All you need to do, is to call makeRobot() Method of RobotEngineer Class
//It then builds the robot and stores it. 


class RobotEngineer {
   private:
      RobotBuilder *oldRobotBuilder;
   public:
      RobotEngineer(RobotBuilder* old){
         delete oldRobotBuilder;
         oldRobotBuilder = old;
      }

      void makeRobot(){
         this->oldRobotBuilder->buildRobotHead();
         this->oldRobotBuilder->buildRobotLegs();
         this->oldRobotBuilder->buildRobotHands();
      }

      Robot* getRobot(){
         return this->oldRobotBuilder->getRobot();
      }
};

int main() {
   RobotBuilder *robotBuilder = new OldRobotBuilder();
   RobotEngineer *robotEngineer = new RobotEngineer(robotBuilder);

   robotEngineer->makeRobot();
   cout << "Robot Being Built\n";
   Robot *firstRobot = robotEngineer->getRobot();
   cout << '\n';

   cout << "Robot Head: " << firstRobot->getRobotHead() << '\n';
   cout << "Robot Head: " << firstRobot->getRobotLegs() << '\n';
   cout << "Robot Head: " << firstRobot->getRobotHands() << '\n';

   cout << '\n';

   Robot *secondRobot = robotEngineer->getRobot();
   secondRobot->setRobotHead("Steel Head");

   cout << "Second Robot Head: " << secondRobot->getRobotHead() << '\n';
   cout << "Second Robot Legs: " << secondRobot->getRobotLegs() << '\n';
   cout << "Second Robot Hands: " << secondRobot->getRobotHands() << '\n';

   cout << '\n';

   cout << "First Robot Head: " << firstRobot->getRobotHead() << '\n';
   cout << "First Robot Legs: " << firstRobot->getRobotLegs() << '\n';
   cout << "First Robot Hands: " << firstRobot->getRobotHands() << '\n';

   cout << '\n';
   
   return 0;
}