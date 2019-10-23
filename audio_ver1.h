// Import necessary librairies 
#include "SDL.h"
#include <iostream>

using namespace std;

// Represents the global pointer to the audio buffer to be played stored in an unsigned integer of 8 bits
static Uint8 *audio_pos;
// Remaining length of the sample left to play stored in an unsigned integer of 32 bits
static Uint32 audio_len; 
// Global prototype for the audio callback function
void my_audio_callback(void *userdata, Uint8 *stream, int len);
// Global prototype for the changeVol function
bool changeVol(int level);
// Length of the sample
static Uint32 wav_length; 
// Buffer containing the audio file stored in an unsigned integer of 8 bits
static Uint8 *wav_buffer; 
// The specs of the song
static SDL_AudioSpec wav_spec; 
int vol = 128;

// Constructor creating a song object
class song 
{
private:
	// Title refers to the full title of the song with the proper directory
	string title;
	// Path is the C-string required to play the song using SDL 
	const char* path;
	// Properly closes the song
	void close()
	{
		SDL_CloseAudio();
		SDL_FreeWAV(wav_buffer);
	}

public:
	// Name stores a record of just the song's name, with the path information
	string name;
	// Rating simply holds the rating for the song
	int rating = 0;
	// Basic constructor for song class
	song() {};
	// Basic deconstructor for song class
	~song() {};
	// Main constructor used to initialize a song using its base name
	song(string title)
	{
		this->name = title;
		// Adds all the necessary tags to make it playable for the path
		this->title = "Playlist/" + title + ".wav";
	}

	// Initialize SDL. Returns false if everything wasn't initialized correctly.
	bool init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			return false;
		}
		else
		{
			cout << "Successful init!\n";
			path = title.c_str();
			return true;
		}
	}

	// Loads the WAV
	bool load()
	{
		// Fills in the specs, buffer, and length of the WAV
		if (SDL_LoadWAV(path, &wav_spec, &wav_buffer, &wav_length) == NULL)
		{
			// Prints an error if it didn't load properly
			fprintf(stderr, "Could not open test.wav: %s\n", SDL_GetError());
			return false;
		}
		else
		{
			// Sets the callback function
			wav_spec.callback = my_audio_callback;
			wav_spec.userdata = NULL;
			// Sets the global static variables
			// Copies the sound buffer
			audio_pos = wav_buffer;
			// Copies the file length
			audio_len = wav_length; 
			return true;
		}
	}

	// Secures the audio output device
	bool setDevice()
	{
		// Open's the audio device 
		if (SDL_OpenAudio(&wav_spec, NULL) < 0)
		{
			// Prints an error if it didn't set device properly
			fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
			return false;
		}
		return true;
	}

	// Actually plays the song
	// Lets the User pause, resume , return to menu, et al. functions 
	bool play() 
	{
		// Start playing 
		SDL_PauseAudio(0);
		// Initializes playing components
		bool done = false;
		char choice;
		// While there's still audio to play and the User is not done with the song play the audio
		while (audio_len > 0 && !(done))
		{
			SDL_Delay(100);
			cin >> choice;
			// If they choose 'p', pause the song
			if (choice == 'p')
			{
				SDL_PauseAudio(1);
				cout << "Song paused..." << endl;
			}
			// If they choose 'u', unpause the song
			else if (choice == 'u')
			{
				SDL_PauseAudio(0);
				cout << "Song resumed..." << endl;
			}
			// If they choose 'q', quit out of the song
			else if (choice == 'q')
			{
				done = true;
				cout << "Returning to menu..." << endl;
			}
			// If they choose 'r', rate the song
			else if (choice == 'r')
			{
				setRating();
			}
			// If they choose 'x', exit out of the song and return to menu
			else if (choice == 'x')
			{
				SDL_PauseAudio(0);
				close();
				// Returns true that the user wants to exit out of the song
				return true;
			}
			// If they choose 'v', let the user change the volume
			else if (choice == 'v')
			{
				int newVol = -1;
				cout << "Please enter the volume you'd like to play the song at (0-8):  ";
				cin >> newVol;
				if (!(changeVol(newVol)))
				{
					cout << "Invalid volume selection...\n";
				}
			}
		}
		// After the ong is done playing, properly close the file and return false
		close();
		return false;
	}

	// Sets what the user wants to rate the song
	void setRating()
	{
		do
		{
			cout << "\nPlease enter your rating for the song (1 for thumbs up, -1 for thumbs down, 0 for neutral):  ";
			cin >> rating;
			if (rating != 1 && rating != -1 && rating != 0 || !cin.good())
			{
				cout << "Invalid rating.. Please try again\n";
			}
		} while (rating != 1 && rating != -1 && rating != 0 || !cin.good());
		cout << "Rating for song: " << name << " set to " << rating << endl;
	}
};

// Copies the data from the audio buffer into the stream
void my_audio_callback(void *userdata, Uint8 *stream, int len)
{
	// Silences the stream
	SDL_memset(stream, 0, len); 
	// If the song is over, pause the song and allows the user to exit out
	if (audio_len == 0)
	{
		SDL_PauseAudio(1);
		cout << "\nEnter anything to continue...";
		return ;
	}
	len = (len > (int) audio_len ? audio_len : len);
	// Simply copies from one buffer into the other
	SDL_MixAudio(stream, audio_pos, len, vol);
	audio_pos += len;
	audio_len -= len;
}

// Chances the volume level with 8 being the highest and 0 being mute
bool changeVol(int level) 
{
	int dial = SDL_MIX_MAXVOLUME / 16;
	if (level > 8 || level < 0 || !cin.good())
	{
		return false;
	}
	else
	{
		vol = dial * level;
		cout << "Volume set successfully!\n";
		return true;
	}
}