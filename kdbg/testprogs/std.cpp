#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>

template<typename T>
struct V : std::vector<T>
{
	V(const T& v) : std::vector<T>(10, v) {}
	void anotherone(const T& v)
	{
		push_back(v);
	}
};

void test_vector(std::vector<std::string>& v)
{
	v.push_back("xyz");
};

void test_sstream(std::basic_ostringstream<char>& str)
{
	str << "Example:\n ";
}

int main()
{
	std::string s = "abc";
	V<std::string> v(s);

	test_vector(v);
	v.anotherone("ABC");

	std::ostringstream dump;
	test_sstream(dump);
	std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(dump, "\n "));
	std::cout << dump.str() << std::endl;
}
