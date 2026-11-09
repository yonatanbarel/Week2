#include "Profile.h"

void Profile::init(User owner)
{
	_owner = owner;
	_page.init();
	_friendsList.init();
}

void Profile::clear()
{
	_page.clearPage();
	_friendsList.clear();
}

User Profile::getOwner() const
{
	return _owner;
}

void Profile::setStatus(std::string new_status)
{
	_page.setStatus(new_status);
}

void Profile::addPostToProfilePage(std::string post)
{
	_page.addLineToPosts(post);
}

void Profile::addFriend(User friend_to_add)
{
	_friendsList.add(friend_to_add);
}

std::string Profile::getPage() const
{
	std::string result = "";
	result += "Status: " + _page.getStatus() + "\n";
	result += "*******************\n";
	result += "*******************\n";
	std::string postsContent = _page.getPosts();
	if (postsContent != "")
	{
		result += postsContent + "\n";
	}
	return result;
}

std::string Profile::getFriends() const
{
	std::string result = "";
	UserNode* curr = _friendsList.get_first();
	while (curr != nullptr)
	{
		if (result == "")
		{
			result += curr->get_data().getUserName();
		}
		else
		{
			result += "," + curr->get_data().getUserName();
		}
		curr = curr->get_next();
	}
	return result;
}

std::string Profile::getFriendsWithSameNameLength() const
{
	std::string result = "";
	unsigned int ownerNameLen = _owner.getUserName().length();
	UserNode* curr = _friendsList.get_first();

	while (curr != nullptr)
	{
		if (curr->get_data().getUserName().length() == ownerNameLen)
		{
			if (result == "")
			{
				result += curr->get_data().getUserName();
			}
			else
			{
				result += "," + curr->get_data().getUserName();
			}
		}
		curr = curr->get_next();
	}
	return result;
}