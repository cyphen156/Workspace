#pragma once
#include <iostream>
#include <string>
#include "Circle.h"
#include "Line.h"
#include "Rect.h"
#include "Shape.h"

using namespace std;

int main() {
	Shape* pStart = new Shape();

	Shape* pLast = pStart;
	pLast = pLast->add(new Circle());
	pLast = pLast->add(new Rect());
	pLast = pLast->add(new Line());
	
	Shape* p = pStart;
	while (p != nullptr) {
		p->paint();
		p = p->getNext();
	}

	p = pStart;
	while (p != nullptr) {
		Shape* temp = p;
		p = temp->getNext();
		delete temp;
	}
	return 0;
}