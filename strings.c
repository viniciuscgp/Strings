#include "strings.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	TCargo cargo1;
	TCargo cargo2;
	TCargo cargo3;

	TList* list = NULL;

	InitCargo(&cargo1, 1, "Mouse Wireless", 44.50, NULL);
	InitCargo(&cargo2, 2, "Teclado Microsoft", 120.00, PrintCargoNoPrice);
	InitCargo(&cargo3, 3, "LED Monitor", 1250.00, NULL);

	AddToList(&list, &cargo1);
	AddToList(&list, &cargo2);
	AddToList(&list, &cargo3);

	DisplayList(list);

	return 0;

}

int InitCargo(TCargo* cargo, int code, char* name, double price, void (*ToString)(struct Cargo* self))
{
	if (!cargo) 
		return 1;

	cargo->code = code;
	strcpy_s(cargo->name, sizeof(cargo->name), name);
	cargo->price = price;
	if (ToString)
		cargo->ToString = ToString;
	else
		cargo->ToString = PrintCargo;

	return 0;
}

int AddToList(TList** list, TCargo* cargo)
{
	TList* ptr;
	TList* new_node;

	if (!cargo)
	{
		printf("Invalid Cargo pointer!\n");
		return 1;
	}

	new_node = (TList*)malloc(sizeof(TList));
	if (!new_node) {
		printf("List item allocation error\n");
		return 1;
	}

	new_node->cargo = cargo;
	new_node->next = NULL;

	if (*list == NULL)
	{
		*list = new_node;
		return 0;
	}

	ptr = *list;
	
	while (ptr->next != NULL) 
	{
		ptr = ptr->next;
	}

	ptr->next = new_node;

	return 0;
}

void DisplayList(TList* list)
{
	if (list == NULL) return;

	TList* ptr = list;

	while (ptr != NULL)
	{
		if (ptr->cargo)
		{
			if (ptr->cargo->ToString)
				ptr->cargo->ToString(ptr->cargo);
			else
				printf("Structure Cargo ToString() not defined!\n");
		}
		ptr = ptr->next;
	}
}

void PrintCargo(TCargo* cargo)
{
	printf("Code....: %d\n", cargo->code);
	printf("Name....: %s\n", cargo->name);
	printf("Price...: %10.2f\n\n", cargo->price);
}

void PrintCargoNoPrice(TCargo* cargo)
{
	printf("Code....: %d\n", cargo->code);
	printf("Name....: %s\n\n", cargo->name);
}








