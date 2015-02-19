#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<map>
#include<fstream>
#include<utility>

using namespace std;

class verma_p1{

	private:
		ifstream iFile;
		vector<char> iTape;
	typedef	pair <int, char> mapKey;
	typedef	pair <int, string> nextStep;
		map <mapKey, nextStep> machStorage;
	public:
		//map<mapKey, 
		verma_p1(string ifile);
		~verma_p1();
		void helloWorld();
		void buildMachine();
		void buildTape(string tape);
		void initStates();
		void transitionBuild();
};
