#include <bits/stdc++.h>
using namespace std;

//Here we have implemented strategy Pattern using
//C++, defined an abstract class containing the basic
//family of algorithms that a particular animal
//can support. This way adding code is avoided in every subclass
//And it also, increases the code reuse
//Negative point - as the number of algorithms increase
//so does the classes and objects

//decouple the strategy algorithms from the actual class
class FlyBehaviour {
	public:
		virtual string fly() = 0;
};

//concrete classes actually implementing the needed behavior
class flys: public FlyBehaviour {
	public:
		string fly() {
			return "Flying High !";
		}
};

//concrete classes actually implementing the needed behavior
class cantFly: public FlyBehaviour {
	public:
		string fly() {
			return "Can't Fly !";
		}
};

class Animal {
	public:
		FlyBehaviour *strategy;
		Animal() {
			strategy = NULL;
		}
		void setstrategy(FlyBehaviour *f) {
			delete strategy;
			strategy = f;
		}
		string fly() {
			return strategy->fly();
		}
};


class Dog: public Animal {
	public:
		Dog() {
			strategy = new cantFly;
		}
};


class Bird: public Animal{
	public:
		Bird() {
			strategy = new flys;
		}
};

int main() {
	Animal *a = new Dog();
	Animal *b = new Bird();
	cout << "Dog: " << a->fly() << '\n';
	cout << "Bird: " << b->fly() << '\n';

	a->setstrategy(new flys());
	cout << "Dog: " << a->fly() << '\n';
	return 0;
}
