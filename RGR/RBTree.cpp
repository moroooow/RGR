#include "RBTree.h"

namespace rbtree
{
	void RBTree::insertElement(std::string& key, std::list<std::string>& translates)
	{
		auto it = tree_.find(key);
		if (it != tree_.end())
		{
			for (const auto& translate : translates)
			{
				if (std::find(it->second.begin(), it->second.end(), translate) == it->second.end())
				{
					it->second.push_back(translate);
				}
			}
			it->second.sort();
		}
		else
		{
			tree_.emplace(key, translates);
			auto it = tree_.find(key);
			it->second.sort();
		}
		
	}

	bool RBTree::searchElement(std::string& key) const
	{
		auto it = tree_.find(key);
		if (it == tree_.end())
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void RBTree::deleteElement(std::string& key)
	{
		tree_.erase(key);
	}

	void RBTree::printTree(std::ostream& out)
	{
		for (auto it = tree_.cbegin(); it != tree_.cend(); ++it)
		{
			out << it->first << " : " << it->second<<std::endl;
		}
	}

	std::list<std::string> rbtree::RBTree::getTranslateByKey(std::string& key)
	{
		std::list<std::string> lst;

		auto it = tree_.find(key);
		if (it != tree_.end())
		{
			return it->second;
		}
		else
		{
			return lst;
		}
	}

	std::ostream& operator<<(std::ostream& out, const std::list<std::string>& data)
	{
		if (!data.size())
		{
			out << "THE LIST IS EMPTY!";
			return out;
		}

		for (auto it = data.cbegin(); it != data.cend(); ++it)
		{
			if (std::next(it) == data.cend())
			{
				out << *it;
				break;
			}
			out << *it << ", ";
		}
		return out;
	}

}