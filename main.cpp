#include <iostream>
#include <cmath>


static const double pi = 3.14159265358979323846;


double absolute(double x) {
    if (x >= 0) {
        return x;
    }
    else if (x < 0) {
        x = (-1) * x;
    return x;
    }
}

class Circle {
private:
    double R, r, l, h;
public:
    Circle(double R, double r, double l, double h) {
        this->R = R;
        this->r = r;
        this->l = l;
        this->h = h;
    }

    void Square();
    void Volume();

    ~Circle() {
        std::cout << "запустился деструктор Circle" << std::endl;
    }
};


void Circle::Square() {
    double S = pi * ((R * R) + ((R + r) * l) + (r * r));
    std::cout << "Площадь: " << S << std::endl;
}

void Circle::Volume() {
    double V = ((pi * h) * ((R * R) + (R * r) + (r * r))) / 3;
    std::cout << V << std::endl;
}

class Branch {
private:
    double a, x;
public:
    Branch(double a, double x) {
        this->a = a;
        this->x = x;
    }

    void task2() {
        double res;
        double xabs = absolute(x);
        if (xabs == 0) {
            std::cout << "логарифм не определен" << std::endl;
        }
        else if (xabs < 1) {
            res = a * (log(xabs));
            std::cout << res << std::endl;

        }
        else if(xabs>=1){
            double undersqrt = (a - (x * x));
            if (undersqrt >= 0){
                res = sqrt(undersqrt);
                std::cout << res << std::endl;
            }
            else if (undersqrt < 0) {
                std::cout << "подкоренное выражение меньше 0" << std::endl;
            }
        }
        
    }

    ~Branch() {
        std::cout << "вызвался деструктор класса Branch" << std::endl;
    }
};

void task3(double x,double y,double b) {
    double res;
    double underlog = b - y;
    double undersqrt = b - x;
    if ((underlog < 0)||(undersqrt<0)){
        std::cout << "логарифм не определен, либо корень меньше нуля" << std::endl;
    }
    else if ((underlog > 0) && (undersqrt >= 0)) {
        res = (log(underlog)) * (sqrt(undersqrt));
        std::cout << res << std::endl;
    }
}

void task4(double n) {
    double x, y;
    int count = 1;
    y = std::modf(n, &x);
    for (int i = x; i < x + 11; ++i) {
 
        std::cout <<std::endl<<"номер числа:"<<count<< std::endl<<"число: " << i << "." << y << std::endl << "целая часть: " << x << std::endl << "дробная часть: " << y << std::endl << std::endl;
        count++;
    }
}

void task5() {
    std::cout << "task 5" << std::endl << std::endl;
    double res;
    double x = -4;
    double step = 0.5;

    for (int i = 0; i < 16; ++i) {
        std::cout << "шаг " << i << ": ";
        if ((1 - x) == 0) {
            std::cout << "нельзя делить на 0" << std::endl << std::endl;
       }
        else {
            res = ((x * x) - (2 * x) + 2) / (x - 1);
            std::cout << res << std::endl << std::endl;
        }
        x = x + step;
    }

}


int main() {
    setlocale(LC_ALL, "Russian");
    double R, r, l, h;
    std::cout << "Введите R, r, l,h" << std::endl;
    std::cin >> R >> r >> l >> h;
    
    Circle a(R, r, l, h);
    a.Square();
    a.Volume();

    std::cout << std::endl << std::endl << "2 задание" << std::endl << std::endl << "введите a и x" << std::endl;
    double a2, x2;
    std::cin >> a2 >> x2;

    Branch t2(a2, x2);
    t2.task2();

    std::cout << std::endl << std::endl << "3 задание: " << std::endl << "введите x,y,b" << std::endl;
    double x3, y3, b3;
    std::cin >> x3 >> y3 >> b3;
    task3(x3, y3, b3);

    std::cout << "task 4" << std::endl <<  "введите n: " << std::endl;
    double n;
    std::cin >> n;

    task4(n);
    task5();
}
