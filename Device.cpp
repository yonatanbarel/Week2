#include "Device.h"

void Device::init(unsigned int id, DeviceType type, std::string os)
{
	_id = id;
	_type = type;
	_os = os;
	_isActive = true;
}

unsigned int Device::getID() const
{
	return _id;
}

DeviceType Device::getType() const
{
	return _type;
}

std::string Device::getOS() const
{
	return _os;
}

bool Device::isActive() const
{
	return _isActive;
}

void Device::activate()
{
	_isActive = true;
}

void Device::deactivate()
{
	_isActive = false;
}