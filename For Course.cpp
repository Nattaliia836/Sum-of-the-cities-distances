#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sum(int s                  // Значення суму одних із к елементів
    , const vector<int>& v      // вектор з усіма данними
    , int i                     // номер елементу, який треба додати
    , int count                 // чисто елементів які ще треба додати
    , const int& k              // кількість ітерацій
    , vector<int>& result       // вектор з результатом
    , int number                // інтекс попереднього доданого в суму числа
) {
    if (count > 1) {
        count--;
        i++;
        for (int j = number + 1; j <  v.size() - (k - (i - 1)); j++) { 
            sum((s + v[j]), v, i, count, k, result, j);
        }
    }
    else if (count <= 1) {
        for (int j = number + 1; j < v.size(); j++) {  
            result.push_back(s + v[j]);
        }
    }
}

int chooseDistance(int t        // Максимальна сума відстаней
    , int k                     // Кількість міст для відвідування
    , vector<int> ls            // Список відстаней, всі відстані є додатними або нульовими цілими числами
) {

    if (ls.size() < k) { 
        return -1;
    }
    vector<int> result;
    sum(0, ls, 1, k, k, result, -1);

    sort(result.begin(), result.end());
   
    int lastSeeEl = 0;
    for (auto element : result) {
        if (element < t) {
            lastSeeEl = element;
        }
        else if (element == t) {
            return element;
        }
        else if (element > t) {
            if (element == result[0]) return -1;
            return lastSeeEl;
        }
    }

    return -1;
}

void main() {
    cout << chooseDistance(174, 3, { 51, 56, 58, 59, 61 }) << endl; //173
    cout << chooseDistance(163, 3, { 50 }) << endl; // -1
    cout << chooseDistance(163, 1, { 50, 52 }) << endl; // -1
    cout << chooseDistance(163, 3, { 50, 113 }) << endl; // -1
    cout << chooseDistance(163, 3, { 50, 60, 53 }) << endl; // 163
    cout << chooseDistance(163, 3, { 50, 60, 52, 54 })<< endl; // 162
}

