#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "main.h"
using namespace std;
class Symbol{
public:
    vector<pair<int,int>> scope;
    string name;
    string type;
    string value;
public:
    Symbol(){};
    ~Symbol() {
    }

    Symbol(const string &name, const string &type) : name(name), type(type) {}
    /*void setName(const string &name) {
        Symbol::name = name;
    }
    void setType(const string &type) {
        Symbol::type = type;
    }
     */
};
class Node{
public:
   /* Node(){
    }*/

    ~Node() {
        delete next;
    }

public:
    Symbol data;
    Node* next;
};
//Node *head;
class SymbolTable
{
public:
    Node *head =nullptr;
    SymbolTable(){
        head = nullptr;
    }
    ~SymbolTable() {
        delete head;
    };
    bool containsName(SymbolTable& list,string name);
    bool containsScope(SymbolTable& list,string name,int scope);
    void run(string filename);
    void addSymbol(SymbolTable &list, Symbol symbol);
  //  void printlist(SymbolTable& list);
    void popScope(SymbolTable &list,int scope);
};
#endif