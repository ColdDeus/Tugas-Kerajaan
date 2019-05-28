/*
File	: nbtree_d.h
Author	: SN
Diubah oleh : Ilham Triza Kurniawan(181511016) dan Rifqi Yuner (181511030)
Last Updt : 14-5-2019



*/

#include <limits.h>
#include <malloc.h>
#include "nbtree_d.h"

void SearchPerson(nbAddr person, char* searchedPerson){
	nbAddr parentLocation, theLastChild;
	bool official, found;
	official = true;
	found = false;
	if(strcmp((person)->info.name, searchedPerson) == 0){
		found = true;
	}else{ 
		if(person->fs != NULL){
			do{
				if(person->fs != NULL && official){		
					person = person->fs;
					if(strcmp(person->info.name, searchedPerson) == 0){
						found=true;
					}
				}else{
					if(person->nb != NULL){
						person = person->nb;
						if(strcmp(person->info.name, searchedPerson)==0){
							found=true;
						}
						official = true;
					}else{
						person = person->parent;
						official = false;
					}
								}
			}while(person->parent != NULL && !found);
		}
	}
	
	
}
void Print_Raja(nbAddr person, char* searchedPerson)
{
		nbAddr parentLocation, theLastChild;
	bool official, found;
	official = true;
	found = false;
	if(strcmp((person)->info.name, searchedPerson) == 0){
		found = true;
	}else{ 
		if(person->fs != NULL){
			do{
				if(person->fs != NULL && official){		
					person = person->fs;
					if(strcmp(person->info.name, searchedPerson) == 0){
						found=true;
					}
				}else{
					if(person->nb != NULL){
						person = person->nb;
						if(strcmp(person->info.name, searchedPerson)==0){
							found=true;
						}
						official = true;
					}else{
						person = person->parent;
						official = false;
					}
								}
			}while(person->parent != NULL && !found);
		}
	}
	if (found && (strcmp (person->info.status,"Alive") == 0) )
	{
		printf("Name\t\t\t\t: %s\nRoman Catholic\t\t\t: ",person->info.name);
		if(person->info.roman == '1'){
			printf("Yes");
		} else{
			printf("No");
		}
		printf("\nGender\t\t\t\t: ");
		if(person->info.gender == '1'){
			printf("Male\n");
		}else printf("Female\n");
		if(person->parent != NULL){
			printf("Parent Name\t\t\t: %s\n",(person->parent)->info.name);
		}
		if(person->fs != NULL){
			person = person->fs;
			printf("First Child\t\t\t: %s\n",person->info.name);
			theLastChild = person;
			while(theLastChild->nb != NULL){
				theLastChild = theLastChild->nb;
			}
			if(theLastChild != person){
				printf("Last Child\t\t\t: %s",theLastChild->info.name);
			}
		}
		
	}
	else 
	{
		if (person->fs != NULL)
		{
			person = person->fs;
		}
		printf("Name\t\t\t\t: %s\nRoman Catholic\t\t\t: ",person->info.name);
		if(person->info.roman == '1'){
			printf("Yes");
		} else{
			printf("No");
		}
		printf("\nGender\t\t\t\t: ");
		if(person->info.gender == '1'){
			printf("Male\n");
		}else printf("Female\n");
		if(person->parent != NULL && strcmp(person->parent->info.name,"1") != 0  ){
			printf("Parent Name\t\t\t: %s\n",(person->parent)->info.name);
		}
		if(person->fs != NULL){
			person = person->fs;
			printf("First Child\t\t\t: %s\n",person->info.name);
			theLastChild = person;
			while(theLastChild->nb != NULL){
				theLastChild = theLastChild->nb;
			}
			if(theLastChild != person){
				printf("Last Child\t\t\t: %s",theLastChild->info.name);
			}
		}
	}
	
		
	
}
void RelatePerson(nbAddr *person, nbAddr theChild, char* searchedPerson){
	nbAddr parentLocation;
	bool official, found;

	official = true;
	found = false;
	parentLocation = *person;
	if(strcmp((*person)->info.name, searchedPerson) == 0){
		found = true;
	}else{
		if(parentLocation->fs != NULL){
			do{
				if(parentLocation->fs != NULL && official){		
					parentLocation = parentLocation->fs;
					if(strcmp(parentLocation->info.name, searchedPerson) == 0){
						found=true;
					}
				}else{
					if(parentLocation->nb != NULL){ 
						parentLocation = parentLocation->nb;
						if(strcmp(parentLocation->info.name, searchedPerson) == 0){
							found=true;
						}
						official = true;
					}else{
						parentLocation = parentLocation->parent;
						official = false;
					}
				}
			}while(parentLocation->parent!=NULL && !found);
		}
	}
	if(found){
		theChild->parent = parentLocation;
		if(parentLocation->fs == NULL){
			parentLocation->fs = theChild;
		}else{
			parentLocation = parentLocation->fs;
			while(parentLocation->nb != NULL){
				parentLocation = parentLocation->nb;
			}
			parentLocation->nb = theChild;
		}
	}else{
		free(theChild);
		printf("\nParent not found!");
	}
}

void ReadPersonFromFile(nbAddr *person){
	dataperson data;
	FILE *file;
	file = fopen("person.txt", "r");
	if(file == NULL){
		printf("Error!");
		exit(1);
	}
	while(fread(&data, sizeof(data), 1, file)){
		if(!(strcmp(data.parentname, "NULL"))){
			InputPerson(&(*person), data);	
		}else{
			nbAddr Theperson;
			nbCreate(&Theperson);
			if(!IsEmpty(Theperson)){
				InputPerson(&Theperson, data);
			}
			RelatePerson(&(*person), Theperson, data.parentname);
		}
	}		
	fclose(file);
}

void WritePersonToFile(dataperson data){
	FILE *file;
	file = fopen("person.txt", "a+");
	if(file == NULL){
		printf("Error!");
		exit(1);
	}
	fwrite(&data, sizeof(data), 1, file);	
	fclose(file);
}

void InputPerson(nbAddr *person, dataperson data){
	strcpy((*person)->info.name, data.name);
	/*(*person)->info.dayOfBirth= data.dayOfBirth;
	(*person)->info.monthOfBirth= data.monthOfBirth;
	(*person)->info.yearOfBirth= data.yearOfBirth;*/
	(*person)->info.roman= data.roman;
	(*person)->info.gender = data.gender;
	strcpy((*person)->info.parentname, data.parentname);
	(*person)->fs = NULL;
	(*person)->parent = NULL;
	(*person)->nb = NULL;
}

bool IsEmpty(nbAddr person){
	if(person == NULL){
		return true;
	}else{
		return false;	
	} 
}

void nbCreate(nbAddr *person){	
	*person = (nbAddr) malloc(sizeof(family));
}


void PrintLineOfSuccession(nbAddr root){
	nbAddr pCur;
	bool resmi;
	int number = 0;
		
	pCur = root;
	printf("\nCurrent Line Of Succession\t:\n\n");
//	printf("(%d)\t %s\n", number, pCur->info.name);
	resmi = true;
	do{ 
		if(pCur->fs != NULL && resmi)
		{
			pCur = pCur->fs;
			if(pCur->info.roman == '0')
			{
				number++;
				printf("(%d)\t %s\n", number, pCur->info.name);	
			}
		} 
	  else if(pCur->nb != NULL)
		{
				pCur = pCur->nb;
			if(pCur->info.roman == '0')
				{
					number++;
					printf("(%d)\t %s\n", number, pCur->info.name);	
				}
				resmi = true;
		} 
			else
			{
				pCur = pCur->parent;
				resmi = false;
			}
	} while(pCur->parent != NULL);
}

void nbLevelOrder(nbAddr root,int curLevel, int desLevel)
{
	if(root!=NULL)
	{
		if(curLevel==desLevel)
			printf("%d  ",root->info);
		nbLevelOrder(root->fs,curLevel+1,desLevel);
		nbLevelOrder(root->nb,curLevel,desLevel);
	}
}

void nbPrint(nbAddr node, char tab[]){
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "\t");
	if (node!=NULL){
		printf("%s --[%s]\n",tab,node->info.name);
		nbPrint(node->fs,tempTab);
		nbPrint(node->nb,tab);
	}
}
