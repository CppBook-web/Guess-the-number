#include <iostream>
#include <string>
#include <cstdlib> // Для генератора случайных чисел
#include <ctime>
using namespace std;

void drawLine(int n, char symbol);
void rules();

int main() {
    setlocale(LC_ALL, "rus");

    string player_name;
    int amount = 1000;
    int betting_amount = 0;
    int guess = 0;
    int dice = 0;
    char choice = 0;

    srand((unsigned)time(NULL));; // генератор случайного числа

    drawLine(60, '_');
    cout << "\n\n\t\t\tИГРА \"КАЗИНО\"\n\n";
    drawLine(60, '_');

    cout << "\n\nВведите Ваше имя: ";

    getline(cin, player_name);
    if (player_name.empty()) {
        player_name = "Tony Stark";
    }

    do {
        system("cls"); //очистка вывода
        rules();
        cout << "\n\nВаш игровой баланс: $" << amount << "\n";

        // Ставка игрока
        do {
            cout << player_name << ", введите Вашу ставку: $";
            cin >> betting_amount;
            if (cin.fail()) { //проверка на ввод числа
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "\nОшибка, проверьте вводите ли Вы верное число.\n";
                continue;
            }
            else if (betting_amount > amount) {
                cout << "Ваша ставка больше доступных средств на счете.\n"
                    << "\nВведите ставку снова.\n";
            }
            else if (betting_amount <= 0) {
                cout << "Минимальная ставка $1.\n"
                    << "\nВведите ставку снова.\n";
            }
        } while (betting_amount > amount || betting_amount <= 0);

        // Ввод числа игрока
        do {
            cout << "Введите число от 1 до 10: ";
            cin >> guess;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "\nОшибка, проверьте вводите ли Вы верное число.\n";
                continue;
            }
            else if (guess <= 0 || guess > 10)
                cout << "Пожалуйста, проверьте вводимое число, "
                << "оно должно быть от 1 до 10.\n"
                << "Введите снова.\n";
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1; // генерация случайного число от 1 до 10

        if (dice == guess) {
            cout << "\n\nВам везет! Ваш выигрыш: $" << betting_amount * 10;
            amount = amount + betting_amount * 10;
        }
        else {
            cout << "Не повезло! Вы потеряли: $" << betting_amount << "\n";
            amount = amount - betting_amount;
        }

        cout << "\nВыигрышное число: " << dice << "\n"
            << "\n" << player_name << ", Ваш баланс: $"
            << amount << "\n";
        if (amount == 0) {
            cout << "У Вас нет денег для игры.";
            break;
        }
        cout << "\n\n-->Играть дальше (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "\n\n\n";
    drawLine(70, '=');
    cout << "\n\nВозвращайтесь снова! Ваш баланс: $"
        << amount << "\n\n";
    drawLine(70, '=');

    return 0;
}

void drawLine(int n, char symbol) {
    for (int i = 0; i < n; i++)
        cout << symbol;
    cout << "\n";
}

void rules() {
    system("cls"); //очистка вывода
    cout << "\n\n";
    drawLine(80, '-');
    cout << "\t\tПРАВИЛА ИГРЫ\n";
    drawLine(80, '-');
    cout << "\n\t* Сделайте ставку и выберите любое число от 1 до 10\n"
        << "\t* Угадаете число, получите в десять раз больше Вашей ставки.\n"
        << "\t* Не угадаете число, потеряете Вашу ставку.\n\n";
    drawLine(80, '-');
}