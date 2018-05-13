#include "Item.h"
#include "ItemCollection.h"

namespace Daniela
{
	using namespace System::IO;
	using namespace System::Collections::Generic;

	ItemCollection::ItemCollection()
	{
		this->types = gcnew List<String^>();
		this->subTypes = gcnew Dictionary<String^, List<String^>^>();
	}
	void ItemCollection::SaveToFile(String ^ filename)
	{
		FileStream^ dbFile;
		BinaryWriter^ writer;

		try {
			FileInfo(filename).Directory->Create();
			dbFile = File::Open(filename, FileMode::OpenOrCreate, FileAccess::ReadWrite);
			writer = gcnew BinaryWriter(dbFile);

			writer->Write(this->Count);

			for (int i = 0; i < this->Count; i++)
			{
				Item^ item = this[i];
				// write you item fields into file 
				// ex: writer->Write(item->Name); 
			}
		}
		catch (Exception^ ex) {
			System::Windows::Forms::MessageBox::Show("Error while writing file");
			throw ex;
		}
		finally {
			writer->Close();
			dbFile->Close();
		}
	}
	void ItemCollection::LoadFromFile(String ^ filename)
	{
		FileStream^ dbFile;
		BinaryReader^ reader;

		try {
			dbFile = File::Open(filename, FileMode::OpenOrCreate, FileAccess::ReadWrite);
			reader = gcnew BinaryReader(dbFile);

			int count = reader->ReadInt32();

			for (int i = 0; i < count; i++)
			{
				Item^ item = gcnew Item();

				// read you item fiels from file
				// ex: item->Name = reader->ReadString();  
				
				this->Add(item);
			}

			
		}
		catch (Exception^ ex) {
			System::Windows::Forms::MessageBox::Show("Error while reading file");
			throw ex;
		}
		finally {
			reader->Close();
			dbFile->Close();
		}
	} 
}