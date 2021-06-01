#include "my_student.h"

#pragma warning (disable : 4996)

// WARNING or ERROR

int NO_SUCH_FIELD_ERROR(int field) {
	if (field > 11 || field<0) {
		printf("\n\tNie ma takiego kierunku\n");
		return 1;
	}
	return 0;
}

void FAILED_TO_PUSH() {
	system("cls");
	printf("\n\t====================================\n");
	printf("\t|   Nie udalo sie dodac elementu   |\n");
	printf("\t====================================\n");
}

void FILE_NOT_OPENED() {
	system("cls");
	printf("\n\t====================================\n");
	printf("\t|   Nie udalo sie otworzyc pliku   |\n");
	printf("\t====================================\n");
}

void STUDENT_NOT_FOUND() {
	system("cls");
	printf("\n\t======================================\n");
	printf("\t|   Nie udalo sie znalezc studenta   |\n");
	printf("\t======================================\n");
}

void UNKNOWN_OPERATION_CODE() {
	system("cls");
	printf("\n\t================================\n");
	printf("\t|   Niepoprawny kod operacji   |\n");
	printf("\t================================\n");
}

void STACK_WAS_ALREADY_EMPTY() {
	system("cls");
	printf("\n\t==========================\n");
	printf("\t|   Stos byl juz pusty   |\n");
	printf("\t==========================\n");
}

void PRINT_STUDENT_ERROR() {
	printf("\n\t=========================================\n");
	printf("\t|   Nie udalo sie wyswietlic studenta   |\n");
	printf("\t=========================================\n");
}


// INFORMATION

int PRINT_STUDENT(char* a, int b, char* c) {
	printf("\n\t============================================================\n");
	printf("\t| Nazwisko studenta : %-35s  |\n", a);
	printf("\t| Rok urodzenia     : %-35d  |\n", b);
	printf("\t| Kierunek studiow  : %-35s  |\n", c);
	printf("\t============================================================\n");
}

void PRINT_START_INFO() {
	printf("\n\tWYNIKI FUNKCJI ZAWSZE WYSWIETLA SIE TUTAJ\n");
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	printf("\tOBECNY STAN STOSU ZAWSZE WYSWIETLI SIE TUTAJ\n");
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
}

void PRINT_CHOOSE_FROM_TABLE() {
	printf("\n\tWybierz z listy: ");
}

void ENTER_YOUR_SURNAME() {
	printf("\n\tPodaj nazwisko: ");
}

void STACK_IS_EMPTY() {
	printf("\n\t=======================\n");
	printf("\t|   Stos jest pusty   |\n");
	printf("\t=======================\n");
}

void ENTER_SEARCH_DATA() {
	printf("\n\tPodaj nazwisko, rok urodzenia albo numer kierunku: ");
}

void PRINT_BREAK() {
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
}

void ENTER_YEAR() {
	printf("\n\tPodaj rok urodzenia: ");
}

void ENTER_FIELD() {
	printf("\n\tPodaj kierunek studiow: ");
}

void ENTER_RIGHT_FIELD() {
	printf("\n\tPodaj poprawny kierunek: ");
}

// SUCCESS

void POP_SUCCESS() {
	system("cls");
	printf("\n\t========================\n");
	printf("\t|   Usuniety element   |\n");
	printf("\t========================\n");
}

void PUSH_SUCCESS() {
	system("cls");
	printf("\n\t==============================\n");
	printf("\t|   Rekord dodany do stosu   |\n");
	printf("\t==============================\n");
}

void CLEAR_SUCCESS() {
	system("cls");
	printf("\n\t=========================\n");
	printf("\t|   Stos wyczyszczony   |\n");
	printf("\t=========================\n");
}

void LOAD_SUCCESS() {
	system("cls");
	printf("\n\t=====================\n");
	printf("\t|   Wczytano dane   |\n");
	printf("\t=====================\n");
}

void SAVE_SUCCESS() {
	system("cls");
	printf("\n\t=====================\n");
	printf("\t|   Zapisano dane   |\n");
	printf("\t=====================\n");
}