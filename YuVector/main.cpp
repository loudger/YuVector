#include <iostream>
//#include <cstring>
#include <string>
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
	std::cout << "===============================================================================" << endl;
	std::cout << "[ 1 ] Создать список" << endl;
	std::cout << "[ 2 ] Просмотреть список" << endl;
	std::cout << "[ 3 ] Создать вектор" << endl;
	std::cout << "[ 4 ] Просмотреть вектор" << endl;
	std::cout << "[ 5 ] Изменить вектор" << endl;
	std::cout << "[ 6 ] Удалить вектор" << endl;
	std::cout << "[ 7 ] Сложить вектора" << endl;
	std::cout << "[ 8 ] Вычесть вектора" << endl;
	std::cout << "[ 9 ] Перемножить вектора" << endl;
	std::cout << endl;
	std::cout << "[ 0 ] Выход" << endl;
	std::cout << "[ 99] Очистить экран" << endl;
	std::cout << endl;
	std::cout << "[ 11] Длина списка" << endl;
	std::cout << "===============================================================================" << endl;
}

void menu() {
	YuVectorList* vList = NULL;
	bool vRepeat = true;
	string vInputString;
	int vOperationNumber;
	printMenuHeader();
	while (vRepeat) {
		std::cout << ">> ";
		std::cin >> vInputString;
		
		bool isString = false;
		for (size_t i = 0 ; i < vInputString.size(); i++) {
			if (isdigit(vInputString[i]) == 0) {
				isString += true;
			}
		}
		if (isString) {
			vOperationNumber = 999;
		}
		else {
			vOperationNumber = atoi(vInputString.c_str());
		}
		
		switch (vOperationNumber) {
		//==============================================================================
		case 0:
			vRepeat = false;
			if (vList != NULL) {
				vList->~YuVectorList();
			}
			break;
		//==============================================================================
		case 1:
			if (vList == NULL) {
				vList = new YuVectorList;
				std::cout << "Список создан [0x" << vList << "]" << endl;
			}
			else {
				char vTmpFlag = false;
				std::cout << "Удалить старый список и создать новый? [y/n]" << endl;
				std::cout << ">> ";
				std::cin >> vTmpFlag;
				if (vTmpFlag == 'y') {
					vList->~YuVectorList();
					vList = new YuVectorList();
					std::cout << "Список пересоздан [0x" << vList << "]" << endl;
				}
				else if (vTmpFlag == 'n') {
					std::cout << "Список не пересоздан [0x" << vList << "]" << endl;
				}
				else {
					std::cout << "Некорректный ответ, возврат в главное меню" << endl;
				}
			}
			break;
		//==============================================================================
		case 2:
			if (vList != NULL) {
				vList->show();
			}
			else {
				std::cout << "Список не создан" << endl;
			}
			break;
		//==============================================================================
		case 3:
			if (vList != NULL) {
				int vTmpNumber;
				std::cout << "[ 1 ] Добавить в конец списка" << endl;
				std::cout << "[ 2 ] Добавить в i-ую позицию списка" << endl;
				std::cout << "[ 0 ] Выход" << endl;
				std::cout << ">> ";
				std::cin >> vTmpNumber;
				if (vTmpNumber == 0) {
					;
				}
				else if (vTmpNumber == 1) {
					vList->add(new YuVector(true));
				}
				else if (vTmpNumber == 2) {
					size_t vIndex;
					std::cout << "Введите номер позиции от 0 до " << vList->getLength() << endl;
					std::cout << ">> ";
					std::cin >> vIndex;
					if ((vIndex >= 0) && (vIndex <= vList->getLength())) {
						vList->add(new YuVector(true), vIndex);
					}
					else {
						std::cout << "Выход за границы диапазона, возврат в главное меню" << endl;
					}
				}
				else {
					std::cout << "Некорректный выбор, возврат в главное меню" << endl;
				}
			}
			else {
				std::cout << "Список не создан" << endl;
			}
			break;
		//==============================================================================
		case 4:
			if (vList != NULL) {
				if (vList->getLength() > 0) {
					size_t vIndex;
					std::cout << "Введите номер позиции от 0 до " << vList->getLength() - 1 << endl;
					std::cout << ">> ";
					std::cin >> vIndex;
					if ((vIndex >= 0) && (vIndex <= (vList->getLength() - 1))) {
						(*vList)[vIndex]->getVector()->show();
					}
					else {
						std::cout << "Выход за границы диапазона, возврат в главное меню" << endl;
					}
				}
				else {
					std::cout << "Список пуст" << endl;
				}
			}
			else {
				std::cout << "Список не создан" << endl;
			}
			break;
		//==============================================================================
		case 5:
			if (vList != NULL) {
				if (vList->getLength() > 0) {
					size_t vIndex;
					std::cout << "Введите номер позиции от 0 до " << vList->getLength() - 1 << endl;
					std::cout << ">> ";
					std::cin >> vIndex;
					if ((vIndex >= 0) && (vIndex <= (vList->getLength() - 1))) {
						double vE1, vE2, vE3;
						std::cout << "[0x" << (*vList)[vIndex]->getVector() << "]" << endl;
						std::cout << "Введите новую координату e1: ";
						std::cin >> vE1;
						(*vList)[vIndex]->getVector()->setE1(vE1);
						std::cout << "Введите новую координату e2: ";
						std::cin >> vE2;
						(*vList)[vIndex]->getVector()->setE2(vE2);
						std::cout << "Введите новую координату e3: ";
						std::cin >> vE3;
						(*vList)[vIndex]->getVector()->setE3(vE3);
					}
					else {
						std::cout << "Выход за границы диапазона, возврат в главное меню" << endl;
					}
				}
				else {
					std::cout << "Список пуст" << endl;
				}
			}
			else {
				std::cout << "Список не создан" << endl;
			}
			break;
		//==============================================================================
		case 6:
			if (vList != NULL) {
				if (vList->getLength() > 0) {
					size_t vIndex;
					std::cout << "Введите номер позиции от 0 до " << vList->getLength() - 1 << endl;
					std::cout << ">> ";
					std::cin >> vIndex;
					if ((vIndex >= 0) && (vIndex <= (vList->getLength() - 1))) {
						vList->remove(vIndex);
					}
					else {
						std::cout << "Выход за границы диапазона, возврат в главное меню" << endl;
					};
				}
				else {
					std::cout << "Список пуст" << endl;
				}
			}
			else {
				std::cout << "Список не создан" << endl;
			}
			break;
			//==============================================================================
		case 7:
			if (vList != NULL) {
				if (vList->getLength() > 0) {
					YuVector* vVecs[3];
					for (size_t i = 0; i < 2; i++) {
						size_t vIndex;
						std::cout << "Введите номер позиции от 0 до " << vList->getLength() - 1 << endl;
						std::cout << ">> ";
						std::cin >> vIndex;
						if ((vIndex >= 0) && (vIndex <= (vList->getLength() - 1))) {
							vVecs[i] = (*vList)[vIndex]->getVector();
						}
						else {
							std::cout << "Выход за границы диапазона, возврат в главное меню" << endl;
						}
					}
					vVecs[2] = new YuVector((*vVecs[0]) + (*vVecs[1]));
					vVecs[2]->show();

					int vTmpNumber;
					std::cout << "[ 1 ] Добавить в конец списка" << endl;
					std::cout << "[ 2 ] Добавить в i-ую позицию списка" << endl;
					std::cout << "[ 0 ] Выход" << endl;
					std::cout << ">> ";
					std::cin >> vTmpNumber;
					if (vTmpNumber == 0) {
						vVecs[2]->~YuVector();
						vVecs[0] = vVecs[1] = vVecs[2] = NULL;
					}
					else if (vTmpNumber == 1) {
						vList->add(vVecs[2]);
					}
					else if (vTmpNumber == 2) {
						size_t vIndex;
						std::cout << "Введите номер позиции от 0 до " << vList->getLength() << endl;
						std::cout << ">> ";
						std::cin >> vIndex;
						if ((vIndex >= 0) && (vIndex <= vList->getLength())) {
							vList->add(vVecs[2], vIndex);
						}
						else {
							std::cout << "Выход за границы диапазона, возврат в главное меню" << endl;
							vVecs[2]->~YuVector();
							vVecs[0] = vVecs[1] = vVecs[2] = NULL;
						}
					}
					else {
						std::cout << "Некорректный выбор, возврат в главное меню" << endl;
						vVecs[2]->~YuVector();
						vVecs[0] = vVecs[1] = vVecs[2] = NULL;
					}
				}
				else {
					std::cout << "Список пуст" << endl;
				}
			}
			else {
				std::cout << "Список не создан" << endl;
			}
			break;
			//==============================================================================
		case 8:
			if (vList != NULL) {
				if (vList->getLength() > 0) {
					YuVector* vVecs[3];
					for (size_t i = 0; i < 2; i++) {
						size_t vIndex;
						std::cout << "Введите номер позиции от 0 до " << vList->getLength() - 1 << endl;
						std::cout << ">> ";
						std::cin >> vIndex;
						if ((vIndex >= 0) && (vIndex <= (vList->getLength() - 1))) {
							vVecs[i] = (*vList)[vIndex]->getVector();
						}
						else {
							std::cout << "Выход за границы диапазона, возврат в главное меню" << endl;
						}
					}
					vVecs[2] = new YuVector((*vVecs[0]) - (*vVecs[1]));
					vVecs[2]->show();

					int vTmpNumber;
					std::cout << "[ 1 ] Добавить в конец списка" << endl;
					std::cout << "[ 2 ] Добавить в i-ую позицию списка" << endl;
					std::cout << "[ 0 ] Выход" << endl;
					std::cout << ">> ";
					std::cin >> vTmpNumber;
					if (vTmpNumber == 0) {
						vVecs[2]->~YuVector();
						vVecs[0] = vVecs[1] = vVecs[2] = NULL;
					}
					else if (vTmpNumber == 1) {
						vList->add(vVecs[2]);
					}
					else if (vTmpNumber == 2) {
						size_t vIndex;
						std::cout << "Введите номер позиции от 0 до " << vList->getLength() << endl;
						std::cout << ">> ";
						std::cin >> vIndex;
						if ((vIndex >= 0) && (vIndex <= vList->getLength())) {
							vList->add(vVecs[2], vIndex);
						}
						else {
							std::cout << "Выход за границы диапазона, возврат в главное меню" << endl;
							vVecs[2]->~YuVector();
							vVecs[0] = vVecs[1] = vVecs[2] = NULL;
						}
					}
					else {
						std::cout << "Некорректный выбор, возврат в главное меню" << endl;
						vVecs[2]->~YuVector();
						vVecs[0] = vVecs[1] = vVecs[2] = NULL;
					}
				}
				else {
					std::cout << "Список пуст" << endl;
				}
			}
			else {
				std::cout << "Список не создан" << endl;
			}
			break;
			//==============================================================================
		case 9:
			if (vList != NULL) {
				if (vList->getLength() > 0) {
					YuVector* vVecs[2];
					for (size_t i = 0; i < 2; i++) {
						size_t vIndex;
						std::cout << "Введите номер позиции от 0 до " << vList->getLength() - 1 << endl;
						std::cout << ">> ";
						std::cin >> vIndex;
						if ((vIndex >= 0) && (vIndex <= (vList->getLength() - 1))) {
							vVecs[i] = (*vList)[vIndex]->getVector();
						}
						else {
							std::cout << "Выход за границы диапазона, возврат в главное меню" << endl;
						}
					}
					double vMul = (*vVecs[0]) * (*vVecs[1]);
					std::cout << "Скалярное произведение векторов равно: " << vMul << endl;
					vVecs[0] = vVecs[1] = NULL;
				}
				else {
					std::cout << "Список пуст" << endl;
				}
			}
			else {
				std::cout << "Список не создан" << endl;
			}
			break;
			//==============================================================================
		case 11:
			if (vList != NULL) {
				std::cout << vList->getLength() << endl;
			}
			break;
			//==============================================================================
		case 99:
			printMenuHeader();
			break;
			//==============================================================================
		default:
			std::cout << "Ошибка ввода" << endl;
			break;
		}
		std::cout << endl;
	}
}