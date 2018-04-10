/*
 * CSc103 Project 3: unix utilities
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: cplusplus.com  
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 
 */
#include <iostream>
#include <string>
#include <locale> //isspace 
using std::string;
#include <set>
using std::set;
#include <getopt.h> // to parse long arguments.
#include <cstdio> // printf
using namespace std;

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of wc.  Supported options:\n\n"
"   -c,--bytes            print byte count.\n"
"   -l,--lines            print line count.\n"
"   -w,--words            print word count.\n"
"   -L,--max-line-length  print length of longest line.\n"
"   -u,--uwords           print unique word count.\n"
"   --help          show this message and exit.\n";

int main(int argc, char *argv[])
{
	// define long options
	static int charonly=0, linesonly=0, wordsonly=0, uwordsonly=0, longonly=0;
	static struct option long_opts[] = {
		{"bytes",           no_argument,   0, 'c'},
		{"lines",           no_argument,   0, 'l'},
		{"words",           no_argument,   0, 'w'},
		{"uwords",          no_argument,   0, 'u'},
		{"max-line-length", no_argument,   0, 'L'},
		{"help",            no_argument,   0, 'h'},
		{0,0,0,0}
	};
	// process options: 
	char c;    //c is set to whatever param is used
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "clwuLh", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'c': //call -c to count bytes
				charonly = 1;
				int bytes();
				cout << bytes();			
				break;
			case 'l':
				linesonly = 1;
				break;
			case 'w': //call -w to count words
				wordsonly = 1;
				int words();
				cout << words();
				break;
			case 'u':
				uwordsonly = 1;
				break;
			case 'L':
				longonly = 1;
				break;
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}
	

		return 0;
} //end main function

int bytes(){
	string input; 
	int count = 0; 
	int whitespace = 0; 
	int total;

       while(getline(cin,input)){ //gets line of input 
		for(int i = 0; i < input.size(); i++){

			if(isspace(input[i])){
			whitespace++;
			}
			else {
			count++;
			}
	}
		total = count + whitespace;
		cout << total << "\n";
		count = 0;
		whitespace = 0;

       }

} //end bytes function

int words(){
	string word;
	int wordCount;
	while(getline(cin,word)){
		for(int i = 0; i < word.size(); i++){
			if(isspace(word[i]))
			wordCount++;
		}
		cout << wordCount + 1 << "\n";
		wordCount = 0;
		
	}

} //end words function
