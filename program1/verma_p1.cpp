#include "verma_p1.h"
#include <utility>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <string>
#include <string.h>
#include <fstream>
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <vector>
verma_p1::verma_p1(string ifile){
	iFile.open(ifile);
	if(!iFile.is_open()){
		cerr<<"error in opening file"<<endl;
	}

    
}
verma_p1::~verma_p1(){
}
void verma_p1::helloWorld(){
	//cout<<"hello world"<<endl;
}
void verma_p1::buildMachine(){

}
void verma_p1::buildTape(string tape){
	//cout<<tape<<endl;
	for(string::iterator it = tape.begin(); it != tape.end(); ++it){
		iTape.push_back(*it);
	}
}
void verma_p1::createStartState(){
	startState = make_pair(start, iTape.at(0));
	steppedStates.push_back(start);
}
void verma_p1::transition(){
	auto res = machStorage.find(startState);
	if(res != machStorage.end()){
		int nuState=res->second.first;
		string breakup = res->second.second;
		char nuChar = breakup.at(0);
		char turn = breakup[1];
		//cout<<turn<<endl;
		moveTape(turn, nuChar);
		if(nuState==accept){
			steppedStates.push_back(nuState);	
			being="accept";
			printStates();
		}
		else if(nuState==reject){
			steppedStates.push_back(nuState);
			being="reject";
			printStates();
		}
		else{
		startState = make_pair(nuState, iTape.at(atTape));
		steppedStates.push_back(nuState);
		//cout<<atTape<<endl;
		//cout<<"new state is "<<startState.first<<"character on tape"<<startState.second<<endl;
		}
	}

}
void verma_p1::moveTape(char turn, char nuChar){
	int xyz = iTape.size();
  	if(turn == 'L'){
		atTape--;
		if(atTape<0){
			being="bounds";
			printStates();			
			exit(EXIT_SUCCESS);
		}
		else{
			iTape.at(atTape+1)= nuChar;
		}

	}		
	else if(turn == 'R'){
	       atTape=atTape+1;
	       //cout<<atTape<<endl;
	       if(atTape>=xyz){
		       being="bounds";
		       printStates();
			exit(EXIT_SUCCESS);
	       }
	       else{
		       iTape.at(atTape-1)= nuChar;
	       }

	}	       
}

void verma_p1::initStates(){
	int temp=-1;
	string line;
	for(int i=0; i<3; i++){
		string useless1;
		string state;
		getline(iFile, line);
		stringstream hello(line);
		hello>>useless1>>temp>>state;
		if(state=="accept"){
			accept=temp;
			being="accept";
			//cout<<state<<endl;
			//cout<<accept<<endl;
		}
		else if(state=="reject"){
			reject=temp;
			being="reject";
			//cout<<state<<endl;
			//cout<<reject<<endl;
		}
		else if(state=="start"){
			start=temp;
			//cout<<state<<endl;
			//cout<<start<<endl;
		}
}
}
void verma_p1::transitionBuild(){
	string line;
	while(getline(iFile, line)){
		string useless1;
		int initState = -1;
		char readTape;
		int stepState = -1;
		char writeTape;
		char direction;
		string combineSaveMeGod = "";
		stringstream hello(line);
		hello>>useless1>>initState>>readTape>>stepState>>writeTape>>direction;
		combineSaveMeGod+=writeTape;
		combineSaveMeGod+=direction;
		machStorage[make_pair(initState, readTape)]=make_pair(stepState,combineSaveMeGod);
		/*
		auto res = machStorage.find(make_pair(0, 'x'));
		if(res != machStorage.end()){
		cout<<res->second.first<<" "<<res->second.second<<endl;
		}*/
	/*	cout<<initState<<endl;
		cout<<readTape<<endl;
		cout<<stepState<<endl;
		cout<<writeTape<<endl;
		cout<<direction<<endl;
		*/
	}
}
void verma_p1::storeState(int state){
	steppedStates.push_back(state);
}
int verma_p1::printStates(){
	int xyz=steppedStates.size();
	for(int i=0; i<xyz; i++){
		cout<<steppedStates.at(i);
		if(i!=xyz-1){
		cout<<"->";
		}
		else{
			cout<<" "<<being<<endl;
			exit(EXIT_SUCCESS);
		}
	}
	return 0;
}	
void verma_p1::run(){
	createStartState();
	while(transitionCount<=5000){
		transition();
		transitionCount++;
		
	}	
}
