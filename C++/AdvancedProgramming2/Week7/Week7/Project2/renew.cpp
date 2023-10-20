#include "new.h"

renew::renew() : renew(1, "null", 0.f) {}

renew::renew(int num, string str, double g) {
	n = num;
	name = str;
	f = g;
}