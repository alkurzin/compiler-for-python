#pragma once

#include <cstring>
#include "TypeToken.h"

using namespace std;


class listToken{
	private:
		string name;
		TypeToken type;
		int x;
		int y;
	public:
		listToken(string name_2, TypeToken type_2, int x_2, int y_2);
		string get_name();
		TypeToken get_type();
		int get_x();
		int get_y();
};

