#include "fonctions.hpp"

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
	cout << "test produit 8" << endl;
	
	
	
	
	
	
	int nb_combi = 0;


	priority_queue< pair<int, pair<string, string> > > res(fnt_corr(data));
	pair<int, pair<string, string> > top;
	//fnt_corr(data);
	while(! res.empty() && nb_combi <= 100)
	{
		top = res.top();
		cout << "correlation = " << top.first << endl;
		cout << "\tpour le produit " << (top.second).first << endl;
		cout << "\tpour le produit " << (top.second).second << endl << endl;
		res.pop();
		nb_combi++;
	}

	cout << "\n\n\nil y a " << nb_combi << " combinaisons\n";
	//int ababpf = card_inter(data["produit_2"],data["produit_3"]);
	//cout << "\n\n**********\t" << ababpf <<"\t***********\n\n"; 
	return 0;
}
