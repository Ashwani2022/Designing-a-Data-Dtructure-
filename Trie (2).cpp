#include <bits/stdc++.h>
using namespace std;

struct node{
    node* arr[26] ;
    bool flag=false ;

    bool contains(node* curr,char c){
        return (curr->arr[c-'a']!=NULL) ;
    }

    void put(char ch , node* curr){
        arr[ch-'a']=curr ;

    }

    node* getnext(char ch){
        return arr[ch-'a'] ;
    }

    void setflag(){
        flag=true ;
    }
    bool isflagset(){
        return flag ;
    }


};

node*root = new node() ;

void insert(string word){
    node* temp=root ;
    for(int i=0 ;i<word.size();i++){
        // there is no instance  of s[i]
         if(!temp->contains(temp,word[i])){ // does not contai
            node* newnode=new node() ;

            //temp->arr[word[i]-'a']=newnode ;
            // we can also use
            temp->put(word[i],newnode) ;
         }
         // we can also use if(node->arr[word[i]-'a']==NUll)
          /*there might be previous instance of s[i]
         previously there was word now we want to insert worse */

         //temp=temp->arr[word[i]-'a'] ;  we can write  it as
         temp=temp->getnext(word[i]) ;
    }
    temp->setflag() ;
}

bool search(string word){

    node*temp =root ;

    for(int i =0 ;i<word.size();i++){

        if(temp->contains(temp,word[i])){
            temp=temp->getnext(word[i]) ;
        }
        else {
            return false ;
        }
    }
        //if(temp->flag==true) return true ;
        //return false ;
        // we can write as
        return temp->isflagset() ;
}

bool startswith(string word){
    node *temp=root ;
    for(int i =0;i<word.size();i++){

        if(temp->contains(temp,word[i])){
        temp=temp->getnext(word[i]) ;

        }
        else return false ;
    }
    return true ;

}











int main()
{
    cout<<"Hello World";

    return 0;
}
