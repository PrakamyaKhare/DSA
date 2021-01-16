// Aurthor = Prakamya Khare

#include<iostream>
using namespace std;

struct Hash{
	int key;
	char value;
};

class HashTable{
	private:
	int i;
	string data;
	const char NIL = NULL;
	int len;
	Hash *hash;
	public:
	  HashTable(string data)
	  {
	  	this->data = data;
	  	len = sizeof(data);
	  	hash = new Hash[len];
	  	i = 0;
	  }
   
   void generate()
   {
     for(i = 0; i <= len; i++)
     {
     	hash[i].key = i;
     	hash[i].value = data[i] ;
      }	
   }  

 char getItem(int indx)
 {
 	return (hash[indx].value);
 }
 
 int getLen()
 {
 	return (sizeof(data));
 }
int getIndex(char ch)
{
	int index ;
	for(index = 0; index < getLen();index++)
	{
		if(ch == hash[index].value){
		 break;
		}
	}
	return index; 
}
void del(int indx)
{
	hash[indx].value = NIL; 
}

void printHash()
{
	cout << "Keys   "<< "Values" << endl;
	for(int i = 0; i<=getLen();i++)
	{
		cout<<hash[i].key << "   "<<hash[i].value << endl;
	}
	cout<<endl;
}			
};

int main(int argc, char *argv[])
{
string data = "abcdefghijklmnopqurstuvwxyz";
HashTable hash(data);
hash.generate();
hash.printHash();
cout<< hash.getIndex('h');
cout<<endl;
cout<<hash.getItem(17);
return 0;	
}
