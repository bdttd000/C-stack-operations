#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum FIELDS {
	AUTOMATYKA_I_ROBOTYKA,
	INFORMATYKA_STOSOWANA,
	INZYNIERIA_BEZPIECZENSTWA,
	INZYNIERIA_MEDYCZNA,
	INZYNIERIA_PRODUKCJI,
	INZYNIERIA_SRODKOW_TRANSPORTU,
	INZYNIERIA_WZORNICTWA_PRZEMYSLOWEGO,
	MECHANIKA_I_BUDOWA_MASZYN,
	POJAZDY_SAMOCHODOWE,
	SYSTEMY_I_URZADENIA_PRZEMYSLOWE,
	GOSPODARKA_PRZESTRZENNA,
	INZYNIERIA_CZYSTEGO_POWIETRZA,
	FIELDS_END
};

static char *fields[] = { 
	"Automatyka i robotyka", 
	"Informatyka stosowana", 
	"Inzynieria bezpieczenstwa", 
	"Inzynieria medyczna", 
	"Inzynieria produkcji", 
	"Inzynieria srodkow transportu", 
	"Inzynieria wzornictwa przemyslowego", 
	"Mechanika i budowa maszyn",
	"Pojazdy samochodwe",
	"Systemy i urzadzenia przemyslowe",
	"Gospodarka przestrzenna",
	"Inzynieria czystego powietrza"
};

typedef struct MY_STUDENT MY_STUDENT;

struct MY_STUDENT {
	char *lastname;
	int year;
	enum FIELDS field;
};

void *MY_STUDENT_Init(char *llastname, int year, enum FIELDS field);
void MY_STUDENT_Free(void *ptr);
void * MY_STUDENT_Push(char *lastname, int year, enum FIELDS field);
void MY_STUDENT_Print(void *ptr);
void MY_STUDENT_Set_Lastname(void* ptr, char* lastname);
int MY_STUDENT_Search(void *pCurData, void *pSearchData);
char *MY_STUDENT_Get_Lastname(void *ptr);
int MY_STUDENT_Get_Year(void *ptr);
enum FIELDS MY_STUDENT_Get_Field(void *ptr);