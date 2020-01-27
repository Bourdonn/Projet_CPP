#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, const char** argv)
{
	assert(argc==2);
	map<string, vector<string> > data;
	ifstream file(argv[1]);
	int  kp = 0, ka = 0;
	string  client, produit, pointvirgule;
	while(!file.eof())
	{
		file >> client;
		file >> pointvirgule;
		file >> produit;
		ka++;
		if(file.eof()) break;
		if(data.find(produit) == data.end())
		{
			(data[produit]).push_back(client);
			kp++;
		}
		else
			(data[produit]).push_back(client);

	}

	for(map<string, vector<string> >::iterator it = data.begin(); it != data.end(); ++it)
	{
		cout << "le " << it -> first << " a ete achete par :\n";
		for(vector<string>::iterator it2 = (it -> second).begin(); it2 != (it -> second).end(); ++it2)
			cout << "\t le " << *it2 << endl;
		cout << "\n\n\n";
	}

	cout << "le nombre de produits est " << kp << endl;

	return 0;
}
