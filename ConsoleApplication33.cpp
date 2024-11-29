#include <iostream>
#include <string>

void manageStudentGrades() {
    const int MAX_GRADES = 100;
    int grades[MAX_GRADES], count = 0;

    while (true) {
        std::cout << "\n1. Додати оцінку\n"
            << "2. Видалити найнижчу оцінку\n"
            << "3. Розрахувати середній бал\n"
            << "4. Вивести список оцінок\n"
            << "5. Вивести список у зворотному порядку\n"
            << "6. Сортувати за зростанням\n"
            << "7. Сортувати за спаданням\n"
            << "0. Повернутись до головного меню\n"
            << "Ваш вибір: ";
        int choice;
        std::cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            if (count >= MAX_GRADES) {
                std::cout << "Список переповнений!\n";
                continue;
            }
            std::cout << "Введіть оцінку: ";
            std::cin >> grades[count++];
        }
        else if (choice == 2) {
            if (count == 0) {
                std::cout << "Список порожній!\n";
                continue;
            }
            int minIndex = 0;
            for (int i = 1; i < count; ++i)
                if (grades[i] < grades[minIndex])
                    minIndex = i;
            for (int i = minIndex; i < count - 1; ++i)
                grades[i] = grades[i + 1];
            --count;
            std::cout << "Найнижчу оцінку видалено.\n";
        }
        else if (choice == 3) {
            if (count == 0) {
                std::cout << "Список порожній!\n";
                continue;
            }
            int sum = 0;
            for (int i = 0; i < count; ++i)
                sum += grades[i];
            std::cout << "Середній бал: " << (double)sum / count << "\n";
        }
        else if (choice == 4) {
            if (count == 0) {
                std::cout << "Список порожній!\n";
                continue;
            }
            std::cout << "Список оцінок: ";
            for (int i = 0; i < count; ++i)
                std::cout << grades[i] << " ";
            std::cout << "\n";
        }
        else if (choice == 5) {
            if (count == 0) {
                std::cout << "Список порожній!\n";
                continue;
            }
            std::cout << "Список у зворотному порядку: ";
            for (int i = count - 1; i >= 0; --i)
                std::cout << grades[i] << " ";
            std::cout << "\n";
        }
        else if (choice == 6) {
            for (int i = 0; i < count - 1; ++i)
                for (int j = 0; j < count - i - 1; ++j)
                    if (grades[j] > grades[j + 1])
                        std::swap(grades[j], grades[j + 1]);
            std::cout << "Список відсортовано за зростанням.\n";
        }
        else if (choice == 7) {
            for (int i = 0; i < count - 1; ++i)
                for (int j = 0; j < count - i - 1; ++j)
                    if (grades[j] < grades[j + 1])
                        std::swap(grades[j], grades[j + 1]);
            std::cout << "Список відсортовано за спаданням.\n";
        }
        else {
            std::cout << "Невірний вибір!\n";
        }
    }
}

void decimalToBinary() {
    int number;
    int binary[32], top = -1;

    std::cout << "Введіть ціле число: ";
    std::cin >> number;

    while (number > 0) {
        binary[++top] = number % 2;
        number /= 2;
    }

    std::cout << "Двійкове представлення: ";
    for (int i = top; i >= 0; --i)
        std::cout << binary[i];
    std::cout << "\n";

    bool isPalindrome = true;
    for (int i = 0; i <= top / 2; ++i) {
        if (binary[i] != binary[top - i]) {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome)
        std::cout << "Двійкове число є паліндромом.\n";
    else
        std::cout << "Двійкове число не є паліндромом.\n";
}

void bankQueue() {
    const int MAX_CLIENTS = 100;
    std::string names[MAX_CLIENTS];
    int times[MAX_CLIENTS], front = 0, rear = 0, totalTime = 0;

    while (true) {
        std::cout << "\n1. Додати клієнта\n"
            << "2. Обслугувати клієнта\n"
            << "3. Вивести чергу\n"
            << "4. Загальний час обслуговування\n"
            << "0. Повернутись до головного меню\n"
            << "Ваш вибір: ";
        int choice;
        std::cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            if ((rear + 1) % MAX_CLIENTS == front) {
                std::cout << "Черга переповнена!\n";
                continue;
            }
            std::cout << "Введіть ім'я клієнта: ";
            std::cin >> names[rear];
            times[rear] = rand() % 20 + 1;
            rear = (rear + 1) % MAX_CLIENTS;
        }
        else if (choice == 2) {
            if (front == rear) {
                std::cout << "Черга порожня!\n";
                continue;
            }
            std::cout << "Обслуговується клієнт: " << names[front] << " (" << times[front] << " хвилин)\n";
            totalTime += times[front];
            front = (front + 1) % MAX_CLIENTS;
        }
        else if (choice == 3) {
            if (front == rear) {
                std::cout << "Черга порожня!\n";
                continue;
            }
            std::cout << "Черга: ";
            for (int i = front; i != rear; i = (i + 1) % MAX_CLIENTS)
                std::cout << names[i] << " ";
            std::cout << "\n";
        }
        else if (choice == 4) {
            std::cout << "Загальний час обслуговування: " << totalTime << " хвилин.\n";
        }
        else {
            std::cout << "Невірний вибір!\n";
        }
    }
}

void browserHistory() {
    const int MAX_HISTORY = 100;
    std::string history[MAX_HISTORY];
    int front = 0, back = 0;

    while (true) {
        std::cout << "\n1. Ввести URL\n"
            << "2. Назад\n"
            << "3. Вперед\n"
            << "4. Вивести історію\n"
            << "0. Повернутись до головного меню\n"
            << "Ваш вибір: ";
        int choice;
        std::cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            if ((back + 1) % MAX_HISTORY == front) {
                std::cout << "Історія переповнена!\n";
                continue;
            }
            std::cout << "Введіть URL: ";
            std::cin >> history[back];
            back = (back + 1) % MAX_HISTORY;
        }
        else if (choice == 2) {
            if (front == back) {
                std::cout << "Історія порожня!\n";
                continue;
            }
            back = (back - 1 + MAX_HISTORY) % MAX_HISTORY;
            std::cout << "Назад до: " << history[back] << "\n";
        }
        else if (choice == 3) {
           
        }
        else if (
