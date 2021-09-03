#include "SymbolTable.h"
#include <sstream>
using namespace std;
int convertInt(string method ){
    if(method == "INSERT") return 1;
    if(method == "LOOKUP") return 2;
    if(method == "ASSIGN") return 3;
    if(method == "PRINT") return 4;
    if(method == "RPRINT") return 5;
    if(method == "BEGIN") return 6;
    return 7;
}
void SymbolTable::run(string filename)
{
    int global_scope = 0;
    int row = 0;
    SymbolTable list;
    string ins,method,name,var;
    fstream input;
    input.open(filename);
    if(input){
        while(std::getline(input,ins)){
            row++;
            istringstream(ins)>>method>>name>>var; // var  = type or value
            //cout<<lineInput<<"|| Method :"<<method<<" || Name :"<<name<<"|| Var : "<<var<<endl;
           int numberMethod = convertInt(method);
           //Insert: 1 Lookup:2 Assign:3 Print:4 RPrint:5 Begin:6 End:7
           switch(numberMethod){
               case 1:
                   if(!containsName(list,name)){
                       Symbol symbol(name,var);
                       symbol.scope.emplace_back(row,global_scope);
                       addSymbol(list,symbol);
                       cout<<"success"<<endl;
                   } else {
                       if(!containsScope(list,name,global_scope)){
                           Node* phead=head;
                           while(phead!= nullptr){
                               if(phead->data.name == name ){
                                   break;
                               }
                               phead=phead->next;
                           }
                           phead->data.value=var;
                           phead->data.scope.emplace_back(row,global_scope);
                           cout<<"success"<<endl;
                       }
                       else throw Redeclared(ins);
                   }
                   break;
               case 2:
                   break;
               case 3:
                   break;
               case 4:
                   break;
               case 5:
                    break;
               case 6:
                   global_scope++;
                   break;
               default:
                   if(global_scope == 0) throw UnknownBlock();
                   popScope(list,global_scope);
                   global_scope--;
                   break;
           }
        }
    }
    else {
        cout<<filename<<" not exist";
    }
    input.close();
}

void SymbolTable::addSymbol(SymbolTable &list, Symbol symbol) {
    if( head == nullptr ) {
        Node *temp=new Node;
        temp->data= symbol;
        temp->next = head;
        head = temp;
    } else {
        Node *phead =head;
        while(phead->next != nullptr){
            phead=phead->next;
        }
        Node *temp = new Node;
        temp->data=symbol;
        temp->next = phead ->next;
        phead->next = temp;
    }
}
/*void SymbolTable::printlist(SymbolTable &list) {
    if(head == nullptr) cout<<"No elements";
    else {
        Node *temp = head;
        while(temp!= nullptr){
            cout<<temp->data.name<<" "<<temp->data.type<<" "<<temp->data.value<<endl;
            temp = temp->next;
        }
    }
}*/
// False -> Them duoc , True -> Khong them duoc
bool SymbolTable::containsName(SymbolTable &list, string name) {
    if(head == nullptr) return false;
    Node* phead=head;
    while(phead!= nullptr){
        if(phead->data.name == name ){
            return true;
        }
        phead=phead->next;
    }
    return false;
}

bool SymbolTable::containsScope(SymbolTable &list,string name, int scope) {
    Node* phead=head;
    while(phead!= nullptr){
        if(phead->data.name == name ){
            break;
        }
        phead=phead->next;
    }
    if(phead->data.scope.back().second == scope){
        return true;
    }
    return false;
}

void SymbolTable::popScope(SymbolTable &list, int scope) {
    Node* phead=head;
    while(phead!= nullptr){
        if(phead->data.scope.back().second == scope){
            phead->data.scope.pop_back();
        }
        phead=phead->next;
    }
}
