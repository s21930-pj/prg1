#include <iostream>
#include <random>

void naive_sort(int const N, int an_array[])
{
	for (auto i = 0; i < N; ++i) {
 		auto the_smallest = an_array[i];
		auto index = i;
		for (auto j = i; j < N; ++j) {
			if (an_array[j] <the_smallest) {
		    		the_smallest = an_array[j];
		    		index = j;
			}
		}
	an_array[index] = an_array[i];
	an_array[i] = the_smallest;
	}
}
void random_initialisation(int const N, int an_array[])
{
	std::random_device rd;
	std::uniform_int_distribution<int> generator(0, 100);
	for(auto i = 0; i < N; ++i)
	 {
		an_array[i] = generator(rd);
	}
}
int main()
{
	auto const N = 10;
	int an_array[N];
	random_initialisation(N, an_array);
	naive_sort(N, an_array);
	for (auto i = 0; i < N; ++i) {
		std::cout << an_array[i] << "\n";
	}
	return 0;
}
