// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=469033
// Created by FUGUO on 2024/12/22.
//
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Player {
private:
    vector<string> cards;

public:
    Player(int n);
    ~Player();
    int tot_calculate();
    int calculate(string one_card, bool twoo);
};

Player::Player(int n) {
    if (n==0) return;
    for ( int i=0; i<n; i++) {
        string input;
        cin >> input ;
        cards.push_back(input);
//        cout << cards.back() << ",index:" << i << endl;
    }
};

Player::~Player() {
    cards.clear();
};

int Player::calculate(string card, bool twoo) {

    if ( "C10" == card ) return 0;

    // todo add the check of D11 and S12

    char type = card[0];

    card.erase(card.begin());

    int num=0;

    if ( 'H'==type) {
        switch(card[0]) {
            case '1' :
                if ( card == "1") {
                    num -= 50; break;
                } else if ( card == "10") {
                    num -= 10; break;
                } else if ( card == "11") {
                    num -= 20; break;
                } else if ( card == "12") {
                    num -= 30; break;
                } else if ( card == "13") {
                    num -= 40; break;
                }
            case '2' : num=-2; break;
            case '3' : num=-3; break;
            case '4' : num=-4; break;
            case '5' : num=-5; break;
            case '6' : num=-6; break;
            case '7' : num=-7; break;
            case '8' : num=-8; break;
            case '9' : num=-9; break;
            default: break;
        }
    } else if ( 'C' ==type) {
        num = 0;
    } else if ( 'S'==type && card == "12") {
        num -= 100;
    } else if ( 'D' == type && card == "11") {
        num += 100;
    }

    return twoo? 2*num:num;
};


int Player::tot_calculate () {

//    cout << "Begin Calculating" << endl;
    int point=0,uni_count=0;
    bool two=0,uni=0,S_check=0,D_check=0, SD_check=0;

    for ( auto &x : cards) {
//        cout << "Begin Checking Bools" << endl;
        if ( "C10" == x) two = true;
        if ( "C10" == x && 1 == cards.size()) return 50;
        if ( 'H' == x.front()) uni_count++;
        if ( "S12" == x) S_check = true;
        if ( "D11" == x) D_check = true;
    }

    if ( S_check && D_check) SD_check=true;
    if (uni_count ==13) uni = true;

    if( uni){
        point += 200;
        if ( SD_check ) {
            point += 300;
        } else if (S_check) {
            point -= 100;
        } else if (D_check) {
            point += 100;
        }

        if ( two ) {
            point *= 2;
        }
    } else {
        for (auto &x: cards) {
            point += calculate(x, two);
        }
    }
    return point;
};


int main() {
    int n;
    int zero_count = 0;
    int count=0;


    int output1=0,output2=0,output3=0,output4=0;
    for(;zero_count!=4;) {
        cin >> n;
        count ++;
//        cout << "check 0:" << n << endl;
        Player p(n);
//        cout << "check 1" << endl;
        if ( n==0) {
            zero_count++;
            if( count %4 == 1) output1=0;
            else if (count%4 == 2) output2=0;
            else if (count%4 == 3) output3=0;
            else if (count%4 == 0) output4=0;
        } else {
            if( count %4 == 1) output1=p.tot_calculate();
            else if (count%4 == 2) output2=p.tot_calculate();
            else if (count%4 == 3) output3=p.tot_calculate();
            else if (count%4 == 0) output4=p.tot_calculate();
        }
        if(count%4 == 0) {
            if ( zero_count != 4) {
                if (output1 > 0) cout << '+' << output1;
                else cout << output1;
                cout << ' ';
                if (output2 > 0) cout << '+' << output2;
                else cout << output2;
                cout << ' ';
                if (output3 > 0) cout << '+' << output3;
                else cout << output3;
                cout << ' ';
                if (output4 > 0) cout << '+' << output4;
                else cout << output4;
                cout << endl;
                zero_count = 0;
            } else {
                continue;
            }
        }
    }
    return 0;
}