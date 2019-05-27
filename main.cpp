
#include "nbtree_d.h"
void menu();
void Input_Orang();
int main() {
	nbAddr king, person,search;
	dataperson data;	
	char nama [45],namaortu[45],namaraja [45];
	char agama,jk,agamalol;
	
	FILE *file;
	file = fopen("person.txt", "ab+");
	if(fread (&data, sizeof(data), 1, file) == NULL){
		strcpy(data.name, "1");
		data.roman = 'NULL';
		data.gender = 'NULL';
		strcpy(data.status,"Death");
		strcpy(data.parentname,	"NULL");
		WritePersonToFile(data);
		printf("Masukkan Nama Raja/Ratu : ");
		scanf("%s",&nama);
		strcpy(data.name, nama);
		printf ("Masukkan Gender (P/L)");
		data.roman = '0';
		jk = getch();
		if (jk == 'P' || jk == 'p')
		{
			data.gender = '0';
		}
		else
		{
			data.gender = '1';
		}
		strcpy(data.status,"Alive");
		strcpy(data.parentname,	"1");
		WritePersonToFile(data);
		fflush(stdin);
		strcpy(namaraja,nama);
		system("cls");
	}
	fclose(file);
	
	menu();

	
	
	return 0;
}




void Input_Orang ()
{
	nbAddr king, person,search;
	dataperson data;
	char nama [45],namaortu[45],namaraja [45];
	char agama,jk,agamalol;
	
	printf("Masukkan Nama : ");
	scanf("%s",&nama);
	strcpy(data.name, nama);
	printf ("Apakah agamanya Kristen Protestan atau tidak ? (Y/N)");
	agamalol = getch();		
	//scanf ("%s",&agamalol);
	if (agamalol == 'y' || agamalol == 'Y')
		{
			printf("Beragama Kristen Protestan");
			data.roman = '0';
		}
		else if (agamalol == 'N' || agamalol == 'n')
		{
			printf("Tidak beragama Kristen Protestan");
			data.roman = '1';
		}
		printf("\n%c",data.roman);
		printf ("\nMasukkan Gender (P/L)");
		jk = getch();
		if (jk == 'P' || jk == 'p')
		{
			printf("Perempuan");
			data.gender = '0';
		}
		else
		{
			printf("Laki-laki");
			data.gender = '1';
		}	
		printf("\nMasukkan Nama Orangtua: ");
		scanf("%s",&namaortu);
		strcpy(data.parentname,	namaortu);	
		strcpy(data.status,"Alive");
		WritePersonToFile(data);	
		fflush(stdin);
		system("cls");
}


void List_Pewaris()
{
	nbAddr king, person,search;
	dataperson data;	
	char nama [45],namaortu[45],namaraja [45];
	char agama,jk,agamalol;
	nbCreate(&king);
	if(!IsEmpty(king))
	{
		ReadPersonFromFile(&king);
	}
	
	// Search Person
	char* searchedPerson = (char*) malloc(40 * sizeof(char*) + 1);
	strcpy(searchedPerson, "1");
	SearchPerson(king, searchedPerson);
	
	// Print Line Of Succession
	PrintLineOfSuccession(king->fs);
	
	
	
	printf("\n\n");
	system("pause");
}
void menu()
{
	
int pil;
	nbAddr king, person;
	dataperson data;

	
	while(1)
	{
		system("cls");	
		printf("\t===============================================\n");
		printf("\t||           Kerajaan Britania Raya           ||\n");
		printf("\t||                Insert Data                 ||\n");
		printf("\t||                   Menu                     ||\n");
		printf("\t||               1. Input Orang               ||\n");
		printf("\t||              2. Bunuh Orang                ||\n");
		printf("\t||          3. Tampil Silsilah Keluarga       ||\n");
		printf("\t||           4. Tampil List Pewaris           ||\n");
		printf("\t||            5. Tampil List Raja             ||\n");
		printf("\t||            6. Exit Program                 ||\n");
		printf("\t===============================================\n");
		pil = getche();
		printf("\n");
		switch(pil){
			case '1':{
				system ("cls");
				Input_Orang();
				break;
			}
			case '2':{
				system("cls");
				break;
			}
			case '3':{
				system("cls");
				break;
			}
			case '4' :{
				system("cls");
				List_Pewaris();
				break;
			}
			default :{
				exit(1);
			}
		
		//goto menu1;	
			}
	}
}
