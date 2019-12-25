#include <iostream>
using namespace std;

long long stoi(string str){
    long long times = 1, num = 0;
    int length = 0;
    while(str[length] != '\0'){
        length++;
    }
    for(int pos = length - 1; pos >= 0; pos--){
        num = num + (str[pos] - '0') * times;
        times *= 10;
    }
    return num;
}
int add(long long num, long long time){ //偶數位加總
    int i = num % (time * 10) / time * 2;
    i = i / 10 + i % 10;
    return i;
}
int add2(long long num, long long time2){ //奇數位加總
    int i = num % (time2 * 10) / time2;
    i = i / 10 + i % 10;
    return i;
}
int main(){
    string str;
    long long num, time = 10, time2 = 1;
    int sum = 0;
    do{
        cout << "請輸入您的信用卡卡號：";
        cin >> str;

        num = stoi(str);

        if(num < 1000000000000 or num > 9999999999999999){
            cout << "輸入錯誤。請重新輸入。\n";
        }
        else{
            while(num / time > 0){
                sum = sum + add(num, time) + add2(num, time2);
                time *= 100;
                time2 *= 100;
            }
            if(sum % 10 == 0){
                if(num > 999999999999 and num < 10000000000000){
                    if(num / 1000000000000 == 4){
                        cout << "此信用卡有效。其所屬公司為VISA。";
                    }
                    else{
                        cout << "此信用卡無效。";
                    }
                }
                else if(num > 99999999999999 and num < 1000000000000000){
                    if(num / 10000000000000 == 34 or num / 1000000000000 == 37){
                        cout << "此信用卡有效。其所屬公司為American Express。";
                    }
                    else{
                        cout << "此信用卡無效。";
                    }
                }
                else if(num > 999999999999999 and num < 10000000000000000){
                    if(num / 1000000000000000 == 4){
                        cout << "此信用卡有效。其所屬公司為VISA。";
                    }
                    else if(num / 100000000000000 == 51 or num / 100000000000000 == 52 or num / 100000000000000 == 53 or num / 100000000000000 == 54 or num / 100000000000000 == 55){
                        cout << "此信用卡有效。其所屬公司為MasterCard。";
                    }
                    else{
                        cout << "此信用卡無效。";
                    }
                }
            }
            else{
                cout << "此信用卡無效。";
            }
        }
    } while(num < 1000000000000 or num > 9999999999999999);
}
