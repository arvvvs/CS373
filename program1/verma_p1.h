#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<map>
#include<fstream>
using namespace std;
class verma_p1 {

	private:
		ifstream iFile;
		vector<char> iTape;
	public:
		verma_p1(string ifile);
		~verma_p1();
		void helloWorld();
		void buildMachine();
		void buildTape(string tape);
		void initStates();
};
