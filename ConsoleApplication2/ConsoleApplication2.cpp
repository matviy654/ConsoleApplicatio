#include <iostream>
#include <thread>  // Для управління швидкістю виведення
#include <cstdlib> // Для генерації випадкових чисел
#include <ctime>
#include <vector>
#include <limits> // Для визначення min/max значень

// Завдання 1: Виведення лінії заданим символом із вибором швидкості
void drawLine() {
    char symbol;
    char direction;
    int length;
    int speed;

    std::cout << "Завдання 1. Введіть символ для лінії: ";
    std::cin >> symbol;
    std::cout << "Введіть довжину лінії: ";
    std::cin >> length;
    std::cout << "Виберіть напрямок (h - горизонтальний, v - вертикальний): ";
    std::cin >> direction;
    std::cout << "Виберіть швидкість (1 - швидко, 2 - нормально, 3 - повільно): ";
    std::cin >> speed;

    int delay = 0;
    switch (speed) {
    case 1: delay = 50; break;
    case 2: delay = 200; break;
    case 3: delay = 500; break;
    default: delay = 200; break;
    }

    if (direction == 'h') {
        for (int i = 0; i < length; ++i) {
            std::cout << symbol;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
    }
    else if (direction == 'v') {
        for (int i = 0; i < length; ++i) {
            std::cout << symbol << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
    }
    else {
        std::cout << "Невірний напрямок!" << std::endl;
    }
    std::cout << std::endl;
}

// Завдання 2: Гра "Кубики"
void diceGame() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел
    int userSum = 0, compSum = 0;

    std::cout << "Завдання 2. Гра 'Кубики'. 3 раунди.\n";

    for (int round = 1; round <= 3; ++round) {
        int userRoll = (rand() % 6 + 1) + (rand() % 6 + 1);
        int compRoll = (rand() % 6 + 1) + (rand() % 6 + 1);
        userSum += userRoll;
        compSum += compRoll;

        std::cout << "Раунд " << round << ": Ви кинули " << userRoll << ", Комп'ютер кинула " << compRoll << std::endl;
    }

    std::cout << "Ваша сума: " << userSum << ", Сума комп'ютера: " << compSum << std::endl;
    if (userSum > compSum) {
        std::cout << "Ви перемогли!" << std::endl;
    }
    else if (userSum < compSum) {
        std::cout << "Комп'ютер переміг!" << std::endl;
    }
    else {
        std::cout << "Нічия!" << std::endl;
    }
}

// Завдання 3: Знайти мінімальний та максимальний елементи в масиві
void findMinMax() {
    std::vector<int> arr(10);
    srand(time(0));

    std::cout << "Завдання 3. Масив:\n";
    for (int& num : arr) {
        num = rand() % 100;
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int min = arr[0], max = arr[0];
    for (int num : arr) {
        if (num < min) min = num;
        if (num > max) max = num;
    }

    std::cout << "Мінімальний елемент: " << min << std::endl;
    std::cout << "Максимальний елемент: " << max << std::endl;
}

// Завдання 4: Пошук місяця з максимальним і мінімальним прибутком в діапазоні
void findProfitRange() {
    std::vector<int> profit(12);

    std::cout << "Завдання 4. Введіть прибуток за 12 місяців:\n";
    for (int i = 0; i < 12; ++i) {
        std::cout << "Місяць " << i + 1 << ": ";
        std::cin >> profit[i];
    }

    int start, end;
    std::cout << "Введіть діапазон місяців (наприклад, 3 і 6): ";
    std::cin >> start >> end;
    --start; --end; // Для зручності індексації

    int maxProfit = profit[start], minProfit = profit[start];
    int maxMonth = start + 1, minMonth = start + 1;

    for (int i = start; i <= end; ++i) {
        if (profit[i] > maxProfit) {
            maxProfit = profit[i];
            maxMonth = i + 1;
        }
        if (profit[i] < minProfit) {
            minProfit = profit[i];
            minMonth = i + 1;
        }
    }

    std::cout << "Максимальний прибуток у місяці: " << maxMonth << " (" << maxProfit << ")\n";
    std::cout << "Мінімальний прибуток у місяці: " << minMonth << " (" << minProfit << ")\n";
}

// Завдання 5: Обчислення різних величин у масиві
void arrayCalculations() {
    int N;
    std::cout << "Завдання 5. Введіть розмір масиву N: ";
    std::cin >> N;

    std::vector<double> arr(N);
    std::cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    // 1. Сума від'ємних елементів
    double sumNegative = 0;
    for (double num : arr) {
        if (num < 0) {
            sumNegative += num;
        }
    }

    // 2. Добуток елементів між мінімальним і максимальним
    double min = arr[0], max = arr[0];
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < N; ++i) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }

    double productBetweenMinMax = 1;
    if (minIndex < maxIndex) {
        for (int i = minIndex + 1; i < maxIndex; ++i) {
            productBetweenMinMax *= arr[i];
        }
    }
    else {
        for (int i = maxIndex + 1; i < minIndex; ++i) {
            productBetweenMinMax *= arr[i];
        }
    }

    // 3. Добуток елементів з парними номерами
    double productEven = 1;
    for (int i = 0; i < N; i += 2) {
        productEven *= arr[i];
    }

    // 4. Сума елементів між першим і останнім від'ємними
    int firstNegative = -1, lastNegative = -1;
    for (int i = 0; i < N; ++i) {
        if (arr[i] < 0) {
            if (firstNegative == -1) {
                firstNegative = i;
            }
            lastNegative = i;
        }
    }

    double sumBetweenNegatives = 0;
    if (firstNegative != -1 && lastNegative != -1 && firstNegative < lastNegative) {
        for (int i = firstNegative + 1; i < lastNegative; ++i) {
            sumBetweenNegatives += arr[i];
        }
    }

    // Виведення результатів
    std::cout << "Сума від'ємних елементів: " << sumNegative << std::endl;
    std::cout << "Добуток між мінімальним і максимальним: " << productBetweenMinMax << std::endl;
    std::cout << "Добуток елементів з парними номерами: " << productEven << std::endl;
    std::cout << "Сума між першим і останнім від'ємними: " << sumBetweenNegatives << std::endl;
}

int main() {
    int choice;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Вивести лінію заданим символом\n";
        std::
