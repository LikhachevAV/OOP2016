#pragma once
#include <iterator>
#include <initializer_list>

template<typename T>
class CMyIterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:

	CMyIterator() : 
		m_pointer(nullptr)
	{
	}

	CMyIterator(T* p) :
		m_pointer(p)
	{
	}

	CMyIterator(const CMyIterator& it) :
		m_pointer(it.m_pointer)
	{
	}

	CMyIterator& operator=(const CMyIterator & it)
	{
		m_pointer = it.m_pointer;
		return *this;
	}

	bool operator!=(CMyIterator const& other) const
	{
		return m_pointer != other.m_pointer;
	}

	bool operator==(CMyIterator const& other) const
	{
		return m_pointer == other.m_pointer;
	}

	 T* operator->() const
	{
		return std::addressof(operator*());
	}


	T& operator[](ptrdiff_t index) const
	{
		return *(m_pointer + index);
	}

	T& operator*() const
	{
		return *m_pointer;
	}

	CMyIterator& operator++()
	{
		++m_pointer;
		return *this;
	}

	CMyIterator const operator++(int)
	{
		CMyIterator<T> tmpCopy(*this);

		++*this;
		return tmpCopy;
	}

	CMyIterator& operator--()
	{
		--m_pointer;
		return *this;
	}

	CMyIterator const operator--(int)
	{
		CMyIterator<T> tmpCopy(*this);
		--*this;
		return tmpCopy;
	}

	CMyIterator const operator+(ptrdiff_t n) const
	{
		return m_pointer + n;
	}

	CMyIterator& operator-(CMyIterator<T> const & other) const
	{
		return m_pointer - other.m_pointer;
	}

	bool operator<(CMyIterator const& other) const
	{
		return m_pointer < other.m_pointer;
	}

	bool operator>(CMyIterator const& other) const
	{
		return m_pointer > other.m_pointer;
	}

	bool operator<=(CMyIterator const& other) const
	{
		return m_pointer <= other.m_pointer;
	}

	bool operator>=(CMyIterator const& other) const
	{
		return m_pointer >= other.m_pointer;
	}

	CMyIterator operator-(ptrdiff_t n) const
	{
		return m_pointer - n;
	}

private:
	T* m_pointer;
};