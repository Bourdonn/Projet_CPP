#ifndef FONCTIONS_HPP
#define FONCTIONS_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <time.h>


std::multimap<int, std::pair<std::string, std::vector<std::string> >, std::greater<int> > read_data(const char * name);

void print_map_data(std::multimap<int, std::pair<std::string, std::vector<std::string> >, std::greater<int> > &data);

int card_inter(std::vector<std::string> &U, std::vector<std::string> &V);

int som_corr(std::multimap<int, std::pair<std::string, std::string>, std::greater<int> > &res);

std::multimap<int, std::pair<std::string, std::string>, std::greater<int> > fnt_corr(std::multimap<int, std::pair<std::string, std::vector<std::string> >, std::greater<int> > &data, int m, int rang);

//Fonction qui retourne la correlation d'indice m de la map 
int corr_ind_m(std::multimap<int, std::pair<std::string, std::string>, std::greater<int> > &res, int m);

void print_max_corr(std::multimap<int, std::pair<std::string, std::string >, std::greater<int> > &res, int m);

int min(int a, int b);

#endif
