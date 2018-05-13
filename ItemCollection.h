#ifndef ITEMCOLLECTION_H
#define ITEMCOLLECTION_H
#include "Item.h"


namespace Daniela
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;

	public ref class ItemCollection : BindingList<Item^>
	{
	public:
		ItemCollection();

		void SaveToFile(String^ filename);
		void LoadFromFile(String^ filename);
 
	};
}
#endif