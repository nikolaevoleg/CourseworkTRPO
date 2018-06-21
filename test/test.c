#define CTEST_MAIN

#include <stdbool.h>
#include <string.h>
#include "../thirdparty/ctest.h"
#include "../source/functions.h"
#include "../source/game.h"

CTEST(INPUT_VALIDATION, FINE_INPUT)
{
	char ch = 'a';
	bool result = dotcheck(ch);
	ASSERT_FALSE(result);
}

CTEST(NUMPOINTS_COINCIDENCE, T_POINTS)
{
	int result = checkStringsNum(2);
	int expected = 0;
	ASSERT_EQUAL(expected, result);
}

int main(int argc, const char** argv) 
{ 

	return ctest_main(argc, argv); 

}


