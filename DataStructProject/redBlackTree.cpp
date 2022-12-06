#include<iostream>
#include<string>
#include"rbTree.h"
using namespace std;

int main()
{
	rbTree<int, int>  T1;
	T1.add(2, 1);
	T1.add(2, 2);
	T1.add(2, 3);
	T1.add(2, 0);
	T1.add(2, 8);
	T1.add(2, 11);
	T1.add(2, 7);
	T1.add(2, 6);
	T1.blackNodes(T1.root);








	T1.ShowinInOrder();
}