
#pragma once

#include "fortest.h"



template <typename T>
class Ring
{
public:

	Ring(size_t maximumNumberOfElements) noexcept;
	~Ring();

	Ring(Ring& a) noexcept;
	Ring& operator=(const Ring& a) noexcept;

	bool push(T& inValue);
	bool take(T * out);

private:
	inline bool copyAuxiliary(const T& a) noexcept;

private:

	T * m_buffer;
	T * m_endBuffer;
	T * m_head;
	T * m_tail;

	int isFull;

private:
	size_t capacity;

};



template <typename T>
Ring<T>::Ring(size_t maximumNumberOfElements) noexcept {

	if (maximumNumberOfElements <= 0) {
		m_endBuffer = m_buffer = nullptr;
		m_tail = m_head = 0;
		capacity = 0;
		return;
	}
	m_buffer = new Int[maximumNumberOfElements];
	m_endBuffer = m_buffer + maximumNumberOfElements;
	m_tail = m_head = m_buffer;
	isFull = 0;
	capacity = maximumNumberOfElements;
};


template<typename T>
inline bool Ring<T>::copyAuxiliary(const T & a) noexcept
{

	if (a.capacity > 0) m_buffer = new Int[a.capacity]; else m_buffer = nullptr;
	if (a.capacity <= 0 || !m_buffer){
		m_endBuffer = m_buffer = nullptr;
		m_tail = m_head = 0;
		capacity = 0;
		return false;
		}

	capacity = a.capacity;
	m_endBuffer = m_buffer + capacity;
	m_tail = m_buffer + (a.tail - a.m_buffer);
	m_head = m_buffer + (a.head - a.m_buffer);
	isFull = a.isFull;
	memcpy(m_buffer, a.m_buffer, sizeof(T)*capacity);//c-style, but i like it sometimes. it works.
	return true;
}




template <typename T>
Ring<T>::Ring(Ring& a) noexcept {
	copyAuxiliary(a);
};

template <typename T>
Ring<T>& Ring<T>::operator=(const Ring<T>& a) noexcept {
	if (&a == this)
		return *this;
	if (m_buffer)
		delete[] m_buffer;
	copyAuxiliary(a);
	return *this;
}



template <typename T>
Ring<T>::~Ring() {
	if (m_buffer){
		delete[] m_buffer;
		m_buffer =nullptr;
		capacity = 0;
	}
};



template <typename T>
bool Ring<T>::push(T& inValue) {
	if (!capacity || (m_head == m_tail && isFull)) return false;//if non-allocated or full
	*m_head = inValue;
	//if (m_tail == nullptr) m_tail = m_buffer;
	if ((++m_head) == m_endBuffer) {
		m_head = m_buffer;
	}
	if (m_head == m_tail) isFull = 1;
	return true;
}

template <typename T>
bool Ring<T>::take(T * out) {
	if ((!capacity || m_head == m_tail || m_tail == nullptr) && !isFull) return false;
	*out = std::move(*m_tail);
	if ((++m_tail) == m_endBuffer) m_tail = m_buffer;
	isFull = 0;
	return true;
}


