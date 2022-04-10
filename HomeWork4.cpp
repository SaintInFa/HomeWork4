#include <iostream>
#include <cassert>
#include <vector>


//task 1
// operator[]
// pop_back()
// pop_front()
// sort()
// print()

class Container {
	int* data;
	int size;
	int capacity;
	int& operator[](int idx) {}

public:
	Container() : size(0), data(nullptr), capacity(0) { }
	Container(int _size) : size(_size) {
		if (_size == 0) {
			Container();
		}
		else if (_size < 0) {
			std::cout << "Something terrible has happened" << std::endl;
			Container();
		}
		else {
			this->data = new int[_size];
			this->capacity = 0;
		}
	}
	virtual ~Container() {
		delete[] data;
	}
	void setData(int idx, int value) {
		assert(idx >= 0 && idx < size);
		this->data[idx] = value;
	}
	int getData(int idx) {
		assert(idx >= 0 && idx < size);
		return this->data[idx];
	}
	int capacity() {
		return this->capacity;
	}
	void resize(int newLength) {
		if (newLength == size) return;
		if (newLength <= 0) {
			return;
		}
		int* newData = new int[newLength];
		if (size > 0) {
			int elemToCopy = (newLength > size) ? size : newLength;
			for (int idx = 0; idx < elemToCopy; idx++) {
				newData[idx] = data[idx];
			}
		}
		delete[] data;
		data = newData;
		size = newLength;
	}
	void erase() {
		capacity = 0;
		for (int idx = 0; idx < size; idx++) {
			data[idx] = 0;
		}
	}

	int& operator[](int idx)
	{
		assert(idx >= 0 && idx < size);
		return data[idx];
	}

	void pop_back() {
		if (size <= 0) {
			return;
		}
		int* newData = new int[size - 1];
		for (int idx = 0; idx < size - 1 ; idx++) {
			newData[idx] = data[idx];
		}
		delete[] data;
		data = newData;
		size = size - 1;
	}

	void pop_front() {
		if (size <= 0) {
			return;
		}
		int* newData = new int[size - 1];
		for (int idx = 0; idx < size - 1; idx++) {
			newData[idx] = data[idx+1];
		}
		delete[] data;
		data = newData;
		size = size - 1;
	};

	void sort() {
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i; j++) {
				if (data[j] > data[j + 1]) {
					int u = data[j];
					data[j] = data[j + 1];
					data[j + 1] = u;
				}
			}
		}
	}

	void print() {
		for (int i = 0; i < size; i++)
			std::cout << data[i] << " ";
		std::cout << std::endl;
	};

};


//task 2
//2. Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться
//использовать максимально быстрый алгоритм.

std::vector<int> array = { 1,2,1,2,5 };
	int u=0;
	for (int i = 0; i < array.size(); i++) {
		bool z = false;
		for (int k = i + 1; k < array.size(); k++) {
			if (array[i] == array[k]) {
				z = true;
				break;
			}
		}
		if (!z) {
			u++;
		}

	}

	// Реализовать класс Hand, который представляет собой коллекцию карт. В классе будет
	//одно поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути
	//динамический массив, а тип его элементов должен быть - указатель на объекты класса
	//Card). Также в классе Hand должно быть 3 метода:
	//• метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в
	//качестве параметра указатель на новую карту
	//• метод Clear, который очищает руку от карт
	//• метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того,
	//что туз может быть равен 11).

	enum ECardSuit { SPADES, CLUBS, DIAMONDS, HEARTS };
	enum ECardValue {
		ACE = 1,
		TWO = 2,
		THREE = 3,
		FOUR = 4,
		FIVE = 5,
		SIX = 6,
		SEVEN = 7,
		EIGHT = 8,
		NINE = 9,
		TEN = 10,
		JACK = 10,
		QUEEN = 10,
		KING = 10
	};
	class Card {
		ECardSuit suit;
		ECardValue value;
		bool isCoverUp;
	public:
		Card(ECardSuit _suit, ECardValue _value) : suit(_suit), value(_value) {
			isCoverUp = true;
		}

		void flip() {
			isCoverUp = !isCoverUp;
		}
		ECardValue getValue() const {
			return value;
		}
	};


	class Hand {
		std::vector<Card*> m_Card;
	public:
		void AddCard(Card* pCard) {
			m_Card.push_back(pCard);
		};
		void ClearCard() {
			m_Card.clear();
		}
		int GetValueCard() {
			int ValueCardInHand = 0;
			for (int i = 0; i < m_Card.size(); i++) {
				if (m_Card[i]->getValue() == 1) {
					ValueCardInHand = ValueCardInHand + 10;
				};
				ValueCardInHand = m_Card[i]->getValue() + ValueCardInHand;

			}
		}
	};




	int main()
	{

	}
