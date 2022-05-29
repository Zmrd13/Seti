#include <iostream>
using namespace std;
#include <cstddef>
#include <cstring>
#include "cmath"
int string_size_2(const char *str) {

    size_t Size = strlen(str);
    return Size;
}
const char * ResetCells(int size,string current){

    for (int i = 0; i < (size*size) ; i++) {
        current[i]=' ';
    }
    return current.c_str();
}
void FieldDraw(int size,const char *in,const char * current){
    cout<<endl;
    int pos=0;
    sqrt(size);
    current=ResetCells(size,current);
    for(int i=0;i<=size*2;i++){
        if(i%2==0||i==size*2){
        for(int j=0;j<=size*2;j++){
        if(j%2==0||j==size*2){
            cout<<"+";
        }
        else{
            cout<<"---";
        }
        }
        cout<<endl;
        }
    else{
        for(int j=0;j<=size*2;j++){
            if(j%2==0||j==size*2){
                cout<<"+";
            }
            else{
                if(current[pos]==' ')
               cout<<" "+to_string(in[pos]-48)+" ";
                else{
                    cout<<" "+to_string(current[pos])+" ";
                }
                pos++;
            }
        }
        cout<<endl;
    }
    }
    }
//    for (int i = 2; i < size + 2 && i < string_size_2(pct); i++) {
//        pct[i];
//    }


string PacketWrapper(int size,int player,const char *pct){
    string wrap;
    wrap+= to_string(player);
    wrap+=to_string(size);
    for (int i = 2; i < (size*size) + 2 && i < string_size_2(pct)*string_size_2(pct); i++) {
        wrap+=pct[i];
    }

    return wrap;
}
int Field(int size,string wrap,const char * current){
    wrap.erase(0,2);
    cout<<wrap;
    FieldDraw(size,wrap.c_str(),current);
return 1;
}


int PacketInterpreter(const char *pct,const char * current) {

    int bound = (int) (unsigned char) pct[1] - 48;
  //bound*=bound;
    if (pct[0] == '0') {
        cout << pct;
        return 1;
    } else if (pct[0] == '1') {

Field(bound,PacketWrapper(bound,2,pct),current);
        return 2;
    } else {
        cerr << "PACKET READING ERROR";
        return -1;
    }
}
int main() {
    string testPacket;
    string current;
    int check = 1;
    while (check > 0) {
        cin >> testPacket;
        check = PacketInterpreter(testPacket.c_str(),current.c_str());
        cout << endl;
    }
    return 0;
}
