#include "Metodi_dochki.h"
#include<iostream>

Filming::Filming(int roles_count) : max_years_filming(50), current_years_filming(5), Actor("Name", komik) {
    roles_per_year = new int[roles_count];
    amount_actors++;
}

Filming& Filming::operator =(const Filming& f) {
    if (this != &f) {
        this->current_years_filming = f.current_years_filming;
        delete[] roles_per_year;
        roles_per_year = new int[max_years_filming];
        for (int i = 0; i < max_years_filming; ++i) {
            this->roles_per_year[i] = f.roles_per_year[i];
        }
    }
    return *this;
}

Filming::Filming(const Filming&& other) noexcept : max_years_filming(other.max_years_filming), current_years_filming(other.current_years_filming), Actor("fds", komik) {
    this->current_years_filming = other.current_years_filming;
}

Filming& Filming::operator=(Filming&& other) noexcept {
    if (this != &other) {
        this->current_years_filming = other.current_years_filming;
        delete[] roles_per_year;
        roles_per_year = new int[max_years_filming];
        for (int i = 0; i < max_years_filming; ++i) {
            roles_per_year[i] = other.roles_per_year[i];
        }
    }
    return *this;
}

ostream& operator<<(ostream& os, const Filming& filming) {
    os << "Текущее количество лет в съёмках: " << filming.current_years_filming << ", Количество ролей в год: ";
    for (int i = 0; i < filming.max_years_filming; ++i) {
        os << filming.roles_per_year[i] << " ";
    }
    cout << endl;
    return os;
}

void Filming::set_current_years_filming(int years) {
    if (years > max_years_filming) {
        throw exception("Превышено максимальное количество лет съемок");
    }
    current_years_filming = years;
}

void Filming::set_roles_per_year(int year, int roles_count) {
    roles_per_year[year] = roles_count;
}

int* Filming::get_roles_per_year() {
    return roles_per_year;
}

int Filming::get_current_years_filming() {
    return current_years_filming;
}

Filming::~Filming() {
    delete[] roles_per_year;
    amount_actors--;
}