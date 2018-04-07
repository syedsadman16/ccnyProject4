#include <cstdio>
#include <getopt.h> // to parse long arguments.
#include <string>
using std::string;
#include <iostream>
using namespace std;


static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of uniq.  Supported options:\n\n"
"   -c,--count         prefix lines by their counts.\n"
"   -d,--repeated      only print duplicate lines.\n"
"   -u,--unique        only print lines that are unique.\n"
"   --help             show this message and exit.\n";

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
	// My Code Starts from here:
	//==============================================================================

	/* Thought Process: There are 2 strings and that are being compared using the equality test. This is still a work in progress, since whenever I ouput a particular sentence with same words it DOES NOT work properly yet. However this does compile! I will be working on this throughout the weekend. I was wondering if we need to use sets or maps instead, but I'm struggling on how to implement them. However, I will keep working on this overnight ... so use git pull.
	*/

	string S1;
	string S2;  // WE NEED TO USE INDUCTION HERE for n amount of inputs -- getline ???
	string Unique;
	string Duplicate;
	// Syntax Reference: std::getline (std::cin,name);
	std::getline (std::cin,S1);
	std::getline (std::cin,S2);
	int temp;
	char p;

	//For unique strings
	if (S1.length() != S2.length()){
		Unique += S1;
		Unique += ' ';
		Unique += S2;
	}
	else if (S1[0] != S2[0]){
		Unique += S1;
		Unique += ' ';
		Unique += S2;
	}
	//for dup strings
	else if (S1[0] == S2[0]){
		for (int i=1; i < S1.length(); ++i){
			//if (S[i] == V[i]){
			//if a letter matches continue checking the next
			//continue;
			//}
			if (S1[i] != S2[i]) {
				// If there is a letter that does match they are not duplicates so add them to unique.
				Unique += S1;
				Unique += ' ';
				Unique += S2;
				break;
			}
			temp = i;
			// This will break when it finds it's duplicates or when i reaches the length of S and they are duplicates.
		}
		if (temp ==  S1.length()-1){
			Duplicate += S1;
			Duplicate += ' ';
			Duplicate += S2;
		}

	}

	// Print the unique words -- using std::cout (standard output):
	cout << "Now printing unique words: " << endl;
	for (int i=0; i < Unique.length(); i++){
		cout << Unique[i];
	}
	cout << endl; // For formatting purposes.

	cout << "Now printing duplicate words: " << endl;
	for (int i=0; i < Duplicate.length(); i++){
		cout << Duplicate[i];
	}
	cout << endl; // For formatting purposes.


	return 0;
}

