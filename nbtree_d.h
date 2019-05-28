/*
File	: nbtree_d.h
Author	: SN
Diubah oleh : Ilham Triza Kurniawan(181511016) dan Rifqi Yuner (181511030)
Last Updt : 14-5-2019
*/

#ifndef nbtree_d_H
#define nbtree_d_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct nbTreeNode *nbAddr;
typedef char nbType[45];

typedef struct {
	nbType name;
	char gender;
	char roman;
	nbType parentname;
	nbType status;
}dataperson;

typedef struct nbTreeNode{
	dataperson info;
	nbAddr fs; //First child
	nbAddr nb; //Next brother
	nbAddr parent;
	nbAddr raja; //address yang akan menunjuk raja atau pewaris
}family;


bool IsEmpty(nbAddr person);

void nbCreate(nbAddr *person);
// Alokasi satu orang


/* ---------------- Operasi-operasi Tree ---------------- */
void InputPerson(nbAddr *person, dataperson data);
// Menambah element pada node parent

void RelatePerson(nbAddr *person, nbAddr theChild, char* searchedPerson);
//mengubungkan

void SearchPerson(nbAddr person, char* searchedPersonName);
// Mencari node dengan info ttn dan mengembalikan addressnya

void PrintLineOfSuccession(nbAddr root);
//menampilkan current line of succession

void WritePersonToFile(dataperson data);
void ReadPersonFromFile(nbAddr *person);
void Print_Raja(nbAddr person, char* searchedPerson);
void nbLevelOrder(nbAddr root,int curLevel, int desLevel); // Levelorder traversing

/* ---------------- PRINT TREE ---------------- */
void nbPrint(nbAddr node, char tab[]);



#endif
