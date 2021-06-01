#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "my_stack.h"
#include "my_student.h"
#include "my_errors.h"

#pragma warning (disable : 4996)

static MY_STACK *last = NULL;
FreeData ptr_free_dat;

void MY_STACK_Init(FreeData pFreeDat){
	last = NULL;
	ptr_free_dat = pFreeDat;
}

void MY_STACK_Free(){
	MY_STACK *p = last, *ptmp = NULL;
	if (!last) {
		STACK_WAS_ALREADY_EMPTY();
	} else {
		while (p) {
			(*ptr_free_dat)(p->pData);
			ptmp = p;
			p = p->next;
			free(ptmp);
		}
		last = NULL;
		CLEAR_SUCCESS();
	}
}

MY_STACK * MY_STACK_Push(void *pdat){
	MY_STACK *current = (MY_STACK *)malloc(sizeof(MY_STACK));
	if (!current)
		return NULL;

	current->next = last;
	current->pData = pdat;
	last = current;
	return current;
}

MY_STACK MY_STACK_Pop(){
	MY_STACK rv;
	if (!last){
		rv.pData = NULL;
		rv.next = NULL;
		return rv;
	}
	
	MY_STACK *next = last->next;
	rv.pData = last->pData;
	rv.next = NULL;
	free(last);
	last = next;
	return rv;
}

void * MY_STACK_Search(void *pSearchDat, CompData ptr_comp_fun, int FirstEntry){
	static MY_STACK *p;
	MY_STACK *ptmp = NULL;

	if (FirstEntry)
		p = last;

	while (p){
		if (!(*ptr_comp_fun)(p->pData, pSearchDat)){
			p = p->next;
		}
		else{
			ptmp = p;
			p = p->next;
			return ptmp->pData;
		}
	}
	return NULL;
}

void MY_STACK_Save() {
	MY_STACK *p = last, *ptmp = NULL;
	int length = 0;
	while (p) {
		ptmp = p;
		p = p->next;
		length++;
	}
	remove("data.bin");
	FILE *fptr;
	fptr = fopen("data.bin", "wb");

	if (fptr == NULL) {
		FILE_NOT_OPENED();
		return;
	}

	fwrite(&length, sizeof(int), 1, fptr);

	int i = 0;
	p = last;

	char* tab_lastname[128];
	int tab_year[128];
	enum FIELDS tab_field[128];

	while (i < length) {

		tab_lastname[i] = MY_STUDENT_Get_Lastname(p->pData);
		tab_year[i] = MY_STUDENT_Get_Year(p->pData);
		tab_field[i] = MY_STUDENT_Get_Field(p->pData);

		p = p->next;
		i++;
	}

	i--;

	while (i >= 0) {
		fwrite(tab_lastname[i], 512 * sizeof(char), 1, fptr);
		fwrite(&tab_year[i], sizeof(int), 1, fptr);
		fwrite(&tab_field[i], sizeof(enum FIELDS), 1, fptr);
		i--;
	}

	fclose(fptr);

	SAVE_SUCCESS();
}

void MY_STACK_Load() {
	
	FILE *fptr;

	fptr = fopen("data.bin", "rb");
	if (fptr == NULL) {
		FILE_NOT_OPENED();
		return;
	}
	int length;
	fread(&length, sizeof(int), 1, fptr);

	int i = 0;
	while (i < length) {
		char lastname[512];
		int year;
		enum FIELDS field;

		fread(lastname, 512*sizeof(char), 1, fptr);
		fread(&year, sizeof(int), 1, fptr);
		fread(&field, sizeof(enum FIELDS), 1, fptr);

		void *pdat = MY_STUDENT_Push(lastname, year, field);
		if (!MY_STACK_Push(pdat))
			FAILED_TO_PUSH();
		i++;
	}

	fclose(fptr);

	LOAD_SUCCESS();
}

void MY_STACK_Load_Clear() {
	MY_STACK_Free();
	MY_STACK_Load();
}

void MY_STACK_Print() {
	MY_STACK* temp_last = last;
	MY_STACK rv;

	system("cls");

	if (!temp_last) {
		STACK_IS_EMPTY();
	}

	while (temp_last) {
		MY_STACK* next = temp_last->next;
		rv.pData = temp_last->pData;
		temp_last = next;
		MY_STUDENT_Print(rv.pData);
	}
}

void MY_STACK_Print_Main() {
	MY_STACK* temp_last = last;
	MY_STACK rv;

	PRINT_BREAK();

	if (!temp_last) {
		STACK_IS_EMPTY();
	}

	while (temp_last) {
		MY_STACK* next = temp_last->next;
		rv.pData = temp_last->pData;
		temp_last = next;
		MY_STUDENT_Print(rv.pData);
	}

	PRINT_BREAK();
}

void MY_STACK_Print_Top() {
	MY_STACK rv;

	system("cls");

	if (last) {
		rv.pData = last->pData;
		MY_STUDENT_Print(rv.pData);
	} else {
		STACK_IS_EMPTY();
	}
}