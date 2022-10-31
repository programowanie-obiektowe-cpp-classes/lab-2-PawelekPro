// ZADANIA 1 - 7

#include <iostream>
using namespace std;

class Wektor
{
public:
    
	double* vector;
    Wektor(const unsigned int n) 
	{ 
		length = n;
		vector = new double[n]{};
	}
    

	int get_length() { return length; };

	int get_capacity() { return capacity; };


	int switchLength(int newLength) 
	{ 
		if (newLength <= get_length() && newLength <= get_capacity()) 
		{
                length = newLength;
                capacity = newLength;
		}
        else if (newLength <= get_capacity() && newLength > get_length()) 
        {
                length = newLength;
                capacity = newLength;
            for (int i = get_length(); i < newLength; i++) {
                vector[i] = .0;
            }
        }
        else if (newLength > get_capacity()) 
        {   
            capacity = newLength;
            double* newMemoryBlock = new double[newLength]{};
            for (int i = 0; i < newLength; i++) {
                if (i < get_capacity()) {
                    newMemoryBlock[i] = vector[i];
                }
                else {
                    newMemoryBlock[i] = 0;
                }  
            }
        }
        return length, capacity;
	}

	void print()
        {
            for (int i = 0; i < get_length(); i++) {
                std::cout << "Wartosc " << vector[i] << "...\n";
            }
        }
	
	~Wektor() 
	{
		delete[] vector;
	}

private:
    int length;
    int capacity;
};


struct Kokardka
{
    Kokardka(int d) : dlugosc{d} {}

    int dlugosc;
};

struct Prezent
{
    Prezent(int dk) : k{dk} {}

    Kokardka k;
    // Inne pola ...
};

class T
{
    // Konstruktor kopiuj¹cy
    T(const T& t)
    { /* ... */
    }

    // Kopiuj¹cy operator przypisania
    T& operator=(const T& t)
    { /* ... */
        return *this;
    }

    // Destruktor
    ~T()
    { /* ... */
    }
};

struct Liczba
{
    Liczba(int w) : wartosc{w} {}
    Liczba(const Liczba& l) : wartosc{l.wartosc} {}
    
    void print() { std::cout << "konstrukcja: " << wartosc << "...\n"; }

    int wartosc;
};


int main()
{

    Wektor vec = Wektor(100);
    std::cout << "ilosc elementow: " << vec.get_length() << "...\n";
    vec.switchLength(120);


    for (int i = 0; i < vec.get_length(); i++) {
        std::cout << "Wartosc " << vec.vector[i] << "...\n";
    }

	std::cout << "ilosc elementow: " << vec.get_length() << "...\n";


    Liczba a{1};
        a.print();
    Liczba b{a};  // W celu konstrukcji b wo³amy konstruktor kopiuj¹cy z argumentem 'a'
        b.print();
    Liczba c = a; // Tutaj tak¿e wo³amy konstruktor kopiuj¹cy, vide lab. 1

    return 0;
}