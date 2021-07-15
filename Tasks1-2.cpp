#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

#ifndef ARRAYINT_H
#define ARRAYINT_H

using namespace std;

class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length) : m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }
    int getLength() { return m_length; }
    
    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    
    void resize(int newLength)
    {
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        int* data = new int[newLength];

        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;


            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        delete[] m_data;

        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);

        int* data = new int[m_length + 1];

        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        data[index] = value;

        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value) { insertBefore(value, m_length); }

    //====Exercise 1==========================================================================================

    void pop_back() {
        m_data[m_length - 1] = 0;
        m_length -= 1;
    }

    void pop_front() {
        for (size_t i = 1; i < m_length; i++)
        {
            m_data[i - 1] = m_data[i];
            m_data[i] = 0;
        }
        m_length -= 1;
    }

    void sort() {
        for (size_t i = 0; i < m_length; i++)
        {
            for (size_t j = 0; j < m_length; j++)
            {
                if (m_data[i] < m_data[j]) {
                    int temp = m_data[i];
                    m_data[i] = m_data[j];
                    m_data[j] = temp;
                }
            }
        }
    }

    void print() const {
        cout << " (";
        for (size_t i = 0; i < m_length; i++)
        {
            cout << m_data[i] << "  ";
        }
        cout << ")" << endl;
    }

    //=======================================================================================================
};

#endif

//====Exercise 2=============================================================================================

void print(vector<int>& a) {
    cout << " The length is: " << a.size() << '\n';
    cout << " (";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    
    cout << ")" << endl;
}
void various(vector<int>& a) {
    int var = 0;
    sort(a.begin(), a.end());
    for (size_t i = 0; i < a.size() - 1;i++)
    { 
        if (a[i] == a[i + 1]) var += 1;
    }
    int rez = a.size() - var;
    cout << " Number of different elements: " << rez << endl;
}

//===========================================================================================================

int main()
{
    cout << " Ex 1" << endl;
    ArrayInt arr(10);
    arr[0] = 5; 
    arr[1] = 6;
    arr[2] = 9;
    arr[3] = 1;
    arr[4] = 3;
    arr[5] = 0;
    arr[6] = 16;
    arr[7] = 11;
    arr[8] = 7;
    arr[9] = 5;    
    arr.print();
    arr.sort();
    arr.print();
    cout << " " << arr.getLength() << endl;
    arr.pop_back();
    arr.print();
    cout << " " << arr.getLength() << endl;
    arr.pop_front();    
    arr.print();
    cout << " " << arr.getLength() << endl << endl;

    //=======================================================================================================

    cout << " Ex 2" << endl;
    vector<int> myVector{ 1,9,8,4,6,1,7,2,9,7,4,4,3,3,7,1,0 };
    print(myVector);
    various(myVector);

    return 0;
}