/*
 * Author: darrengiles
 * Description: Choose-your-own-adventure style Role Playing Game
 */


#include "pch.h"
#include <string>
#include <Windows.h>
#include <iostream>
#include <vector>

using namespace std;

class Scenario
{
	public:
		string name;
		string lines;
		vector<string> options;
		
};

int main()
{

	// Declare Name and heart meter strings
	string username;
	string hearts = "<3 <3 <3";
	int heart = 3;

	//controll variables
	int pointer = 0;
	int textColor = 15;
	//int stat = 1;

	//setup scenarios
	Scenario start;
	start.name = "start";
	start.lines = "It's your first day on the job, its time to get this farmer's life on the road!";
	start.options.push_back("Go farm");
	start.options.push_back("Go to the market");
	start.options.push_back("Go beat your dog... if that's what you're into...");

	Scenario t1s1;//track 1 scene 1
	t1s1.name = "t1s1";
	t1s1.lines = "Okay, so you start farming and you're doing a good job. Really!\nThen out of nowhere a vicious sea bear comes into view... its only a matter of time before it spots you- think fast! ";
	t1s1.options.push_back("Attack!");
	t1s1.options.push_back("Hide!");
	t1s1.options.push_back("Keep farming, maybe it respects a working man");

	Scenario t2s1;
	t2s1.name = "t2s1";
	t2s1.lines = "An old man walks up to your stand and asks 'Hey whadaya selling?";
	t2s1.options.push_back("'Apples, Oranges, and celery'");
	t2s1.options.push_back("'What does it look like?'");
	t2s1.options.push_back("Don't say anything.");

	Scenario t3s1;
	t3s1.name = "t3s1";
	t3s1.lines = "So your dog ended up messing you up. He knawed all over your arm and once you finally escaped his chopping jawls, you realized you're bleeding all over.";
	t3s1.options.push_back("Go to the hospital");
	t3s1.options.push_back("Sleep it off");
	t3s1.options.push_back("Get the gun");

	Scenario current = start;



	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//intro to game
	cout << "What is your name?\n";
	getline(cin, username, '\n'); //gets user's name
	cout << "Hello " << username << ". A great danger awaits before you...\n";
	//enter more story information
	system("PAUSE"); //pause

	//Main Loop, continually displays event and response options
	while (heart > 0)
	{
		if (heart == 3)
		{
			hearts = "<3 <3 <3";
			textColor = 15;
		}
		else if (heart == 2)
		{
			hearts = "<3 <3";
			textColor = 15;
		}
		else if (heart == 1)
		{
			hearts = "<3";
			textColor = 12;
		}
		//Displays current event
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);

		cout << username << ": " << hearts << endl << endl;
		cout << current.lines << endl;
		//cout << lines[q] << lines [r] << endl << endl;

		//Response Option input
		
		for (int i = 0; i < current.options.size(); i++)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				cout << current.options[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << current.options[i] << endl;
			}
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 3)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_SPACE) != 0)
			{
				switch (pointer)
				{
				case 0:
				{
					if (current.name == "start")
					{
						current = t1s1;
					}
					else
					{
						cout << "hey";
					}
					Sleep(250);
					break;
				}
				case 1:
				{
					if (current.name == "start")
					{
						current = t2s1;
					}
					else
					{
						cout << " rut row";
					}
					Sleep(250);
					break;
				}
				case 2:
				{
					if (current.name == "start")
					{
						current = t3s1;
						heart = heart - 2;
					}
					else
					{
						cout << "rut row ronce ragain";
					}
					Sleep(250);
					break;
				}
				}
			}

				break;
		}
			Sleep(150);
	}
		return 0;
}
