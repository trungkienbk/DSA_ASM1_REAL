/*#include "SymbolTable.h"
#include <sstream>;
using namespace std;
int global_scope = 0;
int row = 0;
SymbolTable list;
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
{   Symbol symbol("x","Number");
    Symbol symbol1("y","Number");
    Symbol symbol2("z","Number");
    Symbol symbol3("t","Number");
    add_Symbol(list,symbol);
    add_Symbol(list,symbol1);
    add_Symbol(list,symbol2);
    add_Symbol(list,symbol3);
    pair<int,int> check;
    string lineInput,method,name,var;
    fstream input;
    input.open(filename);
    if(input){
        while(std::getline(input,lineInput)){
            istringstream(lineInput)>>method>>name>>var;
            //cout<<lineInput<<"|| Method :"<<method<<" || Name :"<<name<<"|| Var : "<<var<<endl;
           int numberMethod = convertInt(method);
           //Insert: 1 Lookup:2 Assign:3 Print:4 RPrint:5 Begin:6 End:7
           switch(numberMethod){
               case 1:
               //    cout<<"Ham 1"<<endl;
                   break;
               case 2:
                  // cout<<"Ham 2"<<endl;
                   break;
               case 3:
                 //  cout<<"Ham 3"<<endl;
                   break;
               case 4:
                 //  cout<<"Ham 4"<<endl;
                   break;
               case 5:
                  // cout<<"Ham 5"<<endl;
                    break;
               case 6:
                   row++;
                //   cout<<"Ham 6"<<endl;
                   break;
               default:
                   if(row == 0) throw UnknownBlock();
                   row--;
                  // cout<<"Ham 7"<<endl;
                   break;
           }
        }
    }
    else {
        cout<<filename<<" not exist";
    }
}

void SymbolTable::add_Symbol(SymbolTable &list, Symbol symbol) {
    if( list.head == nullptr  ) {
        Node *head=list.head;
        Node *temp=new Node;
        temp->data= symbol;
        temp->next = list.head;
        head = temp;
        cout<<"success with nullptr"<<endl;
    } else {
        Node *head = list.head;
        while(head->next != nullptr){
            head=head->next;
        }
        Node *temp = new Node;
        temp->data=symbol;
        temp->next = head ->next;
        head->next = temp;
        cout<<"success"<<endl;
    }
}
void SymbolTable::print_list(SymbolTable &list) {
    if(list.head == nullptr) cout<<"No elements";
    else {
        Node *temp = list.head;
        while(temp!= nullptr){
            cout<<temp->data.name<<" "<<temp->data.type<<" "<<temp->data.value<<endl;
            temp = temp->next;
        }
    }
}
*/
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
    SymbolNode* phead=head;
    while(phead!= nullptr){
        if(phead->data.name_sb == symbol.name_sb ){
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
        head = temp;
        cout<<"success with nullptr"<<endl;
    } else {
        SymbolNode *phead = head;
        while(phead->next != nullptr){
            phead=phead->next;
        }
        SymbolNode *temp = new SymbolNode;
        temp->data=symbol;
        temp->next = phead ->next;
        phead->next = temp;
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