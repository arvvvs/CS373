#include "verma_p1.h"
#include <iostream>
#include <list>
#include <string>
#include <string.h>
#include <fstream>
#include <cctype>
#include <sstream>
#include <stdexcept>
verma_p1::verma_p1(string ifile){
	iFile.open(ifile);
	if(!iFile.is_open()){
		cerr<<"error in opening file"<<endl;
	}

    
}
void verma_p1::helloWorld(){
	cout<<"hello world"<<endl;
}

