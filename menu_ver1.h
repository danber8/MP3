#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cctype>
#include <iterator>
#include <sstream>

using namespace std;

struct menu{
	vector<string> playlist;
	vector<string> songs;
	int total = 0;
	int numSongs;
	char text = '0'; //initializes the text to be a 0 char
	char background = '0'; //initializes the background to be a 0 char

	void menu::add() //this pushes things into the stack I think if im not wrong
	{
		playlist.push_back("Sun"); // Daniel's Song
		playlist.push_back("Gwyn"); // Josep's Songs
		playlist.push_back("Ludwig");
		playlist.push_back("Nice_Song"); // Bertak's Song
		playlist.push_back("Hey_Jude"); // Sami's Song
		playlist.push_back("Shining"); // Mical's Song
		playlist.push_back("Shape of You"); // Maisha's Song
		playlist.push_back("Pirates"); // Cyrus' Song
		playlist.push_back("Corpus Christi Bay");
		playlist.push_back("Dol");
		playlist.push_back("I'll be there for you");
		playlist.push_back("Previous Song");
		playlist.push_back("Random Song");
		playlist.push_back("Set Volume");
		playlist.push_back("Autoplay");
		playlist.push_back("Shuffle Play");
		playlist.push_back("Customize Text Color");
		playlist.push_back("Customize Background Color");
		playlist.push_back("Remove");
		playlist.push_back("Play Favorites");
		playlist.push_back("Quit");
	}
	
	string display(){
		int song;
		int i = 0;
		songs.erase(songs.begin(), songs.end());
		cout << endl << "Songs:  \n";
		
		while (i < (int)playlist.size())
		{
			if (playlist[i].compare("Previous Song") == 0)
			{
				numSongs = i;
				cout << endl << "Options:  \n";
				while (i < (int)playlist.size())
				{
					cout << i + 1 << ". " << playlist[i] << endl;
					i++;
					total++;
				}
			}
			else
			{
				cout << i + 1 << ". " << playlist[i] << endl;
				songs.push_back(playlist[i]);
				i++;
			}
			total++;
		}
		do
		{
			cout << endl << "Please enter your selection: ";
			cin >> song;
			if (!(cin.good()) || song > total || song < 1)
			{
				cerr << "ERROR: Invalid selection.\n\n";
				cout << song << "\n";
			}
		} 
		while (song > total || song < 1 || !(cin.good()));
		return playlist[(song) - 1];
	}

	string random()
	{
		int ran = 0;
		srand(time(NULL));
		ran = rand() % numSongs; 
		return playlist[ran];
	}

	int randRange(int r)
	{
		int ran = 0;
		srand(time(NULL));
		ran = rand() % r;
		return ran;
	}

	void setColor()  //sets the color of the text while remembering the users background color
	{
		int color;
		cout << "1 = Blue\n"
			<< "2 = Green\n"
			<< "3 = Aqua\n"
			<< "4 = Red\n"
			<< "5 = Purple\n"
			<< "6 = Yellow\n"
			<< "7 = White\n"
			<< "8 = Gray\n"
			<< "9 = Light Blue\n"
			<< "10 = Light Green\n"
			<< "11 = Light Aqua\n"
			<< "12 = Light Red\n"
			<< "13 = Light Purple\n"
			<< "14 = Light Yellow\n"
			<< "15 = Bright White\n";
		cout << "Please enter what color you'd like the text:  ";
		cin >> color;
		if (color == 1)
		{
			text = '1';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
			
		}
		else if (color == 2)
		{
			text = '2';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 3)
		{
			text = '3';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 4)
		{
			text = '4';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 5)
		{
			text = '5';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 6)
		{
			text = '6';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 7)
		{
			text = '7';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 8)
		{
			text = '8';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 9)
		{
			text = '9';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 10)
		{
			text = 'A';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 11)
		{
			text = 'B';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 12)
		{
			text = 'C';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 13)
		{
			text = 'D';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 14)
		{
			text = 'E';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 15)
		{
			text = 'F';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (!cin.good() || color > 15 || color < 1)
		{
			cout << "Invalid Option... Chosing default color bright white";
			system("COLOR 0F");
		}
	}

	void setBackgroundColor() 
	{  //sets the background color while remembering the users text color choice 
		int color;
		cout << "1 = Blue\n"
			<< "2 = Green\n"
			<< "3 = Aqua\n"
			<< "4 = Red\n"
			<< "5 = Purple\n"
			<< "6 = Yellow\n"
			<< "7 = White\n"
			<< "8 = Gray\n"
			<< "9 = Light Blue\n"
			<< "10 = Light Green\n"
			<< "11 = Light Aqua\n"
			<< "12 = Light Red\n"
			<< "13 = Light Purple\n"
			<< "14 = Light Yellow\n"
			<< "15 = Bright White\n";
		cout << "Please enter what color you'd like the background:  ";
		cin >> color;
		if (color == 1)
		{	
			string color = "COLOR 1";
			color += text;
			system(color.c_str());
			background = '1';
		}
		else if (color == 2)
		{
			string color = "COLOR 2";
			color += text;
			system(color.c_str());
			background = '2';
		}
		else if (color == 3)
		{
			string color = "COLOR 3";
			color += text;
			system(color.c_str());
			background = '3';
		}
		else if (color == 4)
		{
			string color = "COLOR 4";
			color += text;
			system(color.c_str());
			background = '4';
		}
		else if (color == 5)
		{
			string color = "COLOR 5";
			color += text;
			system(color.c_str());
			background = '5';
		}
		else if (color == 6)
		{
			string color = "COLOR 6";
			color += text;
			system(color.c_str());
			background = '6';
		}
		else if (color == 7)
		{
			string color = "COLOR 7";
			color += text;
			system(color.c_str());
			background = '7';
		}
		else if (color == 8)
		{
			string color = "COLOR 8";
			color += text;
			system(color.c_str());
			background = '8';
		}
		else if (color == 9)
		{
			string color = "COLOR 9";
			color += text;
			system(color.c_str());
			background = '9';
		}
		else if (color == 10)
		{
			string color = "COLOR A";
			color += text;
			system(color.c_str());
			background = 'A';
		}
		else if (color == 11)
		{
			string color = "COLOR B";
			color += text;
			system(color.c_str());
			background = 'B';
		}
		else if (color == 12)
		{
			string color = "COLOR C";
			color += text;
			system(color.c_str());
			background = 'C';
		}
		else if (color == 13)
		{
			string color = "COLOR D";
			color += text;
			system(color.c_str());
			background = 'D';
		}
		else if (color == 14)
		{
			string color = "COLOR E";
			color += text;
			system(color.c_str());
			background = 'E';
		}
		else if (color == 15)
		{
			string color = "COLOR F";
			color += text;
			system(color.c_str());
			background = 'F';
		}
		else if (!cin.good() || color > 15 || color < 1)
		{
			cout << "Invalid Option... Chosing default background color black";
			system("COLOR 0F");
		}
	
		else if (background == text)
		{
			cout << "Cannot add the same color";
		}

	}

};

