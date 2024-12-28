// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=468947
// Created by FUGUO on 2024/12/25.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 获取花色对应的数值
int flowerKey(const std::string& card) {
    std::string flowers = "CDSH";
    for (size_t i = 0; i < flowers.size(); ++i) {
        if (card[0] == flowers[i]) return i + 1;
    }
    return 0;  // 花色输入错误
}

// 获取数字对应的数值
int numKey(const std::string& card) {
    std::vector<std::string> nums = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for (size_t i = 0; i < nums.size(); ++i) {
        if (card.substr(1) == nums[i]) return i + 1;
    }
    return 0;  // 数字输入错误
}

// 检查输入是否合法
bool checkInput(const std::vector<std::string>& player) {
    for (size_t i = 0; i < player.size(); ++i) {
        for (size_t m = i + 1; m < player.size(); ++m) {
            if (player[i] == player[m]) return false;  // 有相同的牌，输入错误
        }
        if (flowerKey(player[i]) == 0 || numKey(player[i]) == 0) return false;  // 花色或数字错误
    }
    return true;
}

// 排序玩家的卡牌
void playerSort(std::vector<std::string>& player) {
    std::sort(player.begin(), player.end(), [](const std::string& a, const std::string& b) {
        int numA = numKey(a);
        int numB = numKey(b);
        if (numA != numB) return numA > numB;
        return flowerKey(a) > flowerKey(b);
    });
}

// 获取牌型的数值
int getKey(const std::vector<std::string>& player) {
    for (size_t i = 0; i < player.size() - 1; ++i) {
        if (flowerKey(player[i]) != flowerKey(player[i + 1])) break;
        if (i == player.size() - 2 && numKey(player[0]) - 1 == numKey(player[1]) && numKey(player[0]) - 2 == numKey(player[2]) && numKey(player[0]) >= 3) return 5;
    }
    for (size_t i = 0; i < player.size() - 1; ++i) {
        if (numKey(player[i]) != numKey(player[i + 1])) break;
        if (i == player.size() - 2) return 4;
    }
    if (numKey(player[0]) - 1 == numKey(player[1]) && numKey(player[0]) - 2 == numKey(player[2]) && numKey(player[0]) >= 3) return 3;
    if (numKey(player[0]) == numKey(player[1]) || numKey(player[1]) == numKey(player[2])) return 2;
    return 1;
}

// 获取对子中第一张牌的位置
int doublePlace(const std::vector<std::string>& player) {
    if (numKey(player[0]) == numKey(player[1])) return 0;
    return 1;
}

// 判断谁是赢家
int whoWin(const std::vector<std::string>& player1, const std::vector<std::string>& player2) {
    int count = 0;
    for (size_t i = 0; i < player1.size(); ++i) {
        if (player1[i] == player2[i]) ++count;
    }
    if (count == player1.size()) return 2;  // 平局

    int key1 = getKey(player1);
    int key2 = getKey(player2);
    if (key1 > key2) return 0;
    if (key1 < key2) return 1;

    if (key1 == key2 && key1 == 5) {
        if (numKey(player1[0]) > numKey(player2[0])) return 0;
        if (numKey(player1[0]) < numKey(player2[0])) return 1;
        if (flowerKey(player1[0]) > flowerKey(player2[0])) return 0;
        if (flowerKey(player1[0]) < flowerKey(player2[0])) return 1;
    }

    if (key1 == key2 && key1 == 4) {
        if (numKey(player1[0]) > numKey(player2[0])) return 0;
        if (numKey(player1[0]) < numKey(player2[0])) return 1;
        for (size_t i = 0; i < player1.size(); ++i) {
            if (flowerKey(player1[i]) > flowerKey(player2[i])) return 0;
            if (flowerKey(player1[i]) < flowerKey(player2[i])) return 1;
        }
    }

    if (key1 == key2 && key1 == 3) {
        if (numKey(player1[0]) > numKey(player2[0])) return 0;
        if (numKey(player1[0]) < numKey(player2[0])) return 1;
        for (size_t i = 0; i < player1.size(); ++i) {
            if (flowerKey(player1[i]) > flowerKey(player2[i])) return 0;
            if (flowerKey(player1[i]) < flowerKey(player2[i])) return 1;
        }
    }

    if (key1 == key2 && key1 == 2) {
        int place1 = doublePlace(player1);
        int place2 = doublePlace(player2);
        if (numKey(player1[place1]) > numKey(player2[place2])) return 0;
        if (numKey(player1[place1]) < numKey(player2[place2])) return 1;
        for (size_t i = 0; i < 2; ++i) {
            if (flowerKey(player1[place1 + i]) > flowerKey(player2[place2 + i])) return 0;
            if (flowerKey(player1[place1 + i]) < flowerKey(player2[place2 + i])) return 1;
        }
    }

    for (size_t i = 0; i < player1.size(); ++i) {
        if (numKey(player1[i]) > numKey(player2[i])) return 0;
        if (numKey(player1[i]) < numKey(player2[i])) return 1;
        if (flowerKey(player1[i]) > flowerKey(player2[i])) return 0;
        if (flowerKey(player1[i]) < flowerKey(player2[i])) return 1;
    }

    return 0;  // 默认玩家1赢
}

int main() {
    std::vector<std::string> player1(3), player2(3);
    std::cin >> player1[0] >> player1[1] >> player1[2];
    std::cin >> player2[0] >> player2[1] >> player2[2];

    if (!checkInput(player1) || !checkInput(player2)) {
        std::cout << "Input Error!" << std::endl;
        return 0;
    }

    playerSort(player1);
    playerSort(player2);

    switch (whoWin(player1, player2)) {
        case 0:
            std::cout << "Winner is A!" << std::endl;
            break;
        case 1:
            std::cout << "Winner is B!" << std::endl;
            break;
        case 2:
            std::cout << "Draw!" << std::endl;
    }

    std::cout << "A:";
    for (const auto &card: player1) std::cout << " " << card;
    std::cout << std::endl;

    std::cout << "B:";
    for (const auto &card: player2) std::cout << " " << card;
    std::cout << std::endl;

    return 0;
}
