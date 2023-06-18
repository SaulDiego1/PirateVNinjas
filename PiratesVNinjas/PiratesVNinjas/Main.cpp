#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
//This includes the functions that are created in the other two files. This allow us to use them here freely.
#include "functions.h"

using namespace std;



int main()
{
	//These four lines declare the class into tbe main. This allow us to access the components of the class by stating the name we assigned such as 'ryu'.
	ninja ryu{};
	pirate marvelous{};
	kraken boss{};
	RNG randomizer{};
	//This is a simple string used to handle responses that are needed from the player.
	string response;

	cout << "\t\t***Ninjas V Pirates***" << endl;
	marvelous.talk("Marvelous", "I am sailing for treasures. Land! Ho!", 6); //To access the classes we state the name that is initialized for it and the action.
	timer(); //This will create a pause so we don't get one whole block of text at once.
	marvelous.talk("Arrgh! Give me your valuables!", 6);
	timer();
	ryu.talk("Ryu", "My mission is to defend my homeland from the barbaric pirates.", 11);
	timer();
	marvelous.talk("Arrgh! Just give me any gold you have. I don't wanna stay in this crummy place!", 6);
	timer();
	ryu.talk("We don't have any gold. All we have is cool swords and really great pens.", 11);
	timer();
	ryu.Help();
	timer();
	marvelous.Help();
	timer();
	marvelous.talk("Arrgh! I wasted 37 weeks just to get here!", 6);
	timer();
	ryu.talk("Well it seems you got everything you need. Time to go home now.", 11);
	timer();
	marvelous.talk("Arrgh! I'm not leaving! I just got here! Maybe you should leave!", 6);
	timer();
	ryu.talk("Either you leave on your own or I will make you leave.", 11);
	timer();
	cout << "Type 'hit' to attack the pirate! Beware of his strong slashes, he may attack at random." << endl;
	//The do while loop will continue until we meet an exit requirement.
	do
	{
		cin >> response; //This takes the response from the player as a string.
		if (response == "hit") //If we type hit then we will do everything in here.
		{
			ryu.ThrowStars(); //This will show the action of throwing stars.
			marvelous.Attack(); //This damages the pirate.
		}
		if (marvelous.alive == true) //If the pirate is alive then we will do everything in here.
		{
			randomizer.randomNum(10); //Generate a random number.
			if (randomizer.currentNum > 5) //If the random number is greater than 5 then we attack the player.
			{
				marvelous.UseSword();
				ryu.Attack();
			}
			else if (randomizer.currentNum <= 5) //If the random number is equal to or less than 5 then the attack misses.
			{
				cout << "Attack missed!" << endl;
			}
		}
	} while ((ryu.alive == true) && (marvelous.alive == true)); //This loop continues while both of the characters are alive. It ends when one is defeated.
	if (marvelous.alive == true) //If we lose then we get a game over message.
	{
		marvelous.talk("Bwaahaha! I guess ninjas aren't as cool as pirates. I may not be taking your gold but I am taking your honor!", 6);
		cout << "\t\t*Game Over*" << endl;
		return 0; //This ends the game.
	}
	ryu.talk("Haha! I am victorious!", 11);
	timer();
	boss.talk("Who dares to awaken me from my slumber!", 4); //This will show the next phase has started.
	timer();
	marvelous.talk("Uhoh! we may have to fight together to get away from this.", 6);
	ryu.resetter(); //Reset the ninja.
	marvelous.resetter(); //Reset the pirate.
	timer();
	boss.Help();
	do //The second loop is for this boss fight.
	{
		if (ryu.alive == true) //If the ninja is still alive then we can have him attack the boss.
		{
			cin >> response;
			if (response == "hit")
			{
				ryu.ThrowStars();
				boss.Attack();
				ryu.alive == false;
			}
		}
		if (boss.alive == true && ryu.alive == true) //If the boss and ninja are alive then it will attack the ninja.
		{
			randomizer.randomNum(10);
			if (randomizer.currentNum > 5)
			{
				boss.Slash();
				ryu.Attack();
			}
			else if (randomizer.currentNum <= 5)
			{
				cout << "Attack missed!" << endl;
			}
		}
		if (marvelous.alive == true) //If the pirate is alive then it can attack.
		{
			cin >> response;
			if (response == "hit")
			{
				marvelous.UseSword();
				boss.Attack();
			}
		}
		if (boss.alive == true && marvelous.alive == true) //If the boss and pirate are alive then it will attack the pirate.
		{
			randomizer.randomNum(10);
			if (randomizer.currentNum > 5)
			{
				boss.Slash();
				marvelous.Attack();
			}
			else if (randomizer.currentNum <= 5)
			{
				cout << "Attack missed!" << endl;
			}
		}
	} while ((ryu.alive == true || marvelous.alive == true) && (boss.alive == true)); //If both the pirate and ninja are defeated or the boss is defeated the loop ends.
	if (boss.alive == true) //Game over message if we lose.
	{
		boss.talk("Finally I am able to get some rest.", 4);
		cout << "\t\t*Game Over*" << endl;
		return 0;
	}
	ryu.talk("We did it!", 11);
	timer();
	marvelous.talk("I guess you're not so bad after all.", 6);
	timer();
	ryu.talk("Come on let's go get something to eat.", 11);
	timer();
	marvelous.talk("Now you're talking some sense.", 6);
	cout << "\t\t*The End*" << endl;
	return 0;
}