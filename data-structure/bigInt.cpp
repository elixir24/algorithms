#include <iostream>
#include <string>

using namespace std;

string addNum(const string number1, const string number2){

    string num1 = (number1.length() > number2.length()) ? number2: number1;
    string num2 = (number1.length() > number2.length()) ? number1: number2;
    int len1 = num1.length();
    int len2 = num2.length();

    int carry = 0;
    string add;
    int i = 0;

    for(; i < len1; i++){
        int s = (num1[i] - '0') + (num2[i] - '0') + carry;
        add +=  (s % 10) + '0' ;
        carry = s / 10;
    }

    while(i < len2){
        int s = (num2[i] - '0') + carry;
        add +=  (s % 10) + '0' ;
        carry = s / 10;
        i++;
    }

   if (carry > 0)
    add += carry + '0';

   return add;
}

string multiSingle(const string str, const int digit){
    if( digit == 0)
        return "0";
    else {
        int i = 0;
        string ans;
        int carry = 0;
        while (i < str.length()){
            int d = ((str[i] - '0') * digit) + carry;
            ans += (d % 10) + '0';
            carry = d / 10;
            i++;
        }
        if(carry > 0)
            ans += carry + '0';
        return ans;
    }
}

string multiNum(const string n1, const string n2){
   string num1, num2;
   if (n1.length() > n2.length()){
       num1 = n2; num2= n1;
   }else{
       num1 = n1; num2 = n2;
   }
   int d = num1[0] - '0';
   int remlen = num1.length() - 1;
   string single = multiSingle(num2, d);
   if(remlen > 0){
        string rem = num1.substr(1, remlen);
        string recur = multiNum(rem, num2);
        return addNum(single, "0" + recur);
   } else {
        return single;
   }
}

string makeNum(){
   string num;
   getline(cin, num);
   reverse(num.begin(), num.end());
   return num;
}

void displayNum(string num){
    reverse(num.begin(), num.end());
    cout<<num<<endl;
    return;
}

int main(){
    string num1 = makeNum();
    string num2 = makeNum();
    displayNum(multiNum(num1, num2));
    return 0;
}
