#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int alphabets  =26;

struct Node{

    struct Node* children [alphabets]={};
    int occurences;
    bool flag;

};
void insert_trie(struct Node * trietree,char * word){
struct Node * current=trietree;// current
while(*word!='\0'){

    if(current->children[*word-'a']==NULL){
        current->children[*word-'a']= (struct Node *) calloc(1, sizeof(struct Node));
    }
    current=current->children[*word-'a'];
  ++word;
}
current->flag=true;
}
struct Node* search_trie(struct Node* current,char* word){

while(*word!='\0'){
if(current->children[*word-'a']!=NULL){
    current=current->children[*word-'a'];
    ++word;
}
else
    break;
}
if(*word=='\0'){
    return current;
}
else
    return NULL;
// look for every character we are searching


}
void autocomplete(struct Node* trietree, vector <char> word,char* prefix){
    bool nochild=true;
if(trietree->flag==true && word.size()!=0){// if word.size() is not kept here , it gonna print the prefix so keep this check
    // first print what is given as prefix
    cout<<prefix;// now after this print the things uu got in vector word
    for(int i=0;i<word.size();i++){
        cout<<word[i];
    }
    cout<<endl;

}
for(int i=0;i<alphabets;i++){
if(trietree->children[i]!=nullptr){
       // nochild=false;// it has a child
    word.push_back(i+'a');
    autocomplete(trietree->children[i],word,prefix);
    word.pop_back();
}
}
word.pop_back();
}


int main()
{
   //char word[123456];
    //cout<<"enter number of words u want to enter "<<endl;
//int n;
//cin>>n;
//Node* trietree=new Node();
 struct Node * trietree = new Node();
 char filename[100];
	ifstream bad;
	cin.getline(filename,100);
	bad.open(filename);
if(!bad.is_open()){
	exit(EXIT_FAILURE);
}
char word[50];
bad>>word;
while(bad.good()){
	//cout<<word<<" "<<endl;
	 insert_trie(trietree,word);
	bad>>word;
}
//for(int i=1;i<=n;i++){
        //cin>>word;
    //insert_trie(trietree,word);
//}
vector <char > ch;
cout<<"enter  ur word to search"<<endl;
cin>>word;
Node* temp=search_trie(trietree,word);
if(temp==nullptr)
    cout<<"NO word with this prefix in dictionary "<<endl;
else
autocomplete(temp,ch,word);



    return 0;
}
