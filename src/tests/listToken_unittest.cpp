#include "gtest/gtest.h"

#include "lib/listToken.h"

#include "lib/lexer.h"

#include "lib/TypeToken.h"

#include <cstring>

#include <sstream>

TEST(get_name, the_first)
{
	string str;
	Lexer l;
	TypeToken type =  l.defineTypeToken(2);
	listToken token("n", type, 1, 1);

	str = token.get_name();

	EXPECT_EQ("n", str);
}

TEST(get_type, the_first)
{
	Lexer l;
	TypeToken res;
	TypeToken type =  l.defineTypeToken(2);
	listToken token("n", type, 1, 1);

	res = token.get_type();

	EXPECT_EQ(type, res);
}

TEST(get_x, the_first)
{
	Lexer l;
	int res;
	TypeToken type =  l.defineTypeToken(2);
	listToken token("n", type, 1, 1);

	res = token.get_x();

	EXPECT_EQ(1, res);
}

TEST(get_y, the_first)
{
	Lexer l;
	int res;
	TypeToken type =  l.defineTypeToken(2);
	listToken token("n", type, 1, 1);

	res = token.get_y();

	EXPECT_EQ(1, res);
}

