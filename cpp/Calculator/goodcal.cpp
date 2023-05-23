#include <iostream>
using namespace std;

class Calculator
{
protected:
    int a, b;

public:
    virtual int add(int a, int b) = 0; // 두 정수의 합 리턴
    virtual int subtract(int a, int b) = 0; // 두 정수의 뺄셈 리턴
    virtual double average(int a[], int size) = 0; // 두 정수의 평균 리턴

    void input()
    {
        cout << "정수 2 개를 입력하세요>> ";
        cin >> a >> b;
    }

    void run()
    {
        input();
        cout << "계산된 값은 " << add(a, b) << endl;
    }
};

class GoodCalc : public Calculator
{
public:
    int add(int a, int b) override { return a + b; }
    int subtract(int a, int b) override { return a - b; }
    double average(int a[], int size) override
    {
        double sum = 0;
        for (int i = 0; i < size; i++)
            sum += a[i];
        return sum / size;
    }
};

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    Calculator *p = new GoodCalc();

    cout << p->add(2, 3) << endl;
    cout << p->subtract(2, 3) << endl;
    cout << p->average(a, 5) << endl;

    delete p;

    return 0;
}
