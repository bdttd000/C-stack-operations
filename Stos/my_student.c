#include <stdlib.h>
#include <stdio.h>
#include "my_student.h"
#include "string.h"
#include "my_errors.h"

#pragma warning (disable : 4996)

void *MY_STUDENT_Init(char *lastname, int year, enum FIELD field){
	MY_STUDENT *student = (MY_STUDENT *)malloc(sizeof(MY_STUDENT));
	if(student->lastname = (char*)malloc(strlen(lastname)*sizeof(char))) {
		strcpy(student->lastname, lastname);
		student->year = year;
		student->field = field;
	}
	return (void *)(student);
}


void MY_STUDENT_Free(void* ptr) {
	MY_STUDENT* student = (MY_STUDENT*)ptr;
	if (student) {
		student->lastname = malloc(1);
		free(student->lastname);
		student->lastname = NULL;
		free(student);
		student = NULL;
	}
}

void * MY_STUDENT_Push(char *lastname, int year, enum FIELDS field){
	return MY_STUDENT_Init(lastname, year, field);
}

void MY_STUDENT_Print(void *ptr){
	MY_STUDENT *p = (MY_STUDENT *)ptr;
	if (p) {
		PRINT_STUDENT((char *)p->lastname, (int) p->year, (char *) fields[p->field]);
	} else {
		PRINT_STUDENT_ERROR();
	}
}

void MY_STUDENT_Set_Lastname(void* ptr, char* lastname)
{
	MY_STUDENT* student = (MY_STUDENT*)ptr;
	if (student) {
		student->lastname = (char *)realloc(student->lastname, strlen(lastname) * sizeof(char));		
		strcpy(student->lastname, lastname);
	}
}

char *MY_STUDENT_Get_Lastname(void *ptr) {
	MY_STUDENT *p = (MY_STUDENT *)ptr;
	return p->lastname;
}

int MY_STUDENT_Get_Year(void *ptr) {
	MY_STUDENT *p = (MY_STUDENT *)ptr;
	return p->year;
}

enum FIELDS MY_STUDENT_Get_Field(void *ptr) {
	MY_STUDENT *p = (MY_STUDENT *)ptr;
	return p->field;
}

int MY_STUDENT_Search(void *pCurData, void *pSearchData){
	MY_STUDENT *pcur = (MY_STUDENT *)pCurData;
	MY_STUDENT *psearch = (MY_STUDENT *)pSearchData;

	if (strcmp(pcur->lastname, psearch->lastname) == 0)
		return 1;

	if (pcur->year == psearch->year)
		return 1;

	if (pcur->field == psearch->field)
		return 1;

	return 0;
}