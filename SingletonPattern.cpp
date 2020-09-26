#include <bits/stdc++.h>
using namespace std;

class Singleton {
   private:
      string s;
      static Singleton* singleton;
      Singleton() = default;
   public:
      static Singleton* getInstance() {
         static Singleton s;
         return &s;
      }
      Singleton(const Singleton &) = delete;
      void operator=(const Singleton &) = delete;
      string getString(){
         return this->s;
      }
      void setString(string a) {
         this->s = a;
      }
};

int main() {
   Singleton *obj = Singleton::getInstance();
   obj->setString("AJAY");
   cout << obj->getString() << '\n';
   obj->setString("KUMAR");
   cout << obj->getString() << '\n';
   return 0;
}
