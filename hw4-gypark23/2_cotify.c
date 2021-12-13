
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/*
2_cotify.c
12198215
Kyu Park
*/

typedef struct _Artist
{
	char name[50];
	int birth_year;
}Artist;

typedef struct _Song
{
	char title[100];
	Artist artist;
	int length;
}Song;


typedef struct _Album
{
	char title[100];
	Artist artist;
	int release_year;
	Song* songs;
}Album;


void welcome();
void load();
int numberOfAlbums(char name[]);
int numberOfSongs(char name[]);
//variable to indicate whether welcome() was called for the first time or not
int isFirstRun = 1;
//album array size is currently 4. Read readme
const int ALBUMSIZE = 4;
//maximum song numbers per album is currently 3. Read readme
const int MAXSONGSPERALBUM = 3;
//album array size is currently 4. Read readme
Album albums[4];


int main()
{
	load();
	assert(numberOfAlbums("Taylor Swift") == 1);
	assert(numberOfAlbums("Random Artist") == 0);
	assert(numberOfSongs("Taylor Swift") == 3);
	assert(numberOfSongs("Randomn Artist") == 0);
	welcome();
}


void welcome()
{
	//maximum input length 500
	char input[500];
	char* command;
	char* temp_name;

	if (isFirstRun == 1)
	{
		printf("** Welcome to Cotify -- the CS152 music information service. To learn more about our music,");
		printf(" please enter \"albums < artist>\", \"songs < artist>\", or \"artists\". **\n");
		printf("To exit the program, type \"close\". \n");
		isFirstRun = 0;
	}
	else
	{
		printf("\nPlease enter another selection: \n");
	}

	gets(input);
	printf("\n");

	//separates command and name. Command is whatever letter that comes before space, temp_name is whatever comes after "
	temp_name = strchr(input, '\"');
	command = strtok(input, " ");

	//below three checks the name first. If both case and name were incorrect, throws name error first 
	//if command is close, terminates the program regardless of what comes after the word "close".
	if ((strncmp(command, "close", 5) == 0) && (strlen(command) == 5))
	{
		printf("** Thank you for using Cotify! Goodbye! **");
		exit(0);
	}
	//if strchr for " was null, means name was not surrounded by quotation marks, so throws error
	if (temp_name == NULL)
	{
		printf("Name not found! Please enter two arguments, first command and then name separated by space\n");
		welcome();
	}
	//if temp_name length is 1, means there was only one quotation mark at the end
	//checks if last character was ", if not, means the name wasn't surrounded by quotation marks, so throw error
	if (strlen(temp_name) == 1 || (temp_name[strlen(temp_name) - 1] != '\"'))
	{
		printf("Invalid format of name! Please ensure that your name is surrounded by two quotation marks\"\n");
		welcome();
	}

	//removes both quotation marks from temp_name, and assign it name. Name will be used throughout the program.
	char* name = temp_name;
	name++[strlen(temp_name) - 1] = 0;

	//checks command
	if ((strncmp(command, "albums", 6) == 0) && (strlen(command) == 6))
	{
		//number of album found
		int albumNum = numberOfAlbums(name);
		//if and elses for gramatically correct sentence
		if (albumNum == 1)
		{
			printf("%s has created ", name);
			for (int i = 0; i < ALBUMSIZE; i++)
			{
				if ((strcmp(albums[i].artist.name, name) == 0))
				{
					printf("%s (%d).", albums[i].title, albums[i].release_year);
					//since there's only one occurence, break once found immediately to save time
					break;
				}
			}
		}
		else if (albumNum > 1)
		{
			printf("%s has created ", name);
			for (int i = 0; i < ALBUMSIZE; i++)
			{
				if ((strcmp(albums[i].artist.name, name) == 0))
				{
					if (albumNum > 1)
					{
						printf("%s (%d), ", albums[i].title, albums[i].release_year);
						albumNum--;
					}
					else
					{
						//last occurence has different sentence structure
						printf("and %s (%d).\n", albums[i].title, albums[i].release_year);
						break;
					}
				}
			}
		}
		//album not found
		else
		{
			printf("Album not found! Please try again!\n");
			printf("Make sure you have inputted correct name surrounded by quotation marks \"\n");
		}
		printf("\n");
		welcome();
	}
	else if ((strncmp(command, "songs", 5) == 0) && (strlen(command) == 5))
	{
		//number of songs by the given artist found
		int songNum = numberOfSongs(name);
		if (songNum > 0)
		{
			for (int i = 0; i < ALBUMSIZE; i++)
			{
				for (int j = 0; j < MAXSONGSPERALBUM; j++)
				{
					if ((strcmp(albums[i].artist.name, name) == 0))
					{
						printf("Song: %s -- %d -- Artist: %s -- Album: %s\n", albums[i].songs[j].title,
							albums[i].songs[j].length, albums[i].songs[j].artist.name, albums[i].title);
					}
				}
			}
		}
		else
		{
			printf("Song not found! Please try again!\n");
			printf("Make sure you have inputted correct name surrounded by quotation marks \"\n");
		}
		welcome();
	}
	else if ((strncmp(command, "artists", 7) == 0) && (strlen(command) == 7))
	{
		int numSongs = numberOfSongs(name);
		//two memory variables that remembers the i and j index at the for loops bellow
		int imemory = 0;
		int jmemory = 0;

		if (numSongs > 0)
		{
			for (int i = 0; i < ALBUMSIZE; i++)
			{
				for (int j = 0; j < MAXSONGSPERALBUM; j++)
				{
					if (strcmp(albums[i].songs[j].artist.name, name) == 0)
					{
						//extracts the first i and j index when the song is found and breaks immediately
						//this is to find the artist efficiently by searching through the song
						imemory = i;
						jmemory = j;
						break;
					}
				}
			}
			printf("Artist: %s -- Born: %d -- Number of songs in Cotify: %d\n", albums[imemory].songs[jmemory].artist.name,
				albums[imemory].songs[jmemory].artist.birth_year, numSongs);
		}
		else
		{
			printf("Artist not found! Please try again!\n");
			printf("Make sure you have inputted correct name surrounded by quotation marks \"\n");
		}
		welcome();
	}
	//name was given correctly with quotation marks but command was not found
	else
	{
		printf("Command not found! Invalid command input: please try again!\n");
		welcome();
	}
}


void load()
{
	//read readme for malloc usage
	Artist TaylorSwift = { "Taylor Swift", 1989 };
	Song* TaylorSongs = (Song*)malloc(sizeof(Song) * MAXSONGSPERALBUM);
	Song the1 = { "the 1", TaylorSwift, 210 };
	Song Cardigan = { "Cardigan", TaylorSwift, 240 };
	Song TheLast = { "the last great american dynasty", TaylorSwift, 231 };
	TaylorSongs[0] = the1;
	TaylorSongs[1] = Cardigan;
	TaylorSongs[2] = TheLast;
	Album Folklore = { "Folklore", TaylorSwift, 2020, TaylorSongs };
	albums[0] = Folklore;

	Artist Logic = { "Logic", 1990 };
	Song* LogicSongs = (Song*)malloc(sizeof(Song) * MAXSONGSPERALBUM);
	Song NoPressure = { "No Pressure", Logic, 176 };
	Song HitMyLine = { "hit my line", Logic, 265 };
	Song GP4 = { "GP4", Logic, 274 };
	LogicSongs[0] = NoPressure;
	LogicSongs[1] = HitMyLine;
	LogicSongs[2] = GP4;
	Album NoPressureAlbum = { "No Pressure", Logic, 2020, LogicSongs };
	albums[1] = NoPressureAlbum;

	Artist JuiceWrld = { "Juice Wrld", 1998 };
	Song* JuiceSongs = (Song*)malloc(sizeof(Song) * MAXSONGSPERALBUM);
	Song Anxiety = { "Anxiety", JuiceWrld, 70 };
	Song Conversations = { "Conversations", JuiceWrld, 212 };
	Song Titanic = { "Titanic", JuiceWrld, 177 };
	JuiceSongs[0] = Anxiety;
	JuiceSongs[1] = Conversations;
	JuiceSongs[2] = Titanic;
	Album LegendsNeverDie = { "Legends Never Die", JuiceWrld, 2019, JuiceSongs };
	albums[2] = LegendsNeverDie;

	Artist PopSmoke = { "Pop Smoke", 1999 };
	Song* PopSongs = (Song*)malloc(sizeof(Song) * MAXSONGSPERALBUM);
	Song BadBitch = { "Bad Bitch From Tokyo", PopSmoke, 48 };
	Song Aim = { "Aim For The Moon", PopSmoke, 176 };
	Song ForTheNight = { "For The Night", PopSmoke, 191 };
	PopSongs[0] = BadBitch;
	PopSongs[1] = Aim;
	PopSongs[2] = ForTheNight;
	Album ShootFor = { "Shoot for the Stars, Aim for the Moon", PopSmoke, 2020, PopSongs };
	albums[3] = ShootFor;
}


//finds the number of albums of the given name of artist
int numberOfAlbums(char name[])
{
	int albumNum = 0;

	for (int i = 0; i < ALBUMSIZE; i++)
	{
		if ((strcmp(albums[i].artist.name, name) == 0))
		{
			albumNum++;
		}
	}

	return albumNum;
}

//finds the number of songs of the given name of artist
int numberOfSongs(char name[])
{
	int found = 0;

	for (int i = 0; i < ALBUMSIZE; i++)
	{
		for (int j = 0; j < MAXSONGSPERALBUM; j++)
		{
			if (strcmp(albums[i].songs[j].artist.name, name) == 0)
			{
				found++;
			}
		}
	}

	return found;
}