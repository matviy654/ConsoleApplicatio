#include <iostream>
#include <thread>  // ��� ��������� �������� ���������
#include <cstdlib> // ��� ��������� ���������� �����
#include <ctime>
#include <vector>
#include <limits> // ��� ���������� min/max �������

// �������� 1: ��������� �� ������� �������� �� ������� ��������
void drawLine() {
    char symbol;
    char direction;
    int length;
    int speed;

    std::cout << "�������� 1. ������ ������ ��� ��: ";
    std::cin >> symbol;
    std::cout << "������ ������� ��: ";
    std::cin >> length;
    std::cout << "������� �������� (h - ��������������, v - ������������): ";
    std::cin >> direction;
    std::cout << "������� �������� (1 - ������, 2 - ���������, 3 - �������): ";
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
        std::cout << "������� ��������!" << std::endl;
    }
    std::cout << std::endl;
}

// �������� 2: ��� "������"
void diceGame() {
    srand(time(0)); // ����������� ���������� ���������� �����
    int userSum = 0, compSum = 0;

    std::cout << "�������� 2. ��� '������'. 3 ������.\n";

    for (int round = 1; round <= 3; ++round) {
        int userRoll = (rand() % 6 + 1) + (rand() % 6 + 1);
        int compRoll = (rand() % 6 + 1) + (rand() % 6 + 1);
        userSum += userRoll;
        compSum += compRoll;

        std::cout << "����� " << round << ": �� ������ " << userRoll << ", ����'���� ������ " << compRoll << std::endl;
    }

    std::cout << "���� ����: " << userSum << ", ���� ����'�����: " << compSum << std::endl;
    if (userSum > compSum) {
        std::cout << "�� ���������!" << std::endl;
    }
    else if (userSum < compSum) {
        std::cout << "����'���� ������!" << std::endl;
    }
    else {
        std::cout << "ͳ���!" << std::endl;
    }
}

// �������� 3: ������ ��������� �� ������������ �������� � �����
void findMinMax() {
    std::vector<int> arr(10);
    srand(time(0));

    std::cout << "�������� 3. �����:\n";
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

    std::cout << "̳�������� �������: " << min << std::endl;
    std::cout << "������������ �������: " << max << std::endl;
}

// �������� 4: ����� ����� � ������������ � ��������� ��������� � �������
void findProfitRange() {
    std::vector<int> profit(12);

    std::cout << "�������� 4. ������ �������� �� 12 ������:\n";
    for (int i = 0; i < 12; ++i) {
        std::cout << "̳���� " << i + 1 << ": ";
        std::cin >> profit[i];
    }

    int start, end;
    std::cout << "������ ������� ������ (���������, 3 � 6): ";
    std::cin >> start >> end;
    --start; --end; // ��� �������� ����������

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

    std::cout << "������������ �������� � �����: " << maxMonth << " (" << maxProfit << ")\n";
    std::cout << "̳�������� �������� � �����: " << minMonth << " (" << minProfit << ")\n";
}

// �������� 5: ���������� ����� ������� � �����
void arrayCalculations() {
    int N;
    std::cout << "�������� 5. ������ ����� ������ N: ";
    std::cin >> N;

    std::vector<double> arr(N);
    std::cout << "������ �������� ������:\n";
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    // 1. ���� ��'����� ��������
    double sumNegative = 0;
    for (double num : arr) {
        if (num < 0) {
            sumNegative += num;
        }
    }

    // 2. ������� �������� �� ��������� � ������������
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

    // 3. ������� �������� � ������� ��������
    double productEven = 1;
    for (int i = 0; i < N; i += 2) {
        productEven *= arr[i];
    }

    // 4. ���� �������� �� ������ � ������� ��'������
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

    // ��������� ����������
    std::cout << "���� ��'����� ��������: " << sumNegative << std::endl;
    std::cout << "������� �� ��������� � ������������: " << productBetweenMinMax << std::endl;
    std::cout << "������� �������� � ������� ��������: " << productEven << std::endl;
    std::cout << "���� �� ������ � ������� ��'������: " << sumBetweenNegatives << std::endl;
}

int main() {
    int choice;
    do {
        std::cout << "\n����:\n";
        std::cout << "1. ������� ��� ������� ��������\n";
        std::
