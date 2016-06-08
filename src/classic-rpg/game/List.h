#pragma once
#include <stdexcept>

using namespace std;

namespace Common {
	template <class T>
	struct ListElement {
		explicit ListElement(T const& v) {
			value = v;
		}

		~ListElement() {
			pNextElement = nullptr;
			pPreviousElement = nullptr;
		}

		T value;

		ListElement<T>* pNextElement = nullptr;
		ListElement<T>* pPreviousElement = nullptr;
	};

	template <class T>
	class List {
		ListElement<T>* pFirstElement = nullptr;
		ListElement<T>* pLastElement = nullptr;
		ListElement<T>* pCurrenElement = nullptr;

		uint count_ = 0;

	public:
		List();
		~List();

		T operator[](const uint index);

		void clear();
		void add(T const& element);
		void remove(T const& element);

		uint count() const;
		bool contains(T const& element);

	};

	template <class T>
	List<T>::List() {
	}

	template <class T>
	List<T>::~List() {
		delete pLastElement,
			pCurrenElement,
			pFirstElement;

		pLastElement = nullptr;
		pCurrenElement = nullptr;
		pFirstElement = nullptr;
	}

	template <class T>
	T List<T>::operator[](const uint index) {
		if (index < 0 || index > count_ - 1)
			throw out_of_range("Index out of range");

		pCurrenElement = pFirstElement;

		if (pCurrenElement == nullptr)
			throw out_of_range("List contains no elements");

	    
	    for (uint i = 0; i < index; i++) {
	        pCurrenElement = pCurrenElement->pNextElement;
	    }
	    

		return pCurrenElement->value;
	}

	template <class T>
	void List<T>::clear() {
		if (count_ > 0) {
			pCurrenElement = pFirstElement;

			for (auto i = 0; i < count_; i++) {
				if (pCurrenElement->pNextElement) {
					pCurrenElement = pCurrenElement->pNextElement;
					delete pCurrenElement->pPreviousElement;
				}
				else {
					delete pCurrenElement;
				}
			}

			pFirstElement = nullptr;
			pCurrenElement = nullptr;
			pLastElement = nullptr;

			count_ = 0;
		}
	}

	template <class T>
	void List<T>::add(T const& element) {
		if (pFirstElement == nullptr) {
			pFirstElement = new ListElement<T>(element);
			pLastElement = pFirstElement;
		}
		else {
			pLastElement->pNextElement = new ListElement<T>(element);
			pLastElement->pNextElement->pPreviousElement = pLastElement;
			pLastElement = pLastElement->pNextElement;
		}

		count_++;
	}

	template <class T>
	void List<T>::remove(T const& element) {
		if (count_ > 0) {
			pCurrenElement = pFirstElement;

			for (auto i = 1; i < count_; i++) {
				if (pCurrenElement->value == element) {
					if (pCurrenElement->pPreviousElement && pCurrenElement->pNextElement) {
						pCurrenElement->pPreviousElement->pNextElement = pCurrenElement->pNextElement;
						pCurrenElement->pNextElement->pPreviousElement = pCurrenElement->pPreviousElement;
					}
					else if (pCurrenElement->pPreviousElement) {
						pCurrenElement->pPreviousElement->pNextElement = nullptr;
						pLastElement = pCurrenElement->pPreviousElement;
					}
					else if (pCurrenElement->pNextElement) {
						pCurrenElement->pNextElement->pPreviousElement = nullptr;
						pFirstElement = pCurrenElement->pNextElement;
					}
					else {
						pFirstElement = nullptr;
						pLastElement = nullptr;
					}

					delete pCurrenElement;
					pCurrenElement = nullptr;
					break;
				}
				pCurrenElement = pCurrenElement->pNextElement;
			}
		}

		count_--;
	}

	template <class T>
	unsigned List<T>::count() const {
		return count_;
	}

	template <class T>
	bool List<T>::contains(T const& element) {
		if (count_ > 0) {
			pCurrenElement = pFirstElement;

			for (auto i = 0; i < count_; i++) {
				if (pCurrenElement->value == element) {
					return true;
				}
				pCurrenElement = pCurrenElement->pNextElement;
			}
		}

		return false;
	}
}
