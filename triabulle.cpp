#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>

namespace my_random {
  auto generate(int min_t,int max_t,int nombre)
  {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min_t,max_t);

    auto t = std::vector<int>(nombre);
    for(auto& n : t){
      n = dis(gen);
    }
    /*for(auto i=0;i<nombre;i++){
      t[i] = dis(gen);
      }*/
    return t;
  }
}

inline void tri_a_bulle(std::vector<int>& tab){
  int i=tab.size()-1;
  do{
    for(int j=0;j<=i-1;j++){
      if(tab[j+1]<tab[j]){
	int tmp = tab[j];
	tab[j] = tab[j+1];
	tab[j+1] = tmp;
      }
	}
    i--;
  }while(i>=1);
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    for (int i = 0; i < 10000000; ++i )
    {
        std::sqrt( 123.456L );
    }

    std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
    std::cout << "L'execution a pris " << sec.count() << " seconds\n";
}

inline bool tri_a_bulle_optim(std::vector<int>& T){
  int i = T.size()-1;
  do{
    if(tri_a_bulle_optim)
      for(int j=0;j<=i-1;j++){
	if(T[j+1]<T[j]){
	  int tmp = T[j+1];
	  T[j+1] = T[j];
	  T[j] = tmp;
	  !tri_a_bulle_optim(T);
	}
      }
    i--;
  }while(i>=1);
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    for (int i = 0; i < 10000000; ++i )
    {
        std::sqrt( 123.456L );
    }

    std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
    std::cout << "L'execution a pris " << sec.count() << " seconds\n";

  return tri_a_bulle_optim;
}

void jaffiche(std::vector<int>& t){
  for(int i=0;i<t.size();i++){
    std::cout << t[i] << " ";
  }
  std::cout << "\n";
}

int main(int argc,char *argv[]){

  auto v = my_random::generate(0,10,7);
  jaffiche(v);
  auto v_grand = my_random::generate(0,1000,10);
  jaffiche(v);
  tri_a_bulle(v);
  jaffiche(v_grand);
  std::cout << "pour le tableau de grandes valeurs " << std::endl;
  tri_a_bulle(v_grand);

  std::cout << "Apres tri " << std::endl;
  jaffiche(v);

  jaffiche(v_grand);

  std::cout << "Comparaison avec sort de la librairie standard, on a " << std::endl;
  std::sort(v.begin(), v.end());
  jaffiche(v);
  std::sort(v_grand.begin(),v_grand.end());
  jaffiche(v_grand);

  std::cout << "Apres optimisation de l'algo de tri " << std::endl;
  tri_a_bulle_optim(v);
  jaffiche(v);
  std::cout << "pour le tableau de grandes valeurs ";
  tri_a_bulle_optim(v_grand);

  return 0;
}
