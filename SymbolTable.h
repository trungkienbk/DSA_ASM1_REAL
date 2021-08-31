#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "main.h"
using namespace std;
class Symbol {
public:
    int scope_sb[2] ={0,0};
    string name_sb;
    string type_sb;
    string value_sb;
public:
    Symbol(){};
    //Symbol(const string &nameSb, const string &typeSb) : name_sb(nameSb), type_sb(typeSb) {}; // Constructor
    Symbol(string name,string type){
        name_sb =name;
        type_sb =type;
    }
    bool valid_Symbol(string value_sb,string type_sb);
    void setScope(int arr[]) {
        scope_sb[0]=arr[0];
        scope_sb[1]=arr[1];
    }
    void setNameSb(const string &nameSb) {
        name_sb = nameSb;
    }
    void setTypeSb(const string &typeSb) {
        type_sb = typeSb;
    }
    void setValueSb(const string &valueSb) {
        value_sb = valueSb;
    }
    bool validType(string name,string value);      // check xem dung loai hay ko ---> TypeMismatch
};
class SymbolNode{
public :

    SymbolNode() {
        SymbolNode* next=nullptr;
    }
    Symbol data;
    SymbolNode* next;
};
class SymbolTable{
public:
    //  SymbolTable() {};
    void run(string filename);
    SymbolTable() {p_head = NULL;};
    ~SymbolTable() {};

    bool contains(SymbolTable& list,Symbol symbol,int *arr); // check xem da ton tai hay chua --> Undeclared va Redeclared
    SymbolNode* head() { return p_head; };
public:
    SymbolNode* p_head; // Con trỏ pHead trỏ vào phần tử đầu tiên.
};
#endif




