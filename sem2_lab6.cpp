// Course: 1, Semester: 2, Group: MKN-116
// Lab: #6, Variant: 1
// Student: Timofeev Denis

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

template <typename T>
typename std::vector<T>::iterator FindRoughlyAverage(std::vector<T>& v)
{
	auto tmpV = v;
	double average = std::accumulate(tmpV.begin(), tmpV.end(), 0.0) / tmpV.size();

	auto middle = std::partition(tmpV.begin(), tmpV.end(), [average](const auto& a) {return a < average; });
	auto maxless = std::max_element(tmpV.begin(), middle);
	auto minover = std::min_element(middle, tmpV.end());

	//DEBUG info
	std::cout << std::fixed << " average: " << average << ", max (less avg): " << *maxless << ", min (over avg): " << *minover << std::endl;

	return std::abs(average - *maxless) < std::abs(average - *minover) ? std::find(v.begin(), v.end(), *maxless) : std::find(v.begin(), v.end(), *minover);
}

int main()
{
	//test case 1. Vector of int values
	std::cout << "Case 1 (int)" << std::endl;
	std::vector<int> vectorInt = { 3, 14, 15, 92, 65, 53, 58, 97, 93, 23 };
	std::vector<int>::iterator itInt = FindRoughlyAverage(vectorInt);
	std::cout << std::fixed << " roughly average: " << *itInt << " at index " << std::distance(vectorInt.begin(), itInt) << std::endl;

	//test case 2. Vector of float values
	std::cout << "Case 2 (float)" << std::endl;
	std::vector<float> vectorFloat = { 0.5772156649f, 0.153286060f, 6.512090082f, 4.024310421f, 5.933593992f, 3.598805767f };
	std::vector<float>::iterator itFloat = FindRoughlyAverage(vectorFloat);
	std::cout << std::fixed << " roughly average: " << *itFloat << " at index " << std::distance(vectorFloat.begin(), itFloat) << std::endl;

	//test case 3. Vector of double values
	std::cout << "Case 3 (double)" << std::endl;
	std::vector<double> vectorDouble = { 16180339887.4989484820, 4586834365.6381177203, 0917980576.2862135448, 6227052604.6281890244, 9707207204.1893911374, 8475408807.5386891752 };
	std::vector<double>::iterator itDouble = FindRoughlyAverage(vectorDouble);
	std::cout << std::fixed << " roughly average: " << *itDouble << " at index " << std::distance(vectorDouble.begin(), itDouble) << std::endl;
}
