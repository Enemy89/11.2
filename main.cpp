#include <iostream>
#include <string>

using namespace std;

string IPv4;
int address_part;

string octet (string ip, int partNumber) {
    int count = 0;
    string part;
    for (int i = 0; i < ip.length(); i++) {
        if (ip[i] == '.') {
            count++;
            if (count == partNumber) {
                return part;
            }
            part="";
        }
        else {
            part += ip[i];
        }
    }
}

string check_octet (string octet) {
    string mark="false";
    int octetInt = stoi(octet);
    if (octet.length() > 0 && octet.length() < 4 && (octetInt>=0 && octetInt<=255)) {
        for (int i = 0; i < octet.length(); i++) {
            if (octet[i] >= '0' && octet[i] <= '9') {
                mark="true";
                 return mark;
            }
            else {
                return mark;
            }
        }
    } else {
        mark = "false";
        return mark;
    }
}

int main() {
    cout << "Enter IP and number octet:" << endl;
    getline(cin, IPv4);
    /*string one = octet(IPv4,1);
    string two = octet(IPv4,2);
    string three = octet(IPv4,3);
    string four = octet(IPv4,4);
    cout<<one<<endl<<two<<endl<<three<<endl<<four<<endl;
    cout<<check_octet(octet(IPv4, 1))<<endl;*/
    if (check_octet(octet(IPv4, 1)) == "true" && check_octet(octet(IPv4, 2)) == "true"
        && check_octet(octet(IPv4, 3)) == "true" && check_octet(octet(IPv4, 4)) == "true") {
        cout << "Valid"<<endl;
    } else
        cout << "Invalid"<<endl;
     cout<<check_octet(octet(IPv4,1))<<endl;
     cout<<check_octet(octet(IPv4,2))<<endl;
     cout<<check_octet(octet(IPv4,3))<<endl;
     cout<<check_octet(octet(IPv4,4))<<endl;
}
