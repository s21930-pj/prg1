#include <iostream>
#include <random>
#include <string>

void naive_sort (int const N, int* an_array)
{
	for (auto i = 0; i < N; ++i) {
		int* the_smallest = &an_array[i];
		for (auto j = i; j < N; ++j) {
			if (an_array[j] < *the_smallest) {
					the_smallest = &an_array[j];
			}
		}
		auto tmp = *the_smallest;
		*the_smallest = an_array[i];
		an_array[i] = tmp;
	}
}
void random_initialisation (int const N, int* an_array)
{
	std::random_device rd;
	std::uniform_int_distribution<int> generator(0, 100);
	for (auto i = 0; i <N; ++i) {
		an_array[i] = generator(rd);
	}
}
int main(int argc, char* argv[])
{
	auto const n = std::stoi(argv[1]);
	int* an_array = new int[n];
	random_initialisation(n, an_array);

	naive_sort(n, an_array);

	for (auto i = 0; i < n; ++i) {
		std::cout << an_array[i] << "\n";
	}
	delete[] an_array;

	return 0;
}
