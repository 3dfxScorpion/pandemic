#include <iostream>
// #include "conio.h"  // does not compile on command line --Derrick

using namespace std;

int main() {
	cout << "This is a test! And now I made changes. Does git recognize this?" << endl;
	cout << "This is also a test! I've made additional changes... is this thing working?" << endl;
//	_getch();  // dependent on conio.h  --Derrick
  cin.get();   // replacement for _getch()  --Derrick
	return 0;
}
