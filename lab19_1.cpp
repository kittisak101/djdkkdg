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

void importDataFromFile(string f,vector<string> &names,vector<int> &score,vector<char> &grade ){

    ifstream source(f.c_str());
    string texts;
    int i=0;

    while(getline(source, texts)){


    char format[]= "%[^:]: %d %d %d";
    char name[50];
    int a,b,c;
    sscanf(texts.c_str(),format,name,&a,&b,&c);

    names.push_back(name);
    score.push_back(a + b + c);
    grade.push_back(score2grade(score[i]));
    
    i++;
    


    }

    
}

void getCommand(string &command,string &key){
string h;
cout << "Please input your command: ";
getline(cin,h);

int start = 0;
int end = h.find_first_of(" ");

command = h.substr(start,end-start);
start = end + 1 ;
end = h.find_first_of(" ",start);

key =  h.substr(start);



}

void searchName(vector<string> names,vector<int>  scores,vector<char>  grades,string key){

bool cannotF = false;
cout << "---------------------------------\n";
for (unsigned int i = 0; i < names.size() ; i++)
{

    
    
    if(toUpperStr(names[i]) == toUpperStr(key) ){
    cannotF = true;
    cout <<names[i]<<"'s score = " << scores[i]<< "\n"; 
    cout <<names[i]<<"'s grade = " << grades[i]<< "\n"; 
 
    }

}
if (cannotF == false)
{
    cout << "Cannot found.\n";
}


cout << "---------------------------------\n";



}

void searchGrade(vector<string> names,vector<int>  scores,vector<char>  grades,string key){

    cout << "---------------------------------\n";

    for (unsigned int i = 0; i < names.size() ; i++)
{

    string g;
    g = grades[i];
    if(g == key ){

    cout <<names[i]<<" ("<< scores[i]<< ")\n"; 
 
    }

    

}
    cout << "---------------------------------\n";

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