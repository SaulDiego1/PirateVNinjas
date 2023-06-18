//This is a header file. This is used for better organization in seperating function prototypes and accessing the functions in other files.


#pragma once
//These will allow for us to use the libraries that we are including. This is helpful when it comes to interacting with the console.
#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>

using namespace std; //This is used to avoid stating 'std::' every time I write something.

//This is what is considered a base class or parent class. This call doesn't inherit from any other classes and can only access the components in here.
class GameStructure
{
	virtual void Help(); //This virtual function which is intended to be redefined by the classes that inherit from this.
};

class character : public GameStructure //This is a child class of the GameStructure. This means it will be able to access anything that is public in the parent.
{
public: //This will tell the program that everything after this line is public for usage by other classes that inherit from this one.
	string Name; //Just a simple string to represent the name of a character.
	void getter(int color); //The getter is a function or a method that will get the health variable. This also includes a parameter for an integer.
	void setter(int damage, int color); //Setter will set a new value for the health and contains two different variables. One for damage and one for color.
	void resetter();//The resetter will reset the health and represent the character as alive.
	void talk(string stuffToSay, int color); //The talk method has a string parameter which will allow for text to be put through it such as a sentence.
	void talk(string name, string stuffToSay, int color); //The second talk is an instance of overloading which means that 
	//depending on how many things we put through this we will either do this function or the other one.
	virtual void Attack(); //Attack is made a virtual function which means we will change it in the child classes.
	void Help(); //We can override the Help function using the character class.
	bool alive = true; //This is a boolean used to determine if a character is alive.
private: //Every line after this will be considered to the character class.
	int health = 100; //The only thing made private is the health integer which will be accessed by the getter and setter.
};

class ninja : public character //This is a child of the character class, which is a child of the GameStructure class. This gives it access to both of them.
{
public:
	void ThrowStars(); //This is unique to the ninja class only.
	void Help(); //This can also be overrided by the ninja class.
	void Attack(); //This will override the attack from the character class.
};

class pirate : public character //This class is also allowed to inherit from the character class and have its own unique items.
{
public:
	void UseSword(); //Only the pirate can access this.
	void Help();
	void Attack();
};

class kraken : public character //This has the same case as the pirate and ninja.
{
public:
	void Slash(); //Only kraken can slash.
	void Help();
	void Attack();
};

class RNG //This RNG class doean't inherit from anything making it a base class as well.
{
public:
	void randomNum(int chance); //This will make a random number and has a parameter for the chances of the random number.
	int currentNum; //This will hold the random number.
};

void timer(); //This is an independt function used to be a timer.
