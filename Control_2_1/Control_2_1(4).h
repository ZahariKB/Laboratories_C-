#pragma once
#include "Metodi_maina.h"

class Filming : public Actor {
protected:
    const int max_years_filming;
    int current_years_filming;
    int* roles_per_year;

public:

    Filming() = delete;

    Filming(int);

    Filming& operator =(const Filming&);

    Filming(const Filming&& other) noexcept;

    Filming& operator =(Filming&& other) noexcept;

    friend ostream& operator<<(ostream&, const Filming&);

    void set_current_years_filming(int);

    void set_roles_per_year(int, int);

    int* get_roles_per_year();

    int get_current_years_filming();

    int get_max_years_filming();

    ~Filming();
};

