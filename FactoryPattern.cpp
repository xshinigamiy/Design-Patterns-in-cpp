#include <bits/stdc++.h>
using namespace std;

//an abstract class
class Notification {
   public:
      virtual void notifyUser() = 0;
};

class SMSNotification: public Notification {
   public:  
      void notifyUser() {
         cout << "SMS Notification\n";
      }
      ~SMSNotification() {
         cout << "SMSNotification destructor Called\n";
      }
};

class PushNotification: public Notification {
   public:  
      void notifyUser() {
         cout << "Push Notification\n";
      }
      ~PushNotification() {
         cout << "PushNotification destructor Called\n";
      }
};

class EmailNotification: public Notification {
   public:  
      void notifyUser() {
         cout << "Email Notification\n";
      }
      ~EmailNotification() {
         cout << "EmailNotification destructor Called\n";
      } 
};

//factory class which is responsible for creating/producing objects
//and decoupling the object creation logic
//from client side
class FactoryClass {
   public:
      FactoryClass() {
         cout << "FactoryClass xctor Called\n";
      }
   public:
      Notification* createNotification(string s) {
         if(s == "SMS")
            return new SMSNotification;
         else if(s == "PUSH")
            return new PushNotification;
         else if(s == "EMAIL")
            return new EmailNotification;
         return new EmailNotification;    
      }
};

int main(){
   FactoryClass f;
   vector<Notification*> v;
   v.clear();
   int i = 0;
   while(i < 4){
      if(i == 1){
         v.push_back(f.createNotification("SMS"));
      } else if(i == 2) {
         v.push_back(f.createNotification("PUSH"));
      } else if(i == 3) {
         v.push_back(f.createNotification("EMAIL"));
      }
      ++i;
   }

   for (int i = 0; i < v.size(); ++i) {
      v[i]->notifyUser();
   }
   return 0;
}
