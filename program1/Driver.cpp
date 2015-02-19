#include<cctype>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include "verma_p1.h"
using namespace std;

int main(int argc, char *argv[]){
	string ifile;
	string ofile;
	if(argc==2){
		cout<<ifile<<endl;

	}
	else{
		cout<<"wrong number of commands"<<endl;
		return -1;
	}
	verma_p1 Hello(ifile);
	Hello.helloWorld();
}
