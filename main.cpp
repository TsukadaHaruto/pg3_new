#include "stdio.h"
#include <iostream>
#include <string>
#include <chrono>
int main() {

    // 100000文字の初期化
    std::string a(100000, 'a');
    std::string c(100000, 'c');
    std::move(a);

    // 100000文字のコピー
    auto start_copy = std::chrono::high_resolution_clock::now();
    std::string b = a;
    auto end_copy = std::chrono::high_resolution_clock::now();
    auto duration_copy = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();
    // 100000文字の移動
    auto start_move = std::chrono::high_resolution_clock::now();
    c = std::move(a);
    auto end_cop = std::chrono::high_resolution_clock::now();
    auto duration_move = std::chrono::duration_cast<std::chrono::microseconds>(end_cop - start_move).count();

    // 結果の表示
    std::cout << "100000文字のコピーにかかる時間: " << duration_copy << " μs" << std::endl;
    std::cout << "100000文字の移動にかかる時間: " << duration_move << " μs" << std::endl;

    return 0;
}