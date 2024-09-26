#include "stdio.h"
#include <iostream>
#include <string>
#include <chrono>
int main() {

    // 100000�����̏�����
    std::string a(100000, 'a');
    std::string c(100000, 'c');
    std::move(a);

    // 100000�����̃R�s�[
    auto start_copy = std::chrono::high_resolution_clock::now();
    std::string b = a;
    auto end_copy = std::chrono::high_resolution_clock::now();
    auto duration_copy = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();
    // 100000�����̈ړ�
    auto start_move = std::chrono::high_resolution_clock::now();
    c = std::move(a);
    auto end_cop = std::chrono::high_resolution_clock::now();
    auto duration_move = std::chrono::duration_cast<std::chrono::microseconds>(end_cop - start_move).count();

    // ���ʂ̕\��
    std::cout << "100000�����̃R�s�[�ɂ����鎞��: " << duration_copy << " ��s" << std::endl;
    std::cout << "100000�����̈ړ��ɂ����鎞��: " << duration_move << " ��s" << std::endl;

    return 0;
}