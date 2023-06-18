#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
//This will allow for access to the header file with the same name.
#include "functions.h"

using namespace std;

//This is used to change the color of text by accessing the windows library.
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void GameStructure::Help() //To avoid having warnings for the Help prototype, all we need to do is make a function that is empty.
{

}

void character::getter(int color)
{
	SetConsoleTextAttribute(h, color); //This will set the color of the preceeding text to whatever the number is for int color.
	cout << "Health: " << health << endl; //This will display the health.
	SetConsoleTextAttribute(h, 10); //We reset the color to being green.
}
void character::setter(int damage, int color)
{
	health -= damage; //In the setter we will change the current health by whatever value damage is.
	if (health <= 0) //If our health is below zero then we will do the preceeding code.
	{
		health = 0; //Set health to 0
		alive = false; //Set alive to false.
		SetConsoleTextAttribute(h, color); //Change color.
		cout << "This character has expired." << endl; //Display that we are dead.
		SetConsoleTextAttribute(h, 10); //Change color to green.
	}
}
void character::resetter()
{
	health = 100; //This brings the health back to 100
	alive = true; //Reset to bool to true.
}
void character::talk(string stuffToSay, int color)
{
	SetConsoleTextAttribute(h, color); //Change the color
	cout << stuffToSay << endl; //This will output the sting to the console. This could range from a simple letter to a whole sentence.
	SetConsoleTextAttribute(h, 10); //Reset the color.
}
void character::talk(string name, string stuffToSay, int color)
{
	SetConsoleTextAttribute(h, color); //change the color
	cout << "Hello, my name is " << name << ". " << stuffToSay << endl; //This will introduce the character and have them say something extra.
	SetConsoleTextAttribute(h, 10); //Reset the color.
}
void character::Attack()
{
	setter(10, 0); //This assigns the damage of attack to be 10 damage.
	getter(0); //Displays the health.
}
void character::Help() //This function will remain empty since the child classes of character will change Help.
{

}

void ninja::ThrowStars()
{
	SetConsoleTextAttribute(h, 11); //Change the color
	cout << "I threw a star!" << endl; //This just shows the ninja threw a star.
	SetConsoleTextAttribute(h, 10); //Reset the color
}
void ninja::Help()
{
	SetConsoleTextAttribute(h, 11);//Change the color
	cout << "Ninja's are really cool, you can use them to throw stars!" << endl; //This will introduce what the ninja is.
	SetConsoleTextAttribute(h, 10);//Reset the color
}
void ninja::Attack()
{
	setter(25, 11); //This overrides the Attack from the character class. This means that this version will be used by the system.
	getter(11); //Display the health.
	SetConsoleTextAttribute(h, 10);//Reset the color
}

void pirate::UseSword()
{
	SetConsoleTextAttribute(h, 6);//Change the color
	cout << "I am Swooshing my Sword!" << endl; //Simple text to show that the pirate is doing an attack.
	SetConsoleTextAttribute(h, 10);//Reset the color
}
void pirate::Help()
{
	SetConsoleTextAttribute(h, 6);//Change the color
	cout << "Pirates's are awesome! They're awesome! If you say anything else then you're a liar!" << endl; //This introduces what the pirate is.
	cout << "We also have really cool swords" << endl;
	SetConsoleTextAttribute(h, 10);//Reset the color
}
void pirate::Attack()
{
	setter(25, 6); //This will set the damage to 25.
	getter(6);//Display the health.
	SetConsoleTextAttribute(h, 10);//Reset the color
}

void kraken::Slash()
{
	SetConsoleTextAttribute(h, 4);//Change the color
	cout << "Rawr! I am slashing at you!" << endl; //This shows the attack that the kraken is doing.
	SetConsoleTextAttribute(h, 10);//Reset the color
}
void kraken::Help()
{
	SetConsoleTextAttribute(h, 4);//Change the color
	cout << "I am the mighty Kraken! Beware of my incredible slashes!" << endl; //This introduces the kraken.
	SetConsoleTextAttribute(h, 10);//Reset the color
}
void kraken::Attack()
{
	setter(25, 4); //Overrides the damage of the character class to by at 25 damage.
	getter(4);//Display the health.
	SetConsoleTextAttribute(h, 10);//Reset the color
}

void RNG::randomNum(int chance)
{
	srand((unsigned)time(NULL)); //This makes a random seed.
	currentNum = rand() % chance; //We will generate a random number between 0 and whatever value chance is.
}
void timer()
{
	for (int i = 3; i > 0; i--) //This for loop will continue until it loops 3 times.
	{
		Sleep(1000); //This will delay the loop into seconds.
	}
}