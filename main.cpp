#include <iostream>
#include <string>

using namespace std;

string email;

string first_part_address(string line) {
    string newLine;
    for (int i=0; i<line.length(); i++) {
        if (line[i]=='@') {
            return newLine;
        }
        newLine+=line[i];
    }
}

string second_part_address(string line) {
    string newLine;
    for (int i=line.length(); i>0; i--) {
        if (line[i]=='@') {
            return newLine;
        }
        newLine+=line[i];
    }
}

string mirror_line(string line) {
    string newLine;
    for(int i=line.length(); i>0; i--) {
        newLine+=line[i];
    }
    return newLine;
}

string before_symbol (string str) {
    string result;
    string checkStr = "'-.!#$%&*+-/=?^_`{|}~QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890"; //как ввести символ "\"
    int checkGood, checkBad = 0;
    if (str.length() < 1 && str.length() > 64) {
        result = "No";
        return result;
    } else {
        for (int i = 0; i < str.length(); i++) {
            for (int j = 0; j < checkStr.length(); j++) {
                if (str[i] == checkStr[j]) {
                    checkGood++;
                }
            }
        }
        for (int i = 0; i < str.length() - 1; i++) {
            if (str[0] == '.' || str[str.length()] == '.' || (str[i] == '.' && str[i + 1] == '.')) {
                checkBad++;
            }
        }
        return (checkGood == str.length() && checkBad == 0 ? "Yes" : "No");
    }
}

int main() {
    int count=0;
    cout << "Enter email: " << endl;
    getline(cin, email);
    for (int i=0; i<email.length(); i++) {
        if (email[i] == '@') {
            count++;
        }
    }
    string str= first_part_address(email);
    string result;
    string checkStr = "'-.!#$%&*+-/=?^_`{|}~QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890"; //как ввести символ "\"
    int checkGood, checkBad = 0;
    if (str.length() > 0 && str.length() < 65) {
        for (int i = 0; i < str.length(); i++) {
            for (int j = 0; j < checkStr.length(); j++) {
                if (str[i] == checkStr[j]) {
                    checkGood++;
                }
            }
        }
        for (int i = 0; i < str.length() - 1; i++) {
            if (str[0] == '.' || str[str.length()] == '.' || (str[i] == '.' && str[i + 1] == '.')) {
                checkBad++;
            }
        }
    } else {
        result = "No";
    }
    if (checkGood == str.length() && checkBad == 0) {
        result = "Yes";
    } else {
        result = "No";
    }
    cout<<checkGood<<endl<<str.length()<<endl<<checkBad<<endl<<result;
 //  cout<<first_part_address(email)<<endl;
  // cout<<(count!=1 ? "No email-address!" : before_symbol(first_part_address(email)));
}
