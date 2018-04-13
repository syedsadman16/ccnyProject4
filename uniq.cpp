#include <cstdio>
#include <getopt.h> // to parse long arguments.
#include <string>
using std::string;
#include <iostream>
#include <map>
using std::map;
#include <vector>
#include <set>
#include<iomanip>
using std::setw;
using std::set;
using namespace std;


static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of uniq.  Supported options:\n\n"
"   -c,--count         prefix lines by their counts.\n"
"   -d,--repeated      only print duplicate lines.\n"
"   -u,--unique        only print lines that are unique.\n"
"   --help             show this message and exit.\n";


//Functions Prototypes:
void Counter();
void dups();
void uniq();
void none();
void CU();
void CD();

// Global Variables:
map<string,int> F; /* store frequency table */
string s; /* hold an input */

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
	//=====================================================================
	/* TODO: write me... */


	if(!showcount && !dupsonly && !uniqonly) none();
	else if (dupsonly && uniqonly) return 0; // contradiction!!!!
	else if (showcount && dupsonly) CD();
	else if (showcount && uniqonly) CU();
	else if (showcount) Counter();
	else if (uniqonly) uniq();
	else if (dupsonly) dups();

	//=====================================================================

	return 0;
}




	void Counter()
	{
				while (getline(cin,s)) F[s]++;
				// just print it out:
				for (map<string,int>::iterator i = F.begin(); i != F.end(); i++) {
				if (i->second == 1){

						cout << setw(7) << (*i).second << " " << (*i).first << endl;
				}
				if(i->second != 1){

						cout << setw(7) << i->second << " " << i->first << endl;
				}
			}
	}

	void dups()
	{
				while (getline(cin,s)) F[s]++;
				// just print it out:
				for (map<string,int>::iterator i = F.begin(); i != F.end(); i++) {
				if (i->second != 1){
						string Duplicate = i->first; // Managing an invariant;

						cout << Duplicate << endl;
				}else{
						// do nothing no unique's to be shown!!!
				}
			}
		}

	void uniq()
	{
				while (getline(cin,s)) F[s]++;
				// just print it out:
				for (map<string,int>::iterator i = F.begin(); i != F.end(); i++) {
				if (i->second == 1){
							string Unique = i-> first;

							cout << Unique << endl;
			}else{
					// do nothing here no duplicates to be shown!!!
			}
		}
	}
	void none(){

			while (getline(cin,s)) F[s]++;
			// just print it out: No numbers!!!
			for (map<string,int>::iterator i = F.begin(); i != F.end(); i++) {
			if(i->second == 1){
						// This one prints the Unique ONLY
							cout << (*i).first << endl;
				}
			if(i->second != 1){
						string Duplicate = i->first; // Managing an invariant;
						// This one prints the Duplicate's ONLY
						cout << Duplicate << endl;
				}
		}
}

	void CU() {


			while (getline(cin,s)) F[s]++;
			// just print it out:
			for (map<string,int>::iterator i = F.begin(); i != F.end(); i++) {
					if (i->second == 1){
						// This one prints the numbers and the unique!
						cout << setw(7) << (*i).second << " " << (*i).first << endl;
					}
			}
	}

	void CD() {

					while (getline(cin,s)) F[s]++;
					// just print it out:
					for (map<string,int>::iterator i = F.begin(); i != F.end(); i++) {
					if (i->second != 1){
						// This one prints out the number and the duplicate!
						cout << setw(7) << (*i).second << " " << (*i).first << endl;
					}
			}
	}


