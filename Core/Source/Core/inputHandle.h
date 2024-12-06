#pragma once
#include "Windows.h"

const short checkKey();

template<typename T>
short checkKeyMenu(T choice) {

	if (choice == 0) {
		return 0;
	}
	else {
		return choice;
	}

}
