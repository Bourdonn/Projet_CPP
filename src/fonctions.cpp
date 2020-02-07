#include "fonctions.hpp"

using namespace std;

//Fonction qui lit le fichier avec les donnees et les stocke dans une multimap
//les donnes sont regrouppees de maniere suivante :
// - A chaque produit on associe tableau des clients qui l'ont achete, avec pair<string, vector<string>>
// - Les couples (produit, tableau des clients) sont ensuite stockes 
//	dans l'ordre decroissant selon la taille du tableau des clients, dans une multimap
multimap<int, pair<string, vector<string> >, greater<int> > read_data(const char* name)
{
	ifstream file(name);
	map<string, vector<string> > temp;
	int kp = 0, ka = 0;
	string client, produit, pointvirgule;
	while(!file.eof())
	{
		file >> client;
		file >> pointvirgule;
		file >> produit;
		ka++;
		if(file.eof()) break;
		if(temp.find(produit) == temp.end())
		{
			(temp[produit]).push_back(client);
			kp++;
		}
		else
			(temp[produit]).push_back(client);
	}
	multimap<int, pair<string, vector<string> >, greater<int> > data;
	for(map<string, vector<string> >::iterator it = temp.begin(); it != temp.end(); it++)
		data.insert(make_pair((it -> second).size(), make_pair(it -> first, it -> second) ) );
	return data;
}






//Fonction qui retourne le minimum de deux entiers
int min(int a, int b)
{
	if(a <= b)
		return b;
	else 
		return a;
}







//Fonction qui affiche un par un les produits avec tous les clients qui les ont achetes  
void print_map_data(multimap<int, pair<string, vector<string> >, greater<int> > &data)
{
	map<int, pair<string, vector<string> >, greater<int> >::iterator itm;
	for(itm = data.begin(); itm != data.end(); itm++)
	{
		cout << "le " << (itm -> second).first << " a ete achete par :\n";
		for(vector<string>::iterator itv = (itm -> second).second.begin(); itv != (itm -> second).second.end(); itv++)
			cout << "\t le " << *itv << endl;
		cout << endl << endl << endl;	
	}
}















//Fonction qui pour deux tableaux de donnees (clients) retourne le cardinal de leur intersection
int card_inter(vector<string> &U, vector<string> &V)
{
	int corr = 0;
	vector<string> min,max;
	if(U.size() >= V.size())
	{
		max = U;
		min = V;
	}
	else
	{
		max = V;
		min = U;
	}
	for(vector<string>::iterator itv = min.begin(); itv != min.end(); ++itv)
	{
		if(find(max.begin(), max.end(), *itv) != max.end())
			corr++;
	}
	return corr;
}






//Focntion qui retourne la correlation du m-ieme element de la map 
int corr_ind_m(multimap<int, pair<string, string>, greater<int> > &res, int m)
{
	assert(res.size() >= m);
	multimap<int, pair<string, string>, greater<int> >::iterator it = res.begin();
	int x;	
	for(int k = 0; k < m-1; k++)
	{
		it++;
	}
	x = (*it).first;
	return x;
}





int som_corr(multimap<int, pair<string, string>, greater<int> > &res)
{
	int somme = 0;
	multimap<int, pair<string, string>, greater<int> >::iterator it;
	for(it = res.begin(); it != res.end(); it++)
		somme += it -> first;
	return somme;
}




//Fonction qui retourne une map rangee de correlations avec les combinaisons ij
multimap<int, pair<string, string>, greater<int> > fnt_corr( multimap<int, pair<string, vector<string> >, greater<int> > &data, int m, int rang)
{
	//ofstream file("act.txt"); // accroissement correlation totale
	int compteur1 = 0;
	int compteur2 = 0;
	int card;
	multimap <int, pair<string, string>, greater<int> > res;
	//On parcourt les boucles pour faire les combinaisons ij
	multimap <int, pair<string, vector<string> >, greater<int> >::iterator it1;
	for(it1 = data.begin(); it1 != data.end(); it1++)
	{
		compteur1++;
		if(compteur1 > rang)
			break;
		multimap <int, pair<string, vector<string> >, greater<int> >::iterator it2;
		for(it2 = it1; it2 != data.end(); it2++)
		{
			compteur2++;
			if(compteur2 > rang)
				break;
			if(it1 != it2) //On ne calcule pas la correlation si on a deux fois le meme tableau
			{
				if(res.size() >= m)
				{
					//	Si la m-ieme correlation est plus grande que la taille du tableau 
					//	c'est plus la peine de continuer car les tableaux sont ranges par ordre de taille et 
					//	leur intersection ne peut pas etre plus grande que la m-ieme correlation
					if(corr_ind_m(res,m) > min(it1 -> first, it2 -> first))
					{
						return res;
					}
				}
				card =  card_inter((it1 -> second).second , (it2 -> second).second );
				res.insert(make_pair(card, make_pair((it1 -> second).first , (it2 -> second).first ) ));
			}
		}

	}
	cout << rang << " " << som_corr(res) << endl;
	return res;

}








//Fonction qui affiche les m plus grandes correlations de produits
void print_max_corr(multimap<int, pair<string, string >, greater<int> > &res, int m)
{
	int nb_combi = 0;
	multimap<int, pair<string, string >, greater<int> >::iterator it = res.begin();
	while(it != res.end() && nb_combi < m)
	{
		cout << "correlation = " << it -> first << endl;
		cout << "\tpour le produit " << (it -> second).first << endl;
		cout << "\tpour le produit " << (it -> second).second << endl << endl;
		nb_combi++;
		it++;
	}
}






