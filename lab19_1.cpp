#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &name,vector<int> &scores,vector<char> &grades){
    ifstream source;
    source.open(filename);
    string tl;
    char format[]="%[^:]: %d %d %d";
    while(getline(source,tl)){
        char t[100];
        int a,b,c;
        sscanf(tl.c_str(),format,t,&a,&b,&c);
        name.push_back(t);
        scores.push_back(a+b+c);
        grades.push_back(score2grade(a+b+c));
    }
}

void getCommand(string &c,string &k){
    string cl;
    char ca[100];
    char ka[100];
    char format[]="%s %[^\n]";
    cout<< "Please input your command: "; 
    getline(cin,cl);
    sscanf(cl.c_str(),format,ca,ka);
    c=ca;
    k=ka;
}

void searchName(vector<string> n,vector<int> s,vector<char> g,string k){
    cout<<"---------------------------------"<<endl;
    int x=-1;
    for(unsigned int i=0;i<n.size();i++){
        if(toUpperStr(n.at(i))==k){
            x=i;
        }
    }
    if(x!=-1){
        cout<<n.at(x)<<"'s score = "<<s.at(x)<<endl;
        cout<<n.at(x)<<"'s grade = "<<g.at(x)<<endl;
        }else{
            cout<<"Cannot found.\n";
        }
    cout<<"---------------------------------"<<endl;
}

void searchGrade(vector<string> n,vector<int> s,vector<char> g,string k){
    cout<<"---------------------------------"<<endl;
    for(unsigned int i=0;i<n.size();i++){
        if(g.at(i)==*k.c_str()){
            cout<<n.at(i)<<" ("<<s.at(i)<<")\n";
        }
    }
    cout<<"---------------------------------"<<endl;
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}