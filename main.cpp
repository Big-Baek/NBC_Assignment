#include <iostream>
#include<string>
#include<algorithm>

using namespace std;


int* New_arr(int n) {
	int m; //입력받을 변수

	int* arr = new int[n]; //동적할당

	for (int i = 0; i < n; i++) { //배열에 데이터 입력
		cin >> m;
		arr[i] = m;
	}
	return arr; //입력된 배열 리턴
}

void up_Sort(int n, int* arr) {//오름차순 정렬

	for (int i = 0; i < n - 1; i++) { //각 인덱스 선택, sizeof 함수 쓰면 개판남
		for (int j = 0; j < n - 1 - i; j++) {//선택된 인덱스를 다음 인덱스와 비교
			if (arr[j] > arr[j + 1]) {//전자가 더 작으면 자리 변경
				int imsi = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = imsi;
			}
		}
	}

	for (int i = 0; i < n; i++) {//배열값 차례대로 출력
		cout << arr[i] << " ";
	}
	cout << endl;
}

void down_Sort(int n, int* arr) {//내림차순 정렬
	for (int i = 0; i < n - 1; i++) { 
		for (int j = 0; j < n - 1 - i; j++) {//선택된 인덱스를 다음 인덱스와 비교
			if (arr[j] < arr[j + 1]) {//전자가 더 크면 자리 변경
				int imsi = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = imsi;
			}
		}
	}
	for (int i = 0; i < n; i++) {//배열값 차례대로 출력

		cout << arr[i] << " ";
	}
	cout << endl;
}

int sum(int n, int* arr) {
	int Sum = 0;
	for (int i = 0; i < n; i++) {
		Sum += arr[i];
	}
	return Sum;
}

double avr(int n, int* arr) {

	double Avr = sum(n, arr) / n;

	return Avr;
}

int main() {

	int n; //입력받을 변수
	int order = 10; //의미 없는 수
	cout << "몇개의 수를 입력할지 입력해주세요" << endl;
	cin >> n;

	int* arr = New_arr(n); //동적할당 함수

	while (order != 0) { //0을 누를시 종료
		cout << "1번은 오름차순, 2번은 내림차순, 3번은 총합, 4번은 평균, 종료는 0번 " << endl;
		cin >> order; //번호입력으로 명령
		switch (order) {
		case 1: up_Sort(n, arr); //오름차순 정렬
			break;
		case 2: down_Sort(n, arr);//내림차순 정렬
			break;
		case 3: cout << "총합은:" << " " << sum(n, arr) << endl; //총합 출력
			break;
		case 4: cout << "평균은:" << " " << avr(n, arr) << endl; //평균 출력
			break;
			cout << "잘못된 입력입니다 다시 입력하세요" << endl;
		}
	}

	delete arr;
	return 0;
}
