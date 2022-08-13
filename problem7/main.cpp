#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
void BiasedSort (vector<string> &v)
{
    int k=0 ,j;
    for (unsigned int i=0 ; i< v.size() ; i++)
    {
        if (v[i] == "Untitled")
            swap (v[i] ,v[k++]);
    }
    for (unsigned int i=k ; i< v.size() ; i++)
    {
        string tmp=v[i] ;
        for (j=i;j>0 && tmp<v[j-1] ; j--)
            v[j]=v[j-1];
        v[j]=tmp ;
    }

}

int main()
{
    vector <string>v ;
    v.push_back("firstSong");
    v.push_back("anthorSong");
    v.push_back("Untitled");
    v.push_back("Untitled");
    v.push_back("song");
    v.push_back("abc");
    v.push_back("dqw");
    v.push_back("Untitled");
    BiasedSort(v) ;
    for (auto i : v)
        cout << i << "\n" ;
    return 0;
}
