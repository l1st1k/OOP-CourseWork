#pragma once
#include <stdexcept>
using namespace std;
class ListError : public exception  
{
public:
	ListError(const char* error) : exception(error) { this->error == error; }
	const  char* error_msg() { return error.c_str(); }
private:
	string error;
};