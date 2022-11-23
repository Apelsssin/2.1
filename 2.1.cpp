#include <iostream>
#include <fstream>
#include <string>
void create_arr(std::ifstream& file, int* a, int size) {
	std::string s;
	for (int i = 0; i < size; i++) {
		file >> s;
		a[i] = stoi(s);
	}
}
void print(std::ofstream& file, int* a, int size) {
	file << size << std::endl;
	std::string s;
	for (int i = 0; i < size; i++) {
		file << a[i] << "\t";
	}
	file << std::endl;
}
int main() {
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");
	std::string i;
	fin >> i;
	const int N = stoi(i);
	int* arr1 = new int [N];
	create_arr(fin, &arr1[0], N);
	fin >> i;
	const int M = stoi(i);
	int* arr2 = new int [M];
	create_arr(fin, &arr2[0], M);
	for (int k = M - 1; k > 0; k--) {
		int z = arr2[k];
		arr2[k] = arr2[k - 1];
		arr2[k - 1] = z;
	}
	for (int k = 0; k < N - 1; k++) {
		int z = arr1[k];
		arr1[k] = arr1[k + 1];
		arr1[k + 1] = z;
	}
	print(fout, &arr2[0], M);
	print(fout, &arr1[0], N);
	fin.close();
	fout.close();
	delete[] arr1;
	delete[] arr2;
}