#include "Iterator.h"
#include "DO.h"
#include <iostream>
#include <math.h>
#include <exception>
using namespace std;

int hash_code(TCheie c) {
	return abs(c);
}


DO::DO(Relatie r) {
	rel = r;
	m = MAX;
	size = 0;
	for (int i = 0; i < m; i++)
		lis[i] = nullptr;
}

int DO::dispersie(TCheie c) const{
	return hash_code(c) % m;
}

//adauga o pereche (cheie, valoare) in dictionar
//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
//daca nu exista cheia, adauga perechea si returneaza null
TValoare DO::adauga(TCheie c, TValoare v) {
	int disp = dispersie(c);

	Nod* nou = new Nod(TElem(c,v), nullptr);

	if (lis[disp] == nullptr) {
		lis[disp] = nou;
		size++;
		return NULL_TVALOARE;
	} else {
		Nod* p = lis[disp];
		while (p != nullptr) {
			if (p->e.first == c) {
				TValoare ve = p->e.second;
				p->e.second = v;
				return ve;
			}
			p = p->urm;
		}

		p = lis[disp];
		Nod* ant = nullptr;
		while (p != nullptr) {
			if (rel(p->e.first, c) == false)
				break;
			ant = p;
			p = p->urm;
		}
		if (p == lis[disp]) {
			nou->urm = p;
			lis[disp] = nou;
			size++;
			return NULL_TVALOARE;
		}
		else if (p != nullptr) {
			ant->urm = nou;
			nou->urm = p;
			size++;
			return NULL_TVALOARE;
		}
		else if (p == nullptr) {
			ant->urm = nou;
			size++;
			return NULL_TVALOARE;
		}

	}
}


TValoare DO::cauta(TCheie c) const {
	int disp = dispersie(c);

	Nod* p = lis[disp];
	while (p != nullptr) {
		if (p->e.first == c)
			return p->e.second;
		p = p->urm;
	}
	
	if (p == nullptr)
		return NULL_TVALOARE;
}

TValoare DO::sterge(TCheie c) {
	int disp = dispersie(c);
	if (lis[disp] == nullptr)
		return NULL_TVALOARE;

	if (lis[disp]->e.first == c) {
		Nod* p = lis[disp];
		lis[disp] = lis[disp]->urm;
		int v = p->e.second;
		size--;
		delete p;
		return v;
	}

	Nod* p = lis[disp];
	Nod* ant = nullptr;
	while (p != nullptr) {
		if (p->e.first == c)
			break;
		ant = p;
		p = p->urm;
	}

	if (p == nullptr)
		return NULL_TVALOARE;

	ant->urm = p->urm;
	size--;
	int v = p->e.second;
	delete p;
	return v;
}

int DO::dim() const {
	return size;
}

bool DO::vid() const {
	return size == 0;
}

Iterator DO::iterator() const {
	return  Iterator(*this);
}

DO::~DO() {
	for (int i = 0; i < m; i++) {
		while (lis[i] != nullptr) {
			Nod* p = lis[i];
			lis[i] = lis[i]->urm;
			delete p;
		}
	}
}
