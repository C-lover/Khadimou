#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

namespace my_random{
  auto generate(int min_t,int max_t,int nombre){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min_t,max_t);

    auto t=std::vector<int>(nombre);
    for(auto& n : t){
      n = dis(gen);
    }
    return t;
  }
}

void echange(std::vector<int>& v,int a,int b){
  int temp = v[a];
  v[a]=v[b];
  v[b]=temp;
}

int partitionner(std::vector<int>& v,int premier,int dernier){
  int pivot = v[premier+(dernier-premier)/2];
  //std::cout << "premier "<< premier <<" pivot = "<< pivot <<" dernier "<<dernier<< std::endl;
  int i= premier-1;
  int j = dernier+1;
  while (true) {
    do{
        i++;
    }while (v[i] < pivot);

    do{
      j--;
    }while (v[j] > pivot);
    if (i>= j)  return j;
    echange(v,i,j);

  }

}

inline void tri_rapide(std::vector<int>&T,int first,int last){
  if(first<last){

    int pivot = partitionner(T, first, last);
    std::cout << "premier "<< first <<" pivot = "<< pivot <<" dernier "<<last<< std::endl;
    tri_rapide(T,first,pivot);
    tri_rapide(T,pivot+1,last);

  }
}

void jaffiche(std::vector<int>& t){
  for(int i=0;i<t.size();i++){
    std::cout << t[i] << " ";
  }
  std::cout << "\n";
}

int main(int argc ,char *argv[]){
  int size = atoi(argv[1]);
  auto v = my_random::generate(0,size,size);
  jaffiche(v);
  std::cout << "Apres application du tri rapide "<< std::endl;
  tri_rapide(v,0,v.size()-1);
  std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

  for (int i = 0; i < 10000000; ++i )
  {
      std::sqrt( 123.456L );
  }

  std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
  std::cout << "L'execution a pris " << sec.count() << " seconds\n";
  jaffiche(v);
  return 0;
}
