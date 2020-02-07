#include <iostream>
#include <fstream>
#include <cassert>
#include <map>
using namespace std;

int main (int argc,const char ** argv)
{
	assert(argc==2);
	 int ka =0,kc=0,kp=0;
	 map<string,int> mapp,mapc; 
	{
	 ifstream fin(argv[1]);
	
	 while (!fin.eof())
	 {
		 string client, produit,pointvirgule;
		 fin >> client ;
		 
		 fin >> pointvirgule;
		 fin >> produit;
		  if (fin.eof()) break; 
		 // si le produit n'existe pas on le cree
		 if( mapp.find(produit) == mapp.end())
			 mapp[produit]=kp++;
		 if( mapc.find(client) == mapc.end())
			 mapc[client]=kc++;
		 
		
		 cout << ka << "  "<<  client << " " << produit << endl; 
		 ka++; 
	 }
    }
    cout << " nb clients  "<< kc<< endl;
    cout << " nb produits "<< kp << endl;
	return 0;
}
