#include <iostream>
using namespace std;
template <typename T>
struct Node
{
	T data;
	Node* next;
	Node():next(nullptr){}
	Node(T data):data(data), next(nullptr){}
};

template <typename T>
class LinkedList
{
	public:
		LinkedList()
		{
			head = new Node<T>;
			tail = new Node<T>;
			head = nullptr;
			tail = nullptr;
		}
		~LinkedList()
		{
			if(head)
			{
				if(head != tail )
				{
					delete head;
					head = nullptr;
					delete tail;
					tail = nullptr;
				}
				else
				{
					delete head;
					head = nullptr;
				}
			}
		}
		void insert( T data)
		{
			if(head)
			{
				Node<T>* temp = new Node<T>(data);
				Node<T>* current = head;
				temp->next = current;
				head = temp;

			}
			else
			{
				head = new Node<T>();
				head->data = data;
				tail = head;
			}
		}
		void insert(T data, int pos)
		{
			if(pos == 0)
			{
				insert(data);
				return;
			}
			Node<T>*current = head;
			Node<T>*temp = new Node<T>(data);
			--pos;
			while(pos--)
			{
				current = current->next;
			}
			temp->next = current->next;
			current->next = temp;

		}
		void push_back(T data)
		{
			if(head)
			{
				Node<T>*temp = new Node<T>(data);
				temp->next = nullptr;
				tail->next = temp;
				tail = tail->next;
			}
			else
			{
				head = new Node<T>(data);
				tail = head;
			}
		}
		void remove()
		{
			if(head == tail)
			{
				delete head;
				head = nullptr;
				return;
			}
			Node<T>*temp = new Node<T>;
			temp = head;
			head = head->next;
			delete temp;
			temp = nullptr;
		}
		
		void remove(int pos)
		{
			if(pos == 0)
			{
				this->remove();
				return;
			}
			if(pos < this->size())
			{
				Node<T>*tempBefore = new Node<T>;
				Node<T>*tempAfter = new Node<T>;
				Node<T>* temp = new Node<T>;
				tempBefore = head;
				tempAfter = tempBefore->next;
				--pos;
				temp = tempBefore;
				while(pos--)
				{
					tempBefore = tempBefore->next;
					tempAfter = tempBefore->next;
				}
				delete tempBefore->next;
				if(tempAfter->next)
				{
					tempBefore->next = tempAfter->next;
				}
				else
				{
					tempBefore->next = nullptr;
					tail = tempBefore;
				}
				head = temp;
			}
		}
		int size()
		{
			if(!head)
			{
				return 0;
			}
			int len = 1;
			Node<T>*temp= new Node<T>;
			temp = head;
			while(temp && temp != tail )
			{
				++len;
				temp = temp->next;
				cout << "ll\n";
			}
			return len;
		}
		void print()
		{
			if(!head)
			{
				return;
			}
			Node<T>* temp = head;
			while(temp->next)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << temp->data << endl;
		}
		void empty()
		{
			Node<T>* temp = new Node<T>;
			temp = head;
			while(head->next)
			{
				head = head->next;
				delete temp;
				temp = head;
			}
			delete head;
			head = nullptr;
		}
	private:
		Node<T>* head;
		Node<T>* tail;
};
