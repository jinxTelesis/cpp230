#include<iostream>
using	namespace	std;
//	function	prototype
void	printElements(int*, int);
void	findAllPrime(int*, int&);
bool isPrime(int x);
int	main()
{
	int	arr[] = { 3,5,7,9,11,13,15,16,19 };
	int	size = sizeof(arr) / sizeof(arr[0]);
	printElements(arr, size);
	findAllPrime(arr, size);
	cout << "==	Prime	Elements	==" << endl;
	printElements(arr, size);
	return	0;
}

void	printElements(int*	p, int	sz) {
	for (int i = 0; i<sz; i++)
		cout << *(p + i) << endl;
}

void	findAllPrime(int* p, int& sz) {
	int tempCnt = 0;
	for (int i = 0; i<sz; i++)
		if (isPrime(*(p + i)))
			*(p + tempCnt++) = *(p + i);
	sz = tempCnt;
}

bool isPrime(int x) {
	for (int i = 2; i<x; i++)
		if (x%i == 0)
			return false;
	return true;
}
