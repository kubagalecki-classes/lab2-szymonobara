#include <iostream>

struct Wektor
{
    Wektor(int n) : dlugosc{n}
    {
        wektor = new double[n];
        for (int i = 0; i < n; i++)
            wektor[i] = 2;
    }

    Wektor(const Wektor& w) : pojemnosc(w.dlugosc)
    {
        double* wektor_copy = new double[w.dlugosc];
        for (int i = 0; i < w.dlugosc; i++)
            wektor_copy[i] = 2;
    }

    Wektor(Wektor&& wek1) : dlugosc(std::move(wek1.dlugosc))
    {
        double* wektor_move = new double[wek1.dlugosc];
        for (int i = 0; i < wek1.dlugosc; i++)
            wektor_move[i] = std::move(wek1[i]);
    }
    Wektor& operator=(Wektor&& wek1)
    {

        for (int i = 0; i < dlugosc; i++)
            wektor[i] = std::move(wek1[i]);
        return *this;
    }

    Wektor& operator=(Wektor& wek1)
    {
        if (dlugosc != wek1.dlugosc) {
            std::cout << "Nie mozna przypiac wektorow o roznych dlyugosciach";
        }
        else {
            for (int i = 0; i < dlugosc; i++)
                wektor[i] = wek1[i];
        }
        return *this;
    }

    ~Wektor() { delete wektor; }

    void print(int n)
    {
        for (int i = 0; i < n; i++)
            std::cout << "wektor(" << i << ")=" << wektor[i] << "\n";
    }

    void zmienDlugosc(int new_n)
    {
        if (new_n < pojemnosc) {
            for (int i = new_n; i < pojemnosc; i++) {
                wektor[i] = 0;
            }
        }
        if (new_n > dlugosc) {
            x = new double[dlugosc];
            for (int i = 0; i < dlugosc; i++)
                x[i] = wektor[i];
            delete wektor;
            wektor = new double[new_n];
            for (int i = 0; i < dlugosc; i++)
                wektor[i] = x[i];
            delete x;
            for (int i = dlugosc; i < new_n; i++)
                wektor[i] = 0;
            dlugosc = new_n;
        }
    }

    int getDlugosc() { return dlugosc; }

    int getPojemnosc() { return pojemnosc; }

    double& operator[](int index)
    {
        if (index > dlugosc) {
            zmienDlugosc(index);
        }
        return wektor[index];
    }

    double* x;

private:
    double* wektor;

private:
    int dlugosc;
    int pojemnosc;
};

int main()
{
    Wektor a{8};
    a.zmienDlugosc(10);
    Wektor c{10};

    Wektor b(std::move(a));
    b.print(10);
}
