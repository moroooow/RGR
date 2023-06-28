#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE
#include "map"
#include "string"
#include "list"
#include "iostream"
#include "exception"


namespace rbtree
{
	using RBTmap= std::map<std::string, std::list<std::string>>;

	class RBTree
	{
	public:
		RBTree() = default;
		~RBTree() = default;

		void insertElement(std::string& key, std::list<std::string>& translates);
		bool searchElement(std::string& key)const;
		void deleteElement(std::string& key);
		
		std::list<std::string> getTranslateByKey(std::string& key);

		void printTree(std::ostream& out);

		

	private:
		RBTmap tree_;
	};

	class RBTreeException : public std::exception
	{
	private:
		std::string reason_;

	public:
		RBTreeException(std::string reason) : reason_(reason) {};

		const char* what() const noexcept override
		{
			return reason_.c_str();
		}
	};

	std::ostream& operator<<(std::ostream& out, const std::list<std::string>& data);
}
#endif // !RED_BLACK_TREE