#include "fonctions.hpp"

using namespace std;



int main(int argc, const char** argv)
{
	assert(argc==2);



	//////////////////////DEBUT D'EXECUTION DU PROGRAMME////////////////////

	time_t debut, fin;
	double duree;
	debut=time(NULL);


	//les donnees sont stockees dans une map	
	multimap<int, pair<string, vector<string> >, greater<int> > data(read_data(argv[1]));


	
	//pour afficher la map
	//print_map_data(data);
	//trie des combinaisons ij en fonction du cardinal de leur intersection 
	//int rang = 1000;
	//multimap<int, pair<string,string>, greater<int> > res(fnt_corr(data,100, rang));
	
	for (int rang = 100; rang <= 15000; rang += 100)
		fnt_corr(data, 100, rang);


	//pour afficher les 100 couples les plus correlees
	//print_max_corr(res, 100);
	
	
	
	///////////////////TEMPS D'EXECUTION DU PROGRAMME///////////////////
	
	fin=time(NULL);
	duree=difftime(fin, debut);
/*	
	cout<<" Le temps d'exécution de ce programme est de "<<duree<<" secondes.";
	cout<<endl;
	cout<<endl;
	*/
	return 0;
}
