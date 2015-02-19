#include<cctype>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include "verma_p1.h"
using namespace std;

int main(int argc, char *argv[]){
	string ifile;
	string tape;
	if(argc==3){
		tape=argv[2];	
		ifile=argv[1];
	}
	else{
		cout<<"wrong number of commands"<<endl;
		return -1;
	}
	verma_p1 Hello(ifile);
	Hello.helloWorld();
	Hello.buildTape(tape);
	Hello.initStates();
	Hello.transitionBuild();
	Hello.run();
	return -1;
}
