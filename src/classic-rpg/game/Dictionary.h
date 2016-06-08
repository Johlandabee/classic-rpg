#pragma once
#include <stdexcept>
#include "Types.h"

using namespace std;

namespace Common {
	template <class TKey, class TValue>
	struct DictionaryElement {
		explicit DictionaryElement(TKey const& k, TValue const& v) {
			key = k;
			value = v;
		}

		~DictionaryElement() {
			pNextElement = nullptr;
			pNextElement = nullptr;
		}

		TKey key;
		TValue value;

		DictionaryElement<TKey, TValue>* pNextElement = nullptr;
		DictionaryElement<TKey, TValue>* pPreviousElement = nullptr;
	};
	
	template <class TKey, class TValue>
	class Dictionary {
		DictionaryElement<TKey, TValue>* pFirstElement = nullptr;
		DictionaryElement<TKey, TValue>* pLastElement = nullptr;
		DictionaryElement<TKey, TValue>* pCurrentElement = nullptr;

		uint count = 0;

	public:
		Dictionary();
		~Dictionary();

		TValue operator[](const TKey key);

		uint getCount() const;

		void clear();
		void add(TKey const& key, TValue const& value);
		void remove(TKey const& key);

		bool containsKey(TKey const& key);
		bool containsValue(TValue const& value);
	};

	template <class TKey, class TValue>
	Dictionary<TKey, TValue>::Dictionary() {
	}

	template <class TKey, class TValue>
	Dictionary<TKey, TValue>::~Dictionary() {
		delete pLastElement,
			pCurrentElement,
			pFirstElement;

		pLastElement = nullptr;
		pCurrentElement = nullptr;
		pFirstElement = nullptr;
	}

	template <class TKey, class TValue>
	TValue Dictionary<TKey, TValue>::operator[](const TKey key) {
		pCurrentElement = pFirstElement;

		if (pCurrentElement == nullptr)
			throw logic_error("Dictionary is empty");

		for (uint i = 0; i < count + 1; i++) {
			if (pCurrentElement->key == key) {
				return pCurrentElement->value;
			}

			pCurrentElement = pCurrentElement->pNextElement;
		}

		throw logic_error("Key not present");
	}

	template <class TKey, class TValue>
	unsigned Dictionary<TKey, TValue>::getCount() const {
		return count;
	}

	template <class TKey, class TValue>
	void Dictionary<TKey, TValue>::clear() {
		if (count > 0) {
			pCurrentElement = pFirstElement;

			for (auto i = 0; i < count; i++) {
				if (pCurrentElement->pNextElement) {
					pCurrentElement = pCurrentElement->pNextElement;
					delete pCurrentElement->pPreviousElement;
				}
				else {
					delete pCurrentElement;
				}
			}

			pFirstElement = nullptr;
			pCurrentElement = nullptr;
			pLastElement = nullptr;

			count = 0;
		}
	}

	template <class TKey, class TValue>
	void Dictionary<TKey, TValue>::add(TKey const& key, TValue const& value) {
		if (containsKey(key))
			throw invalid_argument("Key already in use");

		if (pFirstElement == nullptr) {
			pFirstElement = new DictionaryElement<TKey, TValue>(key, value);
			pLastElement = pFirstElement;
		}
		else {
			pLastElement->pNextElement = new DictionaryElement<TKey, TValue>(key, value);
			pLastElement->pNextElement->pPreviousElement = pLastElement;
			pLastElement = pLastElement->pNextElement;
		}

		count++;
	}

	template <class TKey, class TValue>
	void Dictionary<TKey, TValue>::remove(TKey const& key) {
		if (count > 0) {
			pCurrentElement = pFirstElement;

			for (uint i = 1; i < count; i++) {
				if (pCurrentElement->key == key) {
					if (pCurrentElement->pPreviousElement && pCurrentElement->pNextElement) {
						pCurrentElement->pPreviousElement->pNextElement = pCurrentElement->pNextElement;
						pCurrentElement->pNextElement->pPreviousElement = pCurrentElement->pPreviousElement;
					}
					else if (pCurrentElement->pPreviousElement) {
						pCurrentElement->pPreviousElement->pNextElement = nullptr;
						pLastElement = pCurrentElement->pPreviousElement;
					}
					else if (pCurrentElement->pNextElement) {
						pCurrentElement->pNextElement->pPreviousElement = nullptr;
						pFirstElement = pCurrentElement->pNextElement;
					}
					else {
						pFirstElement = nullptr;
						pLastElement = nullptr;
					}

					delete pCurrentElement;
					pCurrentElement = nullptr;
					break;
				}
				pCurrentElement = pCurrentElement->pNextElement;
			}
		}

		count--;
	}

	template <class TKey, class TValue>
	bool Dictionary<TKey, TValue>::containsKey(TKey const& key) {
		if (count > 0) {
			pCurrentElement = pFirstElement;

			for (uint i = 0; i < count; i++) {
				if (pCurrentElement->key == key) {
					pCurrentElement = nullptr;
					return true;
				}

				pCurrentElement = pCurrentElement->pNextElement;
			}
		}

		return false;
	}

	template <class TKey, class TValue>
	bool Dictionary<TKey, TValue>::containsValue(TValue const& value) {
		if (count > 0) {
			pCurrentElement = pFirstElement;

			for (auto i = 0; i < count; i++) {
				if (pCurrentElement->value == value) {
					return true;
				}
				pCurrentElement = pCurrentElement->pNextElement;
			}
		}

		return false;
	}
}
