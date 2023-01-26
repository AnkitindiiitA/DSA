/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //hashmap = unordered_map
    
    //every key has only one unique value if you assign new
    //value to the same key it will update the value of key rather
    //than creating new key
    
    unordered_map<string, int>m;
    
    //insertion method 1
    pair<string, int> p = make_pair("dost", 3);
    m.insert(p);
    
    //insertion method 2 
    pair<string, int> q("aman",4);
    m.insert(q);
    
    //insertion method 3
    m["mera"]=5;
    
    //insertion method 4
    m.insert({"tum",10});
    
    
    
    cout<<m["dost"]<<" ";
    cout<<m["aman"]<<" ";
    cout<<m.at("mera")<<" ";
    cout<<m.at("tum")<<" \n";
    
    //cout<<m.at("unknownkey"); ---> it will give error
    //cout<<m.at("unknownkey"); ---> it will create a key with value 0;
    
    
    //size
    cout<<m.size()<<"\n";
    
    
    
    //to check presence
    cout<<m.count("bro")<<"\n";//if key is present then it will return 1 else 0;
    
    
    
    //erase
    m.erase("aman");
    cout<<m.size()<<"\n";
    
    
    
    //traversing unordered_map
    for(auto &it:m){
        cout<<it.first<<" "<<it.second<<"\n";
    }
    
    //using iterator
    unordered_map<string,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<<it -> first<<" "<<it -> second<<"\n";
        it++; //we can't use it = it+1;
    }
    
    return 0;
}
