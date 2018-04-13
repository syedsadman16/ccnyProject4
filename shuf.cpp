#include <cstdio>   // printf
#include <cstdlib>  // rand
#include <time.h>   // time
#include <getopt.h> // to parse long arguments.
#include <stdlib.h>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
#include <algorithm>
using std::swap;
using std::min;
using namespace std;

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of shuf.  Supported options:\n\n"
"   -e,--echo              treat each argument as an input line.\n"
"   -i,--input-range=LO-HI treat each number in [LO..HI] as an input line.\n"
"   -n,--head-count=N      output at most N lines.\n"
"   --help                 show this message and exit.\n";

int main(int argc, char *argv[]) {
	// define long options
	static int echo=0, rlow=0, rhigh=0;
	static size_t count=-1;
	bool userange = false;
	static struct option long_opts[] = {
		{"echo",        no_argument,       0, 'e'},
		{"input-range", required_argument, 0, 'i'},
		{"head-count",  required_argument, 0, 'n'},
		{"help",        no_argument,       0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "ei:n:h", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'e':
				echo = 1;
				break;
			case 'i':
				if (sscanf(optarg,"%i-%i",&rlow,&rhigh) != 2) {
					fprintf(stderr, "Format for --input-range is N-M\n");
					rlow=0; rhigh=-1;
				} else {
					userange = true;
				}
				break;
			case 'n':
				count = atol(optarg);
				break;
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}
	/* NOTE: the system's shuf does not read stdin *and* use -i or -e.
	 * Even -i and -e are mutally exclusive... */

	/* TODO: write me... */
	//manual input
	int t=0;
	if(echo==1){
		int x; string k;
		vector<string> V;

		while (optind < argc)
			V.push_back(argv[optind++]);

		srand(time(0));
		for(int i=0;i<V.size()-1;i++){
			x=rand()%(V.size()-i)+i;
			k=V[x];
			V[x]=V[i];
			V[i]=k;
			}
		for(int i=0;i<V.size();i++) cout<<V[i]<<'\n';
		}
		else if(rlow<=rhigh){
			int x; int k;
			vector<int> V2;
			for(int i=rlow;i<=rhigh;i++){
				V2.push_back(i);
				}
			srand(time(0));
			for(int i=0;i<V2.size()-1;i++){
				x=rand()%(V2.size()-i)+i;
				k=V2[x];
				V2[x]=V2[i];
				V2[i]=k;
				}
			for(int i=0;i<V2.size();i++) cout<<V2[i]<<'\n';
		}
		else if(count==atol(optarg)){
			int x; string k,s;
			vector<string> V3;
			while(cin>>s) V3.push_back(s);
			for(int i=0;i<V3.size()-1;i++){
				x=rand()%(V3.size()-i)+i;
				k=V3[x];
				V3[x]=V3[i];
				V3[i]=k;
			}
			if(count<=v=V3.size()){
				for(int i=0;i<count;i++){
					cout<<V3[i]<<'\n';
				}
			}
			else{
				for(int i=0;i<V3.size();i++) cout<<V3[i]<<'\n';
			}
		}
	return 0;
}
