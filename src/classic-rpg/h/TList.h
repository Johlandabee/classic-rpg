#pragma once

template <class T>
class TList {
	struct TElement {
		explicit TElement(T const& v) {
			value = v;
		}

		~TElement() {
			delete pNextElement,
				   pPreviousElement,
			       value;

			pNextElement = nullptr;
			pPreviousElement = nullptr;
		}

		T value;
		TElement* pNextElement = nullptr;
		TElement* pPreviousElement = nullptr;
	};

	TElement* pFirstElement = nullptr;
	TElement* pLastElement = nullptr;
	TElement* pCurrentElement = nullptr;

	int count_ = 0;

public:
	TList();
	~TList();

	T operator[](const int index);

	void add(T const& element);
	void remove(T const& element);
};

template <class T>
TList<T>::TList() {
}

template <class T>
TList<T>::~TList() {
	delete pLastElement,
		   pCurrentElement,
		   pFirstElement;

	pLastElement = nullptr;
	pCurrentElement = nullptr;
	pFirstElement = nullptr;
}

template <class T>
T TList<T>::operator[](const int index) {
	
	pCurrentElement = pFirstElement;

	for (auto i = 0; i < index + 1; i++) {
		pCurrentElement = pCurrentElement->pNextElement;
	}

	return pCurrentElement->value;
}

template <class T>
void TList<T>::add(T const& element) {
	if (pFirstElement == nullptr) {
		pFirstElement = new TElement(element);
		pLastElement = pFirstElement;
	}
	else {
		pLastElement->pNextElement = new TElement(element);
		pLastElement->pPreviousElement = pLastElement;
		pLastElement = pLastElement->pNextElement;
	}

	count_++;
}

template <class T>
void TList<T>::remove(T const& element) {
	
}

