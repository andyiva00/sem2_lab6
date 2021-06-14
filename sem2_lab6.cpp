// Course: 1, Semester: 2, Group: MKN-116
// Lab: #6, Variant: 1
// Student: Timofeev Denis

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <forward_list>

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

template <typename T>
typename std::vector<T> UniqueElements(std::forward_list<T>& l)
{
	std::vector<T> v{ std::begin(l), std::end(l) };
	std::sort(v.begin(), v.end());
	auto last = std::unique(v.begin(), v.end());
	v.erase(last, v.end());

	return v;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	if (!v.empty())
	{
		std::cout << "{ ";
		std::copy(v.begin(), v.end(), std::ostream_iterator<T>(os, " "));
		std::cout << "}";
	}
	
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::forward_list<T>& l)
{
	if (!l.empty())
	{
		std::cout << "( ";
		std::copy(l.begin(), l.end(), std::ostream_iterator<T>(os, " "));
		std::cout << ")";
	}

	return os;
}

int main()
{
	//test case 1.1. Vector of int values
	std::cout << "Case 1.1 (int)" << std::endl;
	std::vector<int> vectorInt = { 3, 14, 15, 92, 65, 53, 58, 97, 93, 23 };
	std::cout << " vector: " << vectorInt << std::endl;
	std::vector<int>::iterator itInt = FindRoughlyAverage(vectorInt);
	std::cout << std::fixed << " roughly average: " << *itInt << " at index " << std::distance(vectorInt.begin(), itInt) << std::endl;

	//test case 1.2. Vector of float values
	std::cout << "Case 1.2 (float)" << std::endl;
	std::vector<float> vectorFloat = { 0.5772156649f, 0.153286060f, 6.512090082f, 4.024310421f, 5.933593992f, 3.598805767f };
	std::cout << " vector: " << vectorFloat << std::endl;
	std::vector<float>::iterator itFloat = FindRoughlyAverage(vectorFloat);
	std::cout << std::fixed << " roughly average: " << *itFloat << " at index " << std::distance(vectorFloat.begin(), itFloat) << std::endl;

	//test case 1.3. Vector of double values
	std::cout << "Case 1.3 (double)" << std::endl;
	std::vector<double> vectorDouble = { 16180339887.4989484820, 4586834365.6381177203, 0917980576.2862135448, 6227052604.6281890244, 9707207204.1893911374, 8475408807.5386891752 };
	std::cout << " vector: " << vectorDouble << std::endl;
	std::vector<double>::iterator itDouble = FindRoughlyAverage(vectorDouble);
	std::cout << std::fixed << " roughly average: " << *itDouble << " at index " << std::distance(vectorDouble.begin(), itDouble) << std::endl;

	//test case 2.1. Forward list of int values
	std::cout << "Case 2.1 (int)" << std::endl;
	std::forward_list<int> listInt = { 3,1,4,1,5,9,2,6,5,5,3,5,8,9,7,9,3,2,3 };
	std::cout << " source forward list: " << listInt << std::endl;
	std::vector<int> vectorUniqueInt = UniqueElements(listInt);
	std::cout << " vector of unique elements: " << vectorUniqueInt << std::endl;

	//test case 2.2. Forward list of int values
	std::cout << "Case 2.1 (float)" << std::endl;
	std::forward_list<float> listFloat = { 5.1f, 3.5f, 2.2f, 5.1f, 3.0f, 7.8f, 3.5f, 5.1f };
	std::cout << std::fixed << " source forward list: " << listFloat << std::endl;
	std::vector<float> vectorUniqueFloat = UniqueElements(listFloat);
	std::cout << std::fixed << " vector of unique elements: " << vectorUniqueFloat << std::endl;

	//test case 2.3. Forward list of string values
	std::cout << "Case 2.1 (string)" << std::endl;
	std::forward_list<std::string> listString = { "lorem", "ipsum", "dolor", "sit", "amet", "consectetur", "adipiscing", "elit", "aenean", "dapibus", "leo", "a", "velit", "gravida", "imperdiet", "et", "et", "massa", "praesent", "a", "enim", "elementum", "convallis", "diam", "ut", "suscipit", "nulla"};
	std::cout << std::fixed << " source forward list: " << listString << std::endl;
	std::vector<std::string> vectorUniqueString = UniqueElements(listString);
	std::cout << std::fixed << " vector of unique elements: " << vectorUniqueString << std::endl;

}
