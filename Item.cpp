#include "Item.h"


namespace Daniela
{
	using namespace System;

	Daniela::Item::Item()
	{
	}

	Daniela::Item::Item(int id, String^ name, float price, String^ type, String^ subType)
	{
		throw gcnew System::NotImplementedException();
	}

	Item ^ Item::Clone()
	{
		throw gcnew System::NotImplementedException();
	}

}