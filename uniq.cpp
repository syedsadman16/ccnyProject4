#include <cstdio>
#include <getopt.h> // to parse long arguments.
#include <string>
using std::string;
#include <iostream>
#include <map>
using std::map;
#include <vector>
#include <set>
using std::set;
using namespace std;


static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of uniq.  Supported options:\n\n"
"   -c,--count         prefix lines by their counts.\n"
"   -d,--repeated      only print duplicate lines.\n"
"   -u,--unique        only print lines that are unique.\n"
"   --help             show this message and exit.\n";






int Counter();



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

	/* TODO: write me... */

	Counter(); // Function call to count words ...

	string input;
	getline(cin, input);
	string word;
	int count = 0;
	vector <string> test;
	vector <string> final;
	for(int i = 0; i < input.length(); i++){
		if(input[i]!= 32){
			word+=input[i];
			if(input[i] == input[input.length()-1]){
				test.push_back(word);
			}
		}

		else if(input[i]== 32){
			test.push_back(word);
			word.clear();
		}

		// map<data type, data type> name (parameters)'
		// map<string, int> Map1 (word, count);
		// map.insert();;;;

	}

	if(uniqonly = 1){
	for(int x = 0; x < test.size(); x++){

		if((test[x-1]!= test[x])&&(test[x]!=test[x+1])){

			cout << test[x] << endl;
		}
	}
}



	//duplicate
	count = 0;

	for(int x = 0; x < test.size(); x++){

		if((test[x] == test[x+1])&&(test[x] == test[x-1])){
			continue;
			}
		else if (test[x] == test[x-1]){
			continue;
			}
		else if((test[x] == test[x+1])&&(test[x] != test[x-1])){
				cout << test[x] << endl;
			}
		}

	return 0;
}



	int Counter()
{
	map<string,int> F; /* store frequency table */
	string s; /* hold an input */
	while (cin >> s) F[s]++;
	// just print it out:
	for (map<string,int>::iterator i = F.begin(); i != F.end(); i++) {
				if (i->second == 1){
							cout << endl << "Now printing unique: " << endl;
							cout << "-----------------------------" << endl;
							cout << (*i).first << " :\t" << (*i).second << endl;
				}else{
						cout << endl << "Now Printing duplicates: " << endl;
						cout << "---------------------------------" << endl;
						cout << i->first << " :\t" << i->second << endl;
				}
   }
		return 0;
	}



