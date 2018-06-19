#define CTEST_MAIN

#include <stdbool.h>
#include "../thirdparty/ctest.h"
#include <string.h>
#include "../source/functions.h"
#include "../source/game.h"

CTEST(INPUT_VALIDATION, FINE_INPUT)
{
	char ch = 'a';
	bool result = dotcheck(ch);
	ASSERT_FALSE(result);
}

int main(int argc, const char** argv) 
{ 

	return ctest_main(argc, argv); 

}


