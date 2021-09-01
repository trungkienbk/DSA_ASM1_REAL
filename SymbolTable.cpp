#include "SymbolTable.h"
using namespace std;
void SymbolTable::run(string filename){
    /*SymbolTable list;
    Symbol symbol("x","Number");
    Symbol symbol1("y","Number");
    Symbol symbol2("z","Number");
    Symbol symbol3("t","Number");
    add_Symbol(list,symbol);
    add_Symbol(list,symbol1);
    add_Symbol(list,symbol2);
    add_Symbol(list,symbol3);
    print_list(list); */
    int count_line = 0;
    int count_action = 0;
    string line,method,name,attribue;
    int *arr = new int[2]{0};
    fstream input_file;
    int count = 0;
    input_file.open(filename);
    if(input_file){
        while(std::getline(input_file,line)){
            count_line++;
        }
    }
    input_file.open(filename);
    if(input_file){
        while(std::getline(input_file,line)){
            if( count == 5){
                return;
            }
            cout<<line<<endl;
            count++;
        }
    }
    else {
        cout<<filename<< " not exist";
    }
    input_file.close();
}
// false -> thao tac dc
// true -> ko thao tac dc
// if contains == true ,thi goi ham kia.
bool SymbolTable::contains(SymbolTable &list, string name,int *arr) {
    SymbolNode* head=list.head;
    while(head!= nullptr){
        if(head->data.name_sb == name ){
            return true;
        }
        head=head->next;
    }
    return false;
}

bool SymbolTable::contains_scope(SymbolTable &list, Symbol symbol, int *arr) {
    return false;
}

void SymbolTable::add_Symbol(SymbolTable &list, Symbol symbol) {
    if( head == nullptr  ) {
        SymbolNode *temp=new SymbolNode;
        temp->data= symbol;
        temp->next = head;
        head=temp;
        cout<<"success with nullptr"<<endl;
    } else {
        SymbolNode *p=head;
        while(p->next != nullptr){
            p=p->next;
        }
        SymbolNode *temp = new SymbolNode;
        temp->data=symbol;
        temp->next = p ->next;
        p->next = temp;
        cout<<"success"<<endl;
    }
}

void SymbolTable::print_list(SymbolTable &list) {
    if(head == nullptr) cout<<"No elements";
    else {
        SymbolNode *temp = head;
        while(temp!= nullptr){
            cout<<temp->data.name_sb<<" "<<temp->data.type_sb<<" "<<temp->data.value_sb<<endl;
            cout<<"BEGIN : "<<temp->data.scope_sb[0]<<" & END : "<<temp->data.scope_sb[1]<<endl;
            temp = temp->next;
        }
    }
}