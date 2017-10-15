
#include <dlfcn.h>
#include <stdio.h>

#define NUM1	5
#define NUM2	2


int main (){
	void *h = dlopen("./libaritmetica.so", RTLD_LAZY);

	printf ("Dados los números %d y %d\n", NUM1, NUM2);

	int (*test)() = dlsym (h, "suma");
	printf ("La suma es %d\n", (*test)(NUM1, NUM2));

	test = dlsym (h, "resta");
	printf ("La resta es %d\n", (*test)(NUM1, NUM2));

	test = dlsym (h, "multiplicacion");
	printf ("La multiplicación es %d\n", (*test)(NUM1, NUM2));

	float (*test2)() = dlsym (h, "division");
	printf ("La división es %f\n", (*test2)(NUM1, NUM2));
	return 0;
}
