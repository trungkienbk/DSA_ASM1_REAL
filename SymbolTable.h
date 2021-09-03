/*#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "main.h"
class Symbol{
public:
    vector<pair<int,int>> scope;
    string name;
    string type;
    string value;
public:
    Symbol(){};
    Symbol(string name,string type){
        this->name =name;
        this->name =type;
    }
    void setName(const string &name) {
        Symbol::name = name;
    }
    void setType(const string &type) {
        Symbol::type = type;
    }
};
class Node{
public:
    Node(){
        Node* next = nullptr;
    }
public:
    Symbol data;
    Node* next;
};
class SymbolTable
{
public:
    //SymbolTable() {}
    Node *head;
    SymbolTable(){
        head = nullptr;
    }
    ~SymbolTable() {};
    void add_Symbol(SymbolTable& list,Symbol symbol);
    void run(string filename);
    void print_list(SymbolTable& list);
};
#endif
 */
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
    void showInfo()
    {
        std::cout << "  Name = " << name_sb.c_str();
        std::cout << "  Type = " << type_sb.c_str();
        cout<<endl;
    };
    bool validType(string name,string value);      // check xem dung loai hay ko ---> TypeMismatch
};
class SymbolNode{
public :
    Symbol data;
    SymbolNode* next;
};
SymbolNode *head;
class SymbolTable{
public:
    void run(string filename);
    SymbolTable() {head = NULL;};
    ~SymbolTable() {};
    bool contains(SymbolTable& list,Symbol symbol,int *arr);
    bool contains_scope(SymbolTable& list,Symbol symbol,int *arr); // check xem da ton tai hay chua --> Undeclared va Redeclared
    void add_Symbol(SymbolTable& list,Symbol symbol);
    void print_list(SymbolTable& list);
    // Con trỏ pHead trỏ vào phần tử đầu tiên.
};
bool Symbol::valid_Symbol(string value_sb, string type_sb) {
    return false;
}
#endif