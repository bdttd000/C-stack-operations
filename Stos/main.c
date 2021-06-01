#pragma once

#include <stdlib.h>
#include <string.h>

#include "my_interface.h"
#include "my_stack.h"
#include "my_student.h"
#include "my_errors.h"

#pragma warning (disable : 4996)

int main() {
	int op = 0;
	int start_info = 1;

	MY_STACK_Init(MY_STUDENT_Free);
	PRINT_START_INFO();
	
	while (1){
		if (start_info!=1) {
			MY_STACK_Print_Main();
		} else {
			start_info = 0;
		}
		menu();
		PRINT_CHOOSE_FROM_TABLE();
		scanf("%d", &op);
		switch (op)
		{
		case INTERF_PUSH: push();
			break;
		case INTERF_POP: pop();
			break;
		case INTERF_CLEAR: clear();
			break;
		case INTERF_FIND: find();
			break;
		case INTERF_SAVE: save();
			break;
		case INTERF_LOAD: load();
			break;
		case INTERF_LOAD_CLEAR: load_clear();
			break;
		case INTERF_PRINT: print();
			break;
		case INTERF_TOP: print_top();
			break;
		case INTERF_STOP: clear();
			return 0;
		default:
			UNKNOWN_OPERATION_CODE();
		};
	}
	printf("\n");
	system("pause");
	return 0;
}