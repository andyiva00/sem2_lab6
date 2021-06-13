// Course: 1, Semester: 2, Group: MKN-116
// Lab: #6, Variant: 1
// Student: Timofeev Denis

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>


template <typename T>
typename std::vector<T>::iterator FindRoughlyAverage(std::vector<T>& vector)
{
    double average = std::accumulate(vector.begin(), vector.end(), 0.0) / vector.size();
    
    auto maxless = std::max_element(vector.begin(), vector.end(), [&average](T a, T b) {return (a < b && (double)b < average); });
    auto minover = std::min_element(vector.begin(), vector.end(), [&average](T a, T b) {return (a > b && (double)b < average); });

    std::cout << "average: " << average;

    return abs(average - (double)*maxless) < abs(average - (double)*minover)
        ? maxless : minover;
}

int main()
{
    //test case "int"
    std::vector<int> vectorInt = { 0, 4, 23, 54, 64, 12 };
    std::vector<int>::iterator itInt = FindRoughlyAverage(vectorInt);
    std::cout << "Case 1. Roughly average: " << *itInt << " at index " << std::distance(vectorInt.begin(), itInt) << std::endl;

    //test case "float"
    std::vector<float> vectorFloat = { 9.1f, 3.14f, 0.001f, 3.01f, 1.25f, 5.25f };
    std::vector<float>::iterator itFloat = FindRoughlyAverage(vectorFloat);
    std::cout << "Case 2. Roughly average: " << *itFloat << " at index " << std::distance(vectorFloat.begin(), itFloat) << std::endl;

    //test case "double"
    std::vector<double> vectorDouble = { 151.16416561f , 11.467161f, 97.1054167f, 70.99999f, 115.941670f, 11.3616651f, 41.61238f };
    std::vector<double>::iterator itDouble = FindRoughlyAverage(vectorDouble);
    std::cout << "Case 3. Roughly average: " << *itDouble << " at index " << std::distance(vectorDouble.begin(), itDouble) << std::endl;

}
