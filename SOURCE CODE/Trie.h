#pragma once

#include<iostream>
#include<string>
#include<set>
using namespace std;

class TrieNode{
public:
    TrieNode *links[26];
    bool flag;
    set<long long int> mobile_numbers;
    TrieNode(void){
        this->flag = false;
    }
};

class Trie{
private:
    TrieNode *root;
    void print_search_results(TrieNode *head,string const &name);
    void perform_prefix_search(TrieNode *head,string &name);;
public:
    Trie(void);
    void insert(string const &name,long long int const &number);
    void remove(string const &name);
    void search(string const &name);
    void prefix_search(string const &name);
    void print_all_contacts(void);
    ~Trie(void);
};

Trie::Trie(void){
    root = new TrieNode();
}

void Trie::print_search_results(TrieNode *head,string const &name){
    if(!head->flag){
        cout<<"NO CONTACT FOUND \n";
        return ;
    }
    cout<<name<<" \t : ";
    for(auto &x:head->mobile_numbers){
        cout<<x<<" ";
    }
    cout<<endl;
}

void Trie::perform_prefix_search(TrieNode *head,string &name){
    if(head->flag == true){
        print_search_results(head,name);
    }
    for(int i=0;i<26;i++){
        if(head->links[i] != NULL){
            name.push_back(('a' + i));
            perform_prefix_search(head->links[i],name);
            name.pop_back();
        }
    }
    return ;
}

void Trie::insert(string const &name,long long int const &number){
    TrieNode* head = root;
    for(auto &x:name){
        if(head->links[x-'a'] == NULL)
            head->links[x-'a'] = new TrieNode();
        head = head->links[x-'a'];
    }
    head->flag = true;
    head->mobile_numbers.insert(number);
    return ;
}

void Trie::remove(string const &name){
    TrieNode *head = root;
    for(auto &x:name){
        if(head->links[x-'a'] == NULL){
            cout<<"The user didn't exist\n";
            return ;
        }
        head = head->links[x-'a'];
    }
    head->flag = false;
    return ;
}

void Trie::search(string const &name){
    TrieNode *head = root;
    for(auto &x:name){
        if(head->links[x-'a'] == NULL){
            cout<<"NO CONTACT\n";
            return ;
        }
        head = head->links[x-'a'];
    }
    print_search_results(head,name);
    return ;
}

void Trie::prefix_search(string const &name){
    TrieNode *head = root;
    for(auto &x:name){
        if(head->links[x-'a'] == NULL){
            cout<<"NO SUGGESTED CONTACTS\n";
            return ;
        }
        head = head->links[x-'a'];
    }
    string user_name = name;
    perform_prefix_search(head,user_name);
    return ;
}

void Trie::print_all_contacts(void){
    string user_name = "";
    TrieNode *head = root;
    perform_prefix_search(head,user_name);
    cout<<endl<<endl<<endl;
    return ;
}

Trie::~Trie(void){
    return ;
}



