#include "SymbolTable.h"
using namespace std;
void SymbolTable::run(string filename){
    string line,method,name,attribue;
    int *arr = new int[2]{0};
    SymbolTable list;
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
bool SymbolTable::contains(SymbolTable &list, Symbol symbol,int *arr) {
    bool flag = true;
    SymbolNode* head=list.head();
    while(head!= nullptr){
        if(head->data.name_sb == symbol.name_sb ){
            flag = false;
            break;
        }
        head=head->next;
    }
    if(flag) return false;
    else {
        SymbolNode* phead=list.head();
        while(phead!= nullptr){
            if(phead->data.name_sb == symbol.name_sb && arr[0] > symbol.scope_sb[0] ){
                return false;
            }
            phead = phead->next;
        }
    }
    return true;
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
}*/


