#include "Portfolio3.h"

#include <cassert>
using namespace std;

//test 1
void test2A() {

	Port3 test1(2, 2, 2, 3, 2);
	test1.makefirstcells();

	assert(true);
}

// test 2

void test2B() {
	Port3 test2(5, 4, 3, 2, 3);
	test2.makefirstcells();
	test2.movetogeneration();
	assert(true);
}














int main() {

	test2A();
	cout << "Tests completed.";

	return 0;


}