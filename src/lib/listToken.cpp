#include <iostream>
#include <fstream>
#include <cstring>
#include "listToken.h"

using namespace std;

listToken::listToken(string name_2, TypeToken type_2, int x_2, int y_2){
	name = name_2;
	type = type_2;
	x = x_2;
	y = y_2;
}

string listToken::get_name(){
	return name;
}

TypeToken listToken::get_type(){
	return type;
}

int listToken::get_x(){
	return x;
}

int listToken::get_y(){
	return y;
}

