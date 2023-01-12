#include <bits/stdc++.h>

using namespace std;

string getWilcardIp(int mask);
string getWilcardBinary(int mask);
string getNetmaskIp(int mask);
string getNetmaskBinary(int mask);
string ipToBinaryIp(string ip);
string binaryIpToIp(string ip);
string binaryToNumber(string binaryNum);
string intToBinary(int n);
bool ipValid(string ip);
vector<string> split(const string &str, char delim);
bool isNumber(const string &str);

int main()
{
    int mask = 0, subMask = 0;
    string ip;

    cout<<"Ingrese la IP -> "; cin >> ip;
    if(!ipValid(ip)) { cout<<"La Ip es invalida"<<endl; exit(-1); }
    cout<<"Ingrese la mascara -> "; cin >> mask;
    if(mask < 1 || mask >32) { cout<<"Mascara invalida"<<endl; exit(-1); }
    cout<<"Ingrese la submascara a convertir -> "; cin >> subMask;
    if(subMask < 1 || subMask >32) { cout<<"Submascara invalida"<<endl; exit(-1); }
    //Muestreo de datos
    cout<<"Calculando datos..."<<endl;
    cout<<"Address:\t"<<ip<<"\t\t"<<ipToBinaryIp(ip)<<endl;
    cout<<"Netmask:\t"<<getNetmaskIp(mask)<<" = "<<mask<<"\t\t"<<getNetmaskBinary(mask)<<endl;
    cout<<"Wilcard:\t"<<getWilcardIp(mask)<<"\t\t"<<getWilcardBinary(mask)<<endl;
    cout<<"=>"<<endl;
    cout<<"Network:\t"<<getNetmaskIp(mask)<<"/"<<mask<<"\t\t"<<getNetmaskBinary(mask)<<endl;
    cout<<"HostMin:\t"<<"ip"<<"\t\t"<<"binary"<<endl;
    return 0;
}

string getWilcardIp(int mask){
    return binaryIpToIp(getWilcardBinary(mask));
}

string getWilcardBinary(int mask){
    string binaryMask = "", aux = "";
    int contador = 0;
    for(int i = 0; i < 32; i++){
        aux += (i > (mask-1))?"1":"0";
        contador++;
        if(contador == 8){
            binaryMask += aux;
            if(i != 31)
                binaryMask += ".";
            contador = 0;
            aux = "";
        }
    }
    return binaryMask;
}

string getNetmaskIp(int mask){
    return binaryIpToIp(getNetmaskBinary(mask));
}

string getNetmaskBinary(int mask){
    string binaryMask = "", aux = "";
    int contador = 0;
    for(int i = 0; i < 32; i++){
        aux += (i < mask)?"1":"0";
        contador++;
        if(contador == 8){
            binaryMask += aux;
            if(i != 31)
                binaryMask += ".";
            contador = 0;
            aux = "";
        }
    }
    return binaryMask;
}

string ipToBinaryIp(string ip){
    int counter = 0;
    vector<string> segments = split(ip, '.');
    string binaryIp = "";
    for(string segment : segments){
        binaryIp += intToBinary(stoi(segment));
        if(counter != 3)
            binaryIp += ".";
        counter++;
    }
    return binaryIp;
}

string binaryIpToIp(string ip){
    int counter = 0;
    vector<string> segments = split(ip, '.');
    string ipConvert = "";
    for(string segment : segments){
        ipConvert += binaryToNumber(segment);
        if(counter != 3)
            ipConvert += ".";
        counter++;
    }
    return ipConvert;
}

string binaryToNumber(string binaryNum) {
    return to_string(stoll(binaryNum, nullptr, 2));
}

string intToBinary(int n){
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

bool ipValid(string ip){
    vector<string> list = split(ip, '.');
    if (list.size() != 4)
        return false;
    for (string str: list)
        if (!isNumber(str) || stoi(str) > 255 || stoi(str) < 0)
            return false;
    return true;
}

vector<string> split(const string &str, char delim){
    auto i = 0;
    vector<string> list;
    auto pos = str.find(delim);
    while (pos != string::npos){
        list.push_back(str.substr(i, pos - i));
        i = ++pos;
        pos = str.find(delim, pos);
    }
    list.push_back(str.substr(i, str.length()));
    return list;
}

bool isNumber(const string &str){
    return !str.empty() && (str.find_first_not_of("[0123456789]") == std::string::npos);
}