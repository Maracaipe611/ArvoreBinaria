#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct tree
{
	struct tree *parent;
	struct tree *left_child;
	struct tree *right_child;
	int key;
} node;

node *busca (node *root, int key)
{
	node *aux = root;

	while (aux != NULL) 
	{
		if ((*aux).key == key) {		
			return aux;
		} else if (key < (*aux).key) {
			aux = (*aux).left_child;
		} else {
			aux = (*aux).right_child;
		}
	}
	return NULL;
}

node *inserir (node *root, int key) 
{
	node *aux;

	if (root == NULL) {
		root = (node*) malloc (sizeof(node));
		(*root).key = key;
		(*root).parent = (*root).left_child = (*root).right_child = NULL;
	}

	else { 
		if (key <= (*root).key) {
			aux = inserir ((*root).left_child, key);
			(*root).left_child = aux;
			(*aux).parent = root;
		} else {
			aux = inserir ((*root).right_child, key);
			(*root).right_child = aux;
			(*aux).parent = root;
		}
	}

	return root;
}

void imprimir (node *root)
{
	if (root != NULL) {
		imprimir ((*root).left_child);
		printf("%d  ", (*root).key);
		imprimir ((*root).right_child);
	}
}

node *minimo (node *root) 
{
	node *aux = root;

	while (aux != NULL)
	{
		if ((*aux).left_child == NULL) {
			break;
		} else {
			aux = (*aux).left_child;
		}
	}
	return aux;
}

node *maximo (node *root) 
{
	node *aux = root;

	while (aux != NULL)
	{
		if ((*aux).right_child == NULL) {
			break;
		} else {
			aux = (*aux).right_child;
		}
	}
	return aux;
}


int main(void)
{
	setlocale(LC_ALL, "Portuguese");

	node *inserir (node *root, int key);
	node *minimo (node *root);
	node *maximo (node *root);
	void imprimir (node *root);

	node *root, *aux;
	root = NULL;

	int opt, dado;
	mainMenu: 
		printf ("===========MENU===========\n");
		printf ("1 - Inserir\n"); 
		printf ("2 - Mínimo\n");
		printf ("3 - Máximo\n");
		printf ("4 - Imprimir\n");
		printf ("0 - Sair\n");
		printf ("==========================\n");
		scanf ("%d", &opt);
		system("cls");

		switch(opt){
			case 1:
				printf ("Digite um valor: ");
				scanf ("%d", &dado);
				root = inserir (root, dado);
				break;
			
			case 2:
				printf ("Menor valor: ");
				aux = minimo (root);
				printf ("%d\n", (*aux).key);
				break;

			case 3:
				printf ("Maior valor: ");
				aux = maximo (root);
				printf ("%d\n", (*aux).key);
				break;

			case 4:
				imprimir (root);
				printf("\n");
				break;
		}    		
	while (opt != 0){
		goto mainMenu;
	}

	return 0;
}
