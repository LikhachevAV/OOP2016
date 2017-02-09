#pragma once
#include <iterator>

template<typename T>
class CMyIterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
public:
	~CMyIterator()
	{
		m_pointer = nullptr;
	}

	template<typename T> CMyIterator()
		:m_pointer(nullptr)
	{
	}

	template<typename T> (const CMyIterator& it) :
		m_pointer(it.m_pointer)
	{
	}

	template<typename T> operator=(const CMyIterator & it)
	{
		m_pointer = it.m_pointer;
		return *this;
	}

	template<typename T> operator!=(CMyIterator const& other) const
	{
		return m_pointer != other.m_pointer;
	}

	template<typename T> operator==(CMyIterator const& other) const
	{
		return m_pointer == other.m_pointer;
	}

	 operator->() const
	{
		return std::addressof(operator*());
	}


	template<typename T> operator[](ptrdiff_t index) const
	{
		return *(m_pointer + index);
	}

	template<typename T> operator*() const
	{
		return *m_pointer;
	}

	template<typename T> operator++()
	{
		++m_pointer;
		return *this;
	}

	template<typename T> operator++(int)
	{
		CMyIterator<T> tmpCopy(*this);

		++*this;
		return tmpCopy;
	}

	template<typename T> operator--()
	{
		--m_pointer;
		return *this;
	}

	template<typename T> operator--(int)
	{
		CMyIterator<T> tmpCopy(*this);
		--*this;
		return tmpCopy;
	}

	template<typename T> operator+(ptrdiff_t n) const
	{
		return m_pointer + n;
	}

	template<typename T> operator-(CMyIterator<T> const & other) const
	{
		return m_pointer - other.m_pointer;
	}

	template<typename T>
	CMyIterator<T> const operator+(ptrdiff_t n, CMyIterator<T> const& iter)
	{
		return iter + n;
	}

	template<typename T> operator<(CMyIterator const& other)
	{
		return m_pointer < other.m_pointer;
	}

	template<typename T> operator>(CMyIterator const& other)
	{
		return m_pointer > other.m_pointer;
	}

	template<typename T> operator<=(CMyIterator const& other)
	{
		return m_pointer <= other.m_pointer;
	}

	template<typename T> operator>=(CMyIterator const& other)
	{
		return m_pointer >= other.m_pointer;
	}

	template<typename T> operator-(ptrdiff_t n) const
	{
		return m_pointer - n;
	}

private:
	T* m_pointer;
	template<typename T> m_pointer(p)
	{
	}
};