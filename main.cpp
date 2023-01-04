#include <bits/stdc++.h>

using namespace std;

void separateIp(int segments[], string ip);
void submaskValid(int submask);
string getBinaryNumber(int num);
string ipClass(int ip[]);

int main()
{
    int segments[4], mask = 0, subMask = 0;
    string ip;

    cout << "Ingrese la ip -> ";
    cin >> ip;
    separateIp(segments, ip);
    cout << "Ingrese la submascara actual -> ";
    cin >> mask;
    submaskValid(mask);
    cout << "Ingrese la submascara a convertir -> ";
    cin >> subMask;
    submaskValid(subMask);
    cout<<"Convertir"<<endl;
    cout<<ip<<"/"<<mask<<" -> "<<subMask<<endl;
    cout<<"Ip binary -> ";
    for(int i=0;i<4;i++){
        cout<<getBinaryNumber(segments[i]);
        if(i != 3)
            cout<<".";
    }
    cout<<" "<<ipClass(segments);
    cout<<endl;
    return 0;
}

void separateIp(int segments[], string ip)
{
    string components[4] = {"", "", "", ""};
    int j = 0, points = 0;
    for (int i = 0; i < ip.size(); i++)
    {
        if (ip[i] == '.')
        {
            j++;
            points++;
        }
        else
        {
            components[j] += ip[i];
        }
    }
    if (points != 3)
    {
        cout << "Ip invalida" << endl;
        exit(-1);
    }
    try
    {
        for (int i = 0; i < 4; i++)
        {
            segments[i] = stoi(components[i]);
            if (segments[i] < 0 || segments[i] > 255)
            {
                cout << "Ip invalida con rangos invalidos" << endl;
                exit(-1);
            }
        }
    }
    catch (invalid_argument const &e)
    {
        cout << "Error al convertir" << endl;
        exit(-1);
    }
}

void submaskValid(int mask)
{
    if (mask < 1 || mask > 32)
    {
        cout << "Submascara invalida" << endl;
        exit(-1);
    }
}

string getBinaryNumber(int num){
    int number = num;
    if(number == 0)
        return "0";
    string binary = "";
    while (number>0)
    {
        if((number%2) == 0)
            binary = "0" + binary;
        else
            binary = "1" + binary;
        number = (int)number/2;
    }
    for(int i=binary.size()-1;i<7;i++)
        binary = "0" + binary;
    return binary;
}

string ipClass(int ip[]){
    if(ip[0] >= 1 && ip[0] <= 126)
        return "Class A";
    else if(ip[0] >= 128 && ip[0] <= 191)
        return "Class B";
    else if(ip[0] >= 192 && ip[0] <= 223)
        return "Class C";
    else
        return "Clase desconocida";
}