#include "client.hpp"
#include <vector>
//constructeur par défaut 
client::client(unsigned int i,std::vector<int> p){
	id_client = i;
	ids_produits = p;
	nb_produits = p.size();
	}





