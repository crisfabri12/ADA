#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

template<class N >
vector<N> merge(std::vector<N> A, std::vector<N> B) {
	vector<N> re;
	while (!(A.empty()) && !(B.empty())) {
		if (A[0] < B[0]) {
			re.insert(re.end(), A[0]);
			A.erase(A.begin());
		}
		else {
			re.insert(re.end(), B[0]);
			B.erase(B.begin());
		}
	}
	if (A.empty())
		re.insert(re.end(), B.begin(), B.end());
	else
		re.insert(re.end(), A.begin(), A.end());

	A.clear(); B.clear();
	return re;
}
template<class N >
vector<N> merge_sort(vector<N>& V) {
	int s = V.size();
	if (s <= 1)
		return V;
	std::vector<N> a;
	std::vector<N> b;

	a.insert(a.begin(), V.begin(), V.begin() + (s / 2));
	b.insert(b.begin(), V.begin() + (s / 2), V.end());

	return merge(merge_sort(a), merge_sort(b));
}

int main(int argc, char* argv[]) {
	srand(time(NULL));
	std::vector<int> ss;
	int q;
	for (int w = 10; w <= 100; w += 10) {
		for (int a = 0; a < w; a++) {
			q = rand() % 100;
			ss.push_back(q);
		}
		clock_t start = clock();
		ss = merge_sort<int>(ss);
		clock_t end = clock();

		/*        for(int s=0;s<ss.size();s++)
					std::cout<<ss[s]<<" , ";
				std::cout<<std::endl;
			*/
		cout << std::endl;
		cout << w << " : " << ((double)(end - start) / CLOCKS_PER_SEC);
		ss.clear();
	}
	return 0;
}