
#include "Zoo.h"
#include <ctime>
#include <cstdlib>

int main()
{	
	std::srand((unsigned int) std::time(nullptr));
	Zoo z;
	z.run();
	return 0;
}
