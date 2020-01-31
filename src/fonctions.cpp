#include "fonctions.hpp"

using namespace std;

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


priority_queue< pair <int, pair<string, string> > >  fnt_corr( map<string, vector<string> > &data)
{
	int card;
	priority_queue<pair<int, pair<string, string> > > pq;
	map<string,vector<string> >::iterator itm;
	for(itm = data.begin(); itm != data.end(); ++itm)
	{
		//cout << "iterator itm pointe sur\t" << itm -> first << "\n";
		map <string, vector<string> >::iterator itm2;
		for(itm2 = itm; itm2 != data.end(); ++itm2)
		{
			//cout << "\t itm2 pointe sur\t" << itm2 -> first << "\n";
			if(itm != itm2)
			{
				card = card_inter(itm -> second, itm2 -> second);
				//pair<string, string>Cij()
				pq.push(make_pair(card, make_pair(itm -> first, itm2 -> first)));
				//mapcorr[card_inter(itm -> second, itm2 ->second)] =
				//pair<string,string>(itm -> first, itm2 -> first);
			}
			
		}

	}
	return pq;
}




