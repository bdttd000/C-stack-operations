
typedef struct MY_STACK MY_STACK;

struct MY_STACK{
	void *pData;
	MY_STACK *next;	
};

typedef void(*FreeData)(void *pdat);
typedef int (CompData)(void * pcurData, void * pSearchData);

void MY_STACK_Init(FreeData pFreeDat);
void MY_STACK_Free();
MY_STACK * MY_STACK_Push(void *pdat);
MY_STACK MY_STACK_Pop();
void * MY_STACK_Search(void *pSearchDat, CompData ptr_comp_fun, int FirstEntry);
void MY_STACK_Save();
void MY_STACK_Load();
void MY_STACK_Print();
void MY_STACK_Print_Main();
void MY_STACK_Print_Top();