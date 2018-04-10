#include <cstdio>
#include <getopt.h> // to parse long arguments.
#include <string>
using std::string;
#include <iostream>
#include <map>
using namespace std;


static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of uniq.  Supported options:\n\n"
"   -c,--count         prefix lines by their counts.\n"
"   -d,--repeated      only print duplicate lines.\n"
"   -u,--unique        only print lines that are unique.\n"
"   --help             show this message and exit.\n";



int Couning_Uniq()
{
	map<string,int> Map1; /* store frequency table */
	string Sentence; /* hold an input */
	while (cin >> Sentence) Map1[Sentence]++;
		/* now just print F... */
	for (map<string,int>::iterator it = Map1.begin(); it != Map1.end(); it++) {
		cout << (*it).first << ":\t" << (*it).second << "\n";
	}

	return 0;
}



int main(int argc, char *argv[]) {

	// define long options
	static int showcount=0, dupsonly=0, uniqonly=0;
	static struct option long_opts[] = {
		{"count",         no_argument, 0, 'c'},
		{"repeated",      no_argument, 0, 'd'},
		{"unique",        no_argument, 0, 'u'},
		{"help",          no_argument, 0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "cduh", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'c':
				showcount = 1;
				break;
			case 'd':
				dupsonly = 1;
				break;
			case 'u':
				uniqonly = 1;
				break;
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}

	//==============================================================================
	//==============================================================================

	/* Thought Process: There are 2 strings and that are being compared using the equality test. This is still a work in progress, since whenever I ouput a particular sentence with same words it DOES NOT work properly yet. However this does compile! I will be working on this throughout the weekend. I was wondering if we need to use sets or maps instead, but I'm struggling on how to implement them. However, I will keep working on this overnight ... so use git pull.
	*/

	// WE NEED TO USE INDUCTION HERE for n amount of inputs -- getline ???


	int Couning_Uniq(); // Fucntion Call: Counts all the inputs;

	string Sentence;
	std::getline (std::cin,Sentence); // reads line;
	int Counter;
	std::map<string, int> Map1; // map that holds the sentence.
	Map1.insert(pair<string, int> (Sentence, Counter));
	// Syntax Reference: std::getline (std::cin,name);








/*
	// Print the duplicate words -- using std::cout (standard output):
	// Print the unique words -- using std::cout (standard output):
	for (map<string, int>::iterator it = Map1.begin(); it != Map1.end(); it++) {
		// The Second Value is the integer number of --> Counter
				if(it->second == 1) {
						cout << "Now printing Unique words: :D ... " << endl;
						cout << it->first << " " << flush;
						cout << endl; // For formatting purposes.
				}
				if(it->second != 1) {
						cout << "Now printing Duplicate words: :D ... " << endl;
						cout << it->first << " " << flush;
				}
				else {
					cout << "Invalid argument :D ... " << endl;
				}
				cout << endl; // For formatting purposes.
		}
*/

	return 0;
  }






