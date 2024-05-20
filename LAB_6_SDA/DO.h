#pragma once

typedef int TCheie;
typedef int TValoare;

#define NULL_TVALOARE -1
#define MAX 10

#include <utility>
typedef std::pair<TCheie, TValoare> TElem;

class Iterator;

typedef bool(*Relatie)(TCheie, TCheie);

class Nod {
private:
	TElem e;
	Nod* urm;
public:
	friend class DO;
	friend class Iterator;

	Nod(TElem e, Nod* urm) : e{ e }, urm{ urm } {}
};


class DO {
	friend class Iterator;
private:
	/* aici e reprezentarea */
	int m, size; // numarul de locatii din tabela de dispersie
	Nod* lis[MAX];
	Relatie rel;

	int dispersie(TCheie c) const;

public:

	// constructorul implicit al dictionarului
	DO(Relatie r);


	// adauga o pereche (cheie, valoare) in dictionar
	//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
	// daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
	TValoare adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
	TValoare cauta(TCheie c) const;


	//sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
	TValoare sterge(TCheie c);

	//returneaza numarul de perechi (cheie, valoare) din dictionar
	int dim() const;

	//verifica daca dictionarul e vid
	bool vid() const;

	// se returneaza iterator pe dictionar
	// iteratorul va returna perechile in ordine dupa relatia de ordine (pe cheie)
	Iterator iterator() const;


	// destructorul dictionarului
	~DO();

};
