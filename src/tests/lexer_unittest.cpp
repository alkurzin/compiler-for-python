#include "gtest/gtest.h"

#include "lib/lexer.h"

#include "lib/TypeToken.h"

#include <cstring>

#include <sstream>

TEST(defineTypeToken, the_first)
{
	Lexer l;
	TypeToken type =  l.defineTypeToken(2);

	EXPECT_EQ(2, type);
}
