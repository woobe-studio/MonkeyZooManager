#include "monke.hpp"

Zoo::Zoo(){

}
Zoo::~Zoo(){

}

int Space::setCapacity(int newCapacity){
	if(newCapacity<count)
		return 1;
	else{
		count=newCapacity;
		return 0;
	}
}

