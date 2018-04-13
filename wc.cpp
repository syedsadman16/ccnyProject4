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
 * #hours: 5
 */
#include <iostream>
#include <string>
#include <locale> //isspace 
using std::string;
#include <set>
using std::set;
#include <getopt.h> // to parse long arguments.
#include <cstdio> // printf
#include <vector>
#include <map>
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
				int bytes(); //initialize function
				cout << bytes(); //print contents of function			
				break;
			case 'l': //count lines -l
				linesonly = 1;
				int lines();
				cout << lines();
				break;
			case 'w': //call -w to count words
				wordsonly = 1;
				int words();
				cout << words();
				break;
			case 'u': //count unique words -u
				uwordsonly = 1;
				int unique();
				cout << unique();
				break;
			case 'L': //count longest line -L
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
	
	//This is the default when no --argument is specified
	//prints lines, words, bytes
	string text;
	int letterCount = 0;
	int space = 0;
	int totalLetters = 0;
	int lineCount = 1;
	int wordsCount = 0;

	while(getline(cin,text)) {
		for(int i = 0; i < text.size(); i++){
			if(isspace(text[i])){
			space++;
			wordsCount++;
			}
			else {
			letterCount++;
			}
			if(text[i] == '\n')
			++lineCount;
			
	}
		totalLetters = space + letterCount;
		cout << lineCount << " " <<  wordsCount + 1 << " " <<  totalLetters  << " " <<  text  <<"\n"; 
		//reset all the values for next string
		space = 0; 
		wordsCount = 0;
		lineCount = 1; 
		letterCount = 0;	

	}


			return 0;
} //end main function

//function to count number of bytes
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

//function to count number of words
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

//function to count number of lines
int lines(){
	string wrd; 
	int linesNumbr = 1; 
	while(getline(cin,wrd)){
		for(int i = 0; i<wrd.size(); i++){
			if(wrd[i] == '\n')
			linesNumbr++;
		}
			cout << linesNumbr<<"\n";
			linesNumbr = 1;
			}
}//end line function


int unique(){

	map<string,int> test;
	string uniq;

	while(cin >> uniq){
		test[uniq]++; //add uniq to map
		for(map<string,int>::iterator i = test.begin(); i != test.end(); i++) {
				cout << (*i).first << ":\t" << (*i).second << "\n";
			//test.clear();

			}
			
	}		


}//end function

//function to count longest line
#if 0
int longest(){
	string line; 
	int longest;
	int maxwords = 0;
	int counts = 0;
	vector<string> str;
	
	while(getline(cin, line)){
		line.push_back(str);
		for(int i =0; i<str.size(); i++){
			for(int j = 1; j < line.size() - 1; j++){
			if(isspace(str[i][j]){
			maxwords++;
			}
			else {
			counts++;
			}
			}
		if(counts + maxwords > longest)
	//	cout << "
		}	
	} //end while loop
} //end function
#endif
