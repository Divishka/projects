#include "Data.hpp"

int main()
{
//creating a valid data structure
	Data x;
	x.number = 200584;
	x.smth = "Gefdhjdfhfdgego";

//takes a Data address and use serialize on it
	uintptr_t ptr = serialize(&x);
	
//sends the return value in deserialize
	Data* neww = deserialize(ptr);

//check the return value is equal to the first pointer
	std::cout << "string - " << neww->smth << std::endl << "number - "  << neww->number<< std::endl;
	
	return (0);
}

