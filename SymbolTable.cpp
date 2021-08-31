#include "SymbolTable.h"
using namespace std;
void SymbolTable::run(string filename){
    SymbolTable list;
    Symbol symbol("x","Number");
    Symbol symbol1("y","Number");
    Symbol symbol2("z","Number");
    Symbol symbol3("t","Number");
    add_Symbol(list,symbol);
    add_Symbol(list,symbol1);
    add_Symbol(list,symbol2);
    add_Symbol(list,symbol3);
    print_list(list);
    string line,method,name,attribue;
    int *arr = new int[2]{0};
    fstream input_file;
    int count = 0;
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
bool SymbolTable::contains(SymbolTable &list, Symbol symbol,int *arr) {
    SymbolNode* head=list.head;
    while(head!= nullptr){
        if(head->data.name_sb == symbol.name_sb ){
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
    if( list.head == nullptr  ) {
        SymbolNode *head=list.head;
        SymbolNode *temp=new SymbolNode;
        temp->data= symbol;
        temp->next = list.head;
        head = temp;
        cout<<"success with nullptr"<<endl;
    } else {
        SymbolNode *head = list.head;
        while(head->next != nullptr){
            head=head->next;
        }
        SymbolNode *temp = new SymbolNode;
        temp->data=symbol;
        temp->next = head ->next;
        head->next = temp;
        cout<<"success"<<endl;
    }

}

void SymbolTable::print_list(SymbolTable &list) {
    if(list.head == nullptr) cout<<"No elements";
    else {
        SymbolNode *temp = list.head;
        while(temp!= nullptr){
            cout<<temp->data.name_sb<<" "<<temp->data.type_sb<<" "<<temp->data.value_sb<<endl;
            cout<<"BEGIN : "<<temp->data.scope_sb[0]<<" & END : "<<temp->data.scope_sb[1]<<endl;
            temp = temp->next;
        }
    }
}
/*bool contains (SLinkedList& list, Soldier soldier){
    //Check if array contains soldier
    SoldierNode* head=list.head;
    while(head!=nullptr){
        if((head->data.ID== soldier.ID) && (head->data.HP==soldier.HP) && (head->data.isSpecial==soldier.isSpecial)){
            return true;
        }
        head=head->next;
    }
    return false;
*/
