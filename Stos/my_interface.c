#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_student.h"
#include "my_stack.h"
#include "my_interface.h"
#include "my_errors.h"

#pragma warning (disable : 4996)

static char *strtab[] = {
	"0 - Push         |  (Dodaje element do stosu)                                                     ",			//INTERF_PUSH
	"1 - Pop          |  (Usuwa gorny element ze stosu)                                                ",			//INTERF_POP
	"2 - Clear        |  (Czysci stos)                                                                 ",			//INTERF_CLEAR
	"3 - Find         |  (Szuka elementu w stosie)                                                     ",			//INTERF_FIND
	"4 - Save         |  (Zapisuje stos do pliku)                                                      ",			//INTERF_SAVE
	"5 - Load         |  (Zaczytuje stos z pliku, UWAGA! Funkcja nie czysci stosu tylko dodaje na gore)",			//INTERF_LOAD
	"6 - Clear & Load |  (Zaczytuje stos z pliku, UWAGA! Funkcja czysci stos)                          ",			//INTERF_LOAD_CLEAR
	"7 - Print        |  (Wyswietla caly stos)                                                         ",			//INTERF_PRINT
	"8 - Print top    |  (Wyswietla gorny element stosu)                                               ",			//INTERF_PRINT_TOP
	"9 - Finish       |  (Zamyka program)                                                              "			//INTERF_STOP
};

void menu(){
	size_t it;
	printf("\n\t======================================================================================================\n");
	for (it = 0; it < INTERF_TOT; ++it){
		printf("\t| %-15s |\n", strtab[it]);
	}
	printf("\t======================================================================================================\n");
}

void push(){

	char lastname[512];
	int year;
	int field;

	ENTER_YOUR_SURNAME();
	scanf("%s", lastname);

	ENTER_YEAR();
	scanf("%d", &year);

	printf("\n");

	for (int fieldList = 0; fieldList < FIELDS_END; ++fieldList) {
		printf("\t%d - %s\n", fieldList, fields[fieldList]);
	}

	ENTER_FIELD();
	scanf("%d", &field);

	while(NO_SUCH_FIELD_ERROR(field)) {
		ENTER_RIGHT_FIELD();
		scanf("%d", &field);
	}

	void *pdat = MY_STUDENT_Push(lastname, year, field);
	if (!MY_STACK_Push(pdat)) FAILED_TO_PUSH();
	else PUSH_SUCCESS();
}

void pop(){
	MY_STACK tmp = MY_STACK_Pop();
	if (tmp.pData) {
		POP_SUCCESS();
		MY_STUDENT_Print(tmp.pData);
		MY_STUDENT_Free(tmp.pData);
	} else {
		STACK_WAS_ALREADY_EMPTY();
	}
}

void find(){
	char str[128];
	int year = -1;
	int field = -1;
	MY_STUDENT search_st;
	memset(&search_st, 0, sizeof(MY_STUDENT));

	ENTER_SEARCH_DATA();

	scanf_s("%s", str, sizeof(str));
	stdin_clear();

	if (isdigit(str[0]))
	{
		int n = atoi(str);
		if (n >= 0 && n < FIELDS_END)
			field = n;
		else
			year = atoi(str);

		MY_STUDENT_Set_Lastname(&search_st, "");
	}
	else
		MY_STUDENT_Set_Lastname(&search_st, str);
	search_st.year = year;
	search_st.field = field;


	void* dataptr = MY_STACK_Search(&search_st, MY_STUDENT_Search, 1); //make a first search

	system("cls");
	int found = 0;

	if (dataptr) {
		MY_STUDENT_Print(dataptr);
		found = 1;
	}

	while (dataptr) {
		dataptr = MY_STACK_Search(&search_st, MY_STUDENT_Search, 0);
		if (dataptr) {
			MY_STUDENT_Print(dataptr);
			found = 1;
		}
	}

	if (found == 0) {
		STUDENT_NOT_FOUND();
	}
}

void clear(){
	MY_STACK_Free();
}

void save() {
	MY_STACK_Save();
}

void load() {
	MY_STACK_Load();
}

void load_clear() {
	MY_STACK_Load_Clear();
}

void print() {
	MY_STACK_Print();
}

void print_top() {
	MY_STACK_Print_Top();
}

void stdin_clear() {
	char ch;
	while ((ch = getchar()) != EOF && ch != '\n');
}