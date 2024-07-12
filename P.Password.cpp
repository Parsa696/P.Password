#include <iostream>
#include <string>

using namespace std;

double evaluatePasswordStrength(const string& password) {
    double score = 0;

    if (password.length() >= 6) {
        score += 20; // امتیاز برای حداقل طول 6
        if (password.length() > 6) {
            score += 20; // امتیاز برای طول بیش از 6
        }

        bool hasDigit = false, hasSpecialChar = false;
        bool hasUpperCase = false, hasLowerCase = false;

        for (char c : password) {
            if (isdigit(c)) hasDigit = true;
            else if (ispunct(c)) hasSpecialChar = true;
            else if (isupper(c)) hasUpperCase = true;
            else if (islower(c)) hasLowerCase = true;
        }

        if (hasDigit) score += 20; // امتیاز برای داشتن عدد
        if (hasSpecialChar) score += 20; // امتیاز برای داشتن حروف خاص
        if (hasUpperCase) score += 20; // امتیاز برای داشتن حروف بزرگ
        if (hasLowerCase) score += 20; // امتیاز برای داشتن حروف کوچک
    }

    return score;
}

int main() {
    string password;

    cout << "لطفاً رمز عبور خود را وارد کنید: ";
    cin >> password;

    double strength = evaluatePasswordStrength(password);

    cout << "میزان سختی رمز عبور: " << strength << "%" << endl;

    return 0;
}
