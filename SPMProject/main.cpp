#include<iostream>
#include<fstream>
#include<time.h>
#include<string>
#include<random>
#include"BubbleSort.h"
#include"MergeSort.h"
#include"InsertionSort.h"
#include"QuickSort.h"

using namespace std;

int* generateRandomNumbers(int* randomNum, int data);

random_device rd;
default_random_engine eng{ rd() };


int main()
{

	const long int DATA1 = 10000;
	int dataSets;

	clock_t begin_time;

	cout << "Enter Number of Data sets: ";
	cin >> dataSets;

	int i = 0;
	while (dataSets > i){
		long int data = DATA1 + (i * 10000);
		int* randomNum = new int[data];
			
		cout << "Pass " << i+1 << endl;

		float elapsedTime;
		ofstream outFile;

		// ******************************* INSERTION SORT *******************************//

		randomNum = generateRandomNumbers(randomNum, data);
		begin_time = clock();
		InsertionSort::sort(randomNum,data);
		elapsedTime = ((float)(clock() - begin_time))/1000;

		outFile.open("insertion"+ to_string(i+1) + ".txt");
		outFile << "Time for Pass " << i + 1 << ": " << elapsedTime << endl;
		for (int i = 0; i < data; i++){
			outFile << randomNum[i] << endl;
		}
		outFile.close();
		if (i == 0){
			outFile.open("insertionsorttime.txt", std::ofstream::out | std::ofstream::trunc);
			outFile.close();
		}
		outFile.open("insertionsorttime.txt",ios::app);
		outFile << data << " " << elapsedTime << endl;
		outFile.close();
		cout << "Insertion Sort Time " << elapsedTime << endl;

		// ******************************* BUBBLE SORT *******************************//

		randomNum = generateRandomNumbers(randomNum, data);
		begin_time = clock();
		BubbleSort::sort(randomNum, data);
		elapsedTime = ((float)(clock() - begin_time)) / 1000;

		outFile.open("bubble"+ to_string(i+1) + ".txt");
		outFile << "Time for Pass " << i + 1 << ": " << elapsedTime << endl;
		for (int i = 0; i < data; i++){
			outFile << randomNum[i] << endl;
		}
		outFile.close();
		if (i == 0){
			outFile.open("bubblesorttime.txt", std::ofstream::out | std::ofstream::trunc);
			outFile.close();
		}
		outFile.open("bubblesorttime.txt",ios::app);
		outFile << data << " " << elapsedTime << endl;
		outFile.close();
		cout << "Bubble Sort Time " << elapsedTime << endl;

		// ******************************* MERGE SORT *******************************//

		randomNum = generateRandomNumbers(randomNum, data);
		begin_time = clock();
		MergeSort::sort(randomNum, 0, data - 1);
		elapsedTime = ((float)(clock() - begin_time))/1000;

		outFile.open("merge" + to_string(i+1) + ".txt");
		outFile << "Time for Pass " << i + 1 << ": " << elapsedTime << endl;
		for (int i = 0; i < data; i++){
			outFile << randomNum[i] << endl;
		}
		outFile.close();
		if (i == 0){
			outFile.open("mergesorttime.txt", std::ofstream::out | std::ofstream::trunc);
			outFile.close();
		}

		outFile.open("mergesorttime.txt",ios::app);
		outFile << data << " " << elapsedTime << endl;
		outFile.close();
		cout << "Merge Sort Time " << elapsedTime << endl;

		// ******************************* QUICK SORT *******************************//

		randomNum = generateRandomNumbers(randomNum, data);
		begin_time = clock();
		QuickSort::sort(randomNum, 0, data-1);
		elapsedTime = ((float)(clock() - begin_time))/1000;

		outFile.open("quick" + to_string(i + 1) + ".txt");
		outFile << "Time for Pass " << i + 1 << ": " << elapsedTime << endl;
		for (int i = 0; i < data; i++){
			outFile << randomNum[i] << endl;
		}
		outFile.close();
		if (i == 0){
			outFile.open("quicksorttime.txt", ios::trunc);
			outFile.close();
		}
		outFile.open("quicksorttime.txt", ios::app);
		outFile << data << " " << elapsedTime << endl;
		outFile.close();
		cout << "Quick Sort Time " << elapsedTime << endl << endl;

		i++;
		delete randomNum;
	}

	system("pause");

}

int* generateRandomNumbers(int* randomNum, int data){
	uniform_int_distribution<> dist(0, data);

	srand(time(NULL));

	for (int i = 0; i < data; i++){
		randomNum[i] = dist(eng);
	}

	return randomNum;
}