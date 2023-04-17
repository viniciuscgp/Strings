#ifndef STRINGS_GUARD
#define STRINGS_GUARD

typedef struct Cargo {
	int code;
	char name[255];
	double price;
	void (*ToString)(struct Cargo* self);
} TCargo;

typedef struct List {
	TCargo* cargo;
	struct List * next;
} TList;

int InitCargo(TCargo* cargo, int code, char* name, double price, void (*ToString)(struct Cargo* self));

int AddToList(TList** list, TCargo* cargo);

void DisplayList(TList* list);

void PrintCargo(TCargo* cargo);

void PrintCargoNoPrice(TCargo* cargo);

#endif
