#pragma once

#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Packet
{
public:
	//Constructor
	Packet(const string& newPacket)
	{
		this->mFeild = newPacket;
		this->mLengthFeild = newPacket.size();
	}

	//Destructor
	~Packet()
	{

	}

	//Setters
	
	friend ostream& operator << (ostream& lhs, const Packet& rhs)
	{
		lhs << "Packet field: " << rhs.mFeild << " , length: " << rhs.mLengthFeild;
		return lhs;
	}
	

private:
	string mFeild;
	int mLengthFeild;    //The number of characters in the feild (unit: bytes)
};


