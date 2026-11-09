#pragma once
#include <iostream>
#include<mutex>
using namespace std;
class ContSingleton
{
private:
	long cont;
	mutex m;
public:
	static ContSingleton& getInst();
	~ContSingleton();
	void incrementar();
	void decrementar();
	long getCont();
private:
	ContSingleton();

};

