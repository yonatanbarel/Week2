#include "SocialNetwork.h"

void SocialNetwork::init(std::string networkName, int minAge)
{
	_networkName = networkName;
	_minAge = minAge;
	_profilesList.init();
}

void SocialNetwork::clear()
{
	_profilesList.clear();
}

std::string SocialNetwork::getNetworkName() const
{
	return _networkName;
}

int SocialNetwork::getMinAge() const
{
	return _minAge;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < (unsigned int)_minAge)
	{
		return false;
	}
	_profilesList.add(profile_to_add);
	return true;
}

std::string SocialNetwork::getWindowsDevices() const
{
	std::string result = "";
	ProfileNode* pCurr = _profilesList.get_first();

	while (pCurr != nullptr)
	{
		User owner = pCurr->get_data().getOwner();
		DevicesList devList = owner.getDevices();
		DeviceNode* dCurr = devList.get_first();

		while (dCurr != nullptr)
		{
			std::string os = dCurr->get_data().getOS();
			if (os == WINDOWS7 || os == WINDOWS10 || os == WINDOWS11)
			{
				std::string deviceEntry = "[" + std::to_string(dCurr->get_data().getID()) + ", " + os + "]";
				if (result == "")
				{
					result += deviceEntry;
				}
				else
				{
					result += ", " + deviceEntry;
				}
			}
			dCurr = dCurr->get_next();
		}
		pCurr = pCurr->get_next();
	}
	return result;
}