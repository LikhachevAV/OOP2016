#pragma once

#include <string>
#include <memory>

class CStringList
{
	struct Node
	{
		Node(const std::string & data, Node * prev, std::unique_ptr<Node> && next)
			: data(data), prev(prev), next(std::move(next))
		{
		}
		std::string data;
		Node *prev;
		std::unique_ptr<Node> next;
	};
public:
	~CStringList();
	size_t GetSize()const;

	bool IsEmpty() const;

	void Append(const std::string& data);

	class CIterator
	{
		friend CStringList;
		CIterator(Node *node);
	public:
		CIterator() = default;
		std::string & operator*()const;
		CIterator & operator++();
	private:
		Node *m_node = nullptr;
	};

	CIterator begin();

	CStringList::CIterator const cbegin() const;

	CStringList::CIterator end();

	CStringList::CIterator const cend() const;

	CStringList::CIterator rbegin();

	CStringList::CIterator const crbegin() const;

	CStringList::CIterator rend();

	CStringList::CIterator const crend() const;

	std::string & GetBackElement();
	std::string const& GetBackElement()const;
	void Clear();
private:
	size_t m_size = 0;
	std::unique_ptr<Node> m_firstNode;
	Node * m_lastNode = nullptr;
};