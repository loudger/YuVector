#include <iostream>
#include <ctime>
#include <clocale>

#include "YuVector.h"

using namespace std;

void menu();
void printMenuHeader();

int main() {
	srand(time(NULL));
	setlocale(0, "RUS");
	menu();
	/*cout << "==== VECTOR ====" << endl;

	YuVector vVec1(rand() % 11, rand() % 11, rand() % 11);
	YuVector vVec2(rand() % 11, rand() % 11, rand() % 11);
	YuVector vVec3 = (vVec1 + vVec2);
	YuVector vVec4 = (vVec1 - vVec2);
	double vV1V2 = (vVec1 * vVec2);

	vVec1.show();
	vVec2.show();
	vVec3.show();
	vVec4.show();
	cout << "vVec1 * vVec2 = " << vV1V2 << endl;

	cout << endl << "==== LIST ====" << endl;

	YuVectorList vList;

	for (size_t i = 0; i < 3; i++) {
		vList.add(new YuVector(rand() % 11, rand() % 11, rand() % 11));
	}

	for (size_t i = 0; i < vList.getLength(); i++) {
		vList[i]->getVector()->show();
		//vList.operator[i]->getVector()->show();
	}*/

	//system("pause");
	return 0;
}

void printMenuHeader() {
	system("cls");
	cout << "===============================================================================" << endl;
	cout << "[ 1 ] Создать список" << endl;
	cout << "[ 2 ] Просмотреть список" << endl;
	cout << "[ 3 ] Добавить вектор в список" << endl;
	cout << "[ 4 ] Создать вектор" << endl;
	cout << "[ 5 ] Просмотреть вектор" << endl;
	cout << "[ 6 ] Изменить вектор" << endl;
	cout << "[ 7 ] Сложить вектора" << endl;
	cout << "[ 8 ] Вычесть вектора" << endl;
	cout << "[ 9 ] Перемножить вектора" << endl;
	cout << endl;
	cout << "[ 0 ] Выход" << endl;
	cout << "[ 99] Очистить экран" << endl;
	cout << "===============================================================================" << endl;
}

void menu() {
	YuVectorList* vList = NULL;
	bool vRepeat = true;
	int vOperationNumber;
	printMenuHeader();
	while (vRepeat) {
		cout << ">> ";
		cin >> vOperationNumber;
		switch (vOperationNumber) {
		//==============================================================================
		case 0:
			vRepeat = false;
			break;
		//==============================================================================
		case 1:
			if (vList == NULL) {
				vList = new YuVectorList;
				cout << "Список создан [0x" << vList << "]" << endl;
			}
			else {
				char vTmpFlag = false;
				cout << "Удалить старый список и создать новый? [y/n]" << endl;
				cout << ">> ";
				cin >> vTmpFlag;
				if (vTmpFlag == 'y') {
					//vList->~YuVectorList();
					vList = new YuVectorList();
					cout << "Список пересоздан [0x" << vList << "]" << endl;
				}
				else if (vTmpFlag == 'n') {
					cout << "Список не пересоздан [0x" << vList << "]" << endl;
				}
				else {
					cout << "Некорректный ответ, возврат в главное меню" << endl;
				}
			}
			break;
		//==============================================================================
		case 2:
			if (vList != NULL) {
				vList->show();
			}
			else {
				cout << "Список не создан" << endl;
			}
			break;
		//==============================================================================
		case 3:
			if (vList != NULL) {
				int vTmpNumber;
				cout << "[ 1 ] Добавить в конец списка" << endl;
				cout << "[ 2 ] Добавить в i-ую позицию списка" << endl;
				cout << "[ 0 ] Выход" << endl;
				cout << ">> ";
				cin >> vTmpNumber;
				if (vTmpNumber == 0) {
					;
				}
				else if (vTmpNumber == 1) {
					vList->add(new YuVector(true));
				}
				else if (vTmpNumber == 2) {
					size_t vIndex;
					cout << "Введите номер позиции от 0 до " << vList->getLength() << endl;
					cout << ">> ";
					cin >> vIndex;
					if ((vIndex >= 0) && (vIndex <= vList->getLength())) {
						vList->add(new YuVector(true), vIndex);
					}
					else {
						cout << "Выход за границы диапазона, возврат в главное меню" << endl;
					}
				}
				else {
					cout << "Некорректный выбор, возврат в главное меню" << endl;
				}
			}
			else {
				cout << "Список не создан" << endl;
			}
			break;
		//==============================================================================
		case 4:
			int vTmp;
			YuVector* vVec;
			vVec = new YuVector(true);
			cout << "[ 1 ] Сохранить вектор в конец списка" << endl;
			cout << "[ 2 ] Просмотреть вектор и удалить" << endl;
			cout << ">> ";
			cin >> vTmp;
			if (vTmp == 1) {
				if (vList != NULL) {
					vList->add(vVec);
				}
				else {
					cout << "Список не создан" << endl;
					vVec->~YuVector();
				}
			}
			else if (vTmp == 2) {
				vVec->show();
				vVec->~YuVector();
			}
			else {
				cout << "Некорректный выбор, возврат в главное меню" << endl;
				vVec->~YuVector();
			}
			break;
		//==============================================================================
		case 5:
			if (vList != NULL) {
				if (vList->getLength() > 0) {
					size_t vIndex;
					cout << "Введите номер позиции от 0 до " << vList->getLength() - 1 << endl;
					cout << ">> ";
					cin >> vIndex;
					if ((vIndex >= 0) && (vIndex <= (vList->getLength() - 1))) {
						(*vList)[vIndex]->getVector()->show();
					}
					else {
						cout << "Выход за границы диапазона, возврат в главное меню" << endl;
					}
				}
				else {
					cout << "Список пуст" << endl;
				}
			}
			else {
				cout << "Список не создан" << endl;
			}
			break;
		//==============================================================================
		case 6:
			if (vList != NULL) {
				if (vList->getLength() > 0) {
					size_t vIndex;
					cout << "Введите номер позиции от 0 до " << vList->getLength() - 1 << endl;
					cout << ">> ";
					cin >> vIndex;
					if ((vIndex >= 0) && (vIndex <= (vList->getLength() - 1))) {
						double vE1, vE2, vE3;
						cout << "[0x" << (*vList)[vIndex]->getVector() << "]" << endl;
						cout << "Введите новую координату e1: ";
						cin >> vE1;
						(*vList)[vIndex]->getVector()->setE1(vE1);
						cout << "Введите новую координату e2: ";
						cin >> vE2;
						(*vList)[vIndex]->getVector()->setE2(vE2);
						cout << "Введите новую координату e3: ";
						cin >> vE3;
						(*vList)[vIndex]->getVector()->setE3(vE3);
					}
					else {
						cout << "Выход за границы диапазона, возврат в главное меню" << endl;
					}
				}
				else {
					cout << "Список пуст" << endl;
				}
			}
			else {
				cout << "Список не создан" << endl;
			}
			break;
		//==============================================================================
		case 7:
			//cout << "Введите номер позиции от 0 до " << endl;
			break;
		//==============================================================================
		case 99:
			printMenuHeader();
			break;
		//==============================================================================
		default:
			break;
		}
		cout << endl;
	}
}