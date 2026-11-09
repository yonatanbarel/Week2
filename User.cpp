#include "User.h"

void User::init(unsigned int id, std::string username, unsigned int age)
{
	_id = id;
	_username = username;
	_age = age;
	_devices.init();
}

void User::clear()
{
	_devices.clear();
}

unsigned int User::getID() const
{
	return _id;
}

std::string User::getUserName() const
{
	return _username;
}

unsigned int User::getAge() const
{
	return _age;
}

DevicesList& User::getDevices()
{
	return _devices;
}

void User::addDevice(Device newDevice)
{
	_devices.add(newDevice);
}

bool User::checkIfDevicesAreOn() const
{
	DeviceNode* curr = _devices.get_first();
	while (curr != nullptr)
	{
		if (!curr->get_data().isActive())
		{
			return false;
		}
		curr = curr->get_next();
	}
	return true;
}