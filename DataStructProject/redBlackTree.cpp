#include<iostream>
#include<string>
#include"rbTree.h"
using namespace std;

int main()
{
	rbTree<int, int>  T1;
	T1.add(2, 1);
	T1.add(2, 2);
	T1.add(2, 4);
	T1.add(2, 5);
	T1.add(2, 7);

	T1.ShowinInOrder();
}