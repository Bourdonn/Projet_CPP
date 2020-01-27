#ifndef CLIENT_HPP 
#define CLIENT_HPP

#include <vector>

class client{
	
	private:
	unsigned int id_client; //numéro du client
	std::vector<int> ids_produits; //numéro du produit acheté
	unsigned int nb_produits; //nombre de produits achetés
	
	public: 
	client(unsigned int, std::vector<int>); //constructeur
	
	//exemple : si produits_florent =(1,5,2,1), 
    ///alors Florent(3,produits_florent) désigne le client 3. De plus, 
    ///ce client a acheté les produits (1,5,2,1).
	
	//accesseurs
	unsigned int ID()const{return id_client;}
	std::vector<int> IDS_PROD()const{return ids_produits;};
	unsigned int NB_PROD()const{ return nb_produits;}
	
	//Florent.NB_PROD() retourne le nombre d'articles achetés par 
	//Florent
	

	//mutateurs
	unsigned int &ID(){ return id_client;}
	std::vector<int> &IDS_PROD(){return ids_produits;}

	
};




#endif //CLIENT_HPP
