#include <iostream>

#include "Device.h"

using std::cout;
using std::endl;

std::string getDeviceTypeString(const DeviceType type)
{
	if (type == PC)
		return "PC";
	else if (type == LAPTOP)
		return "Laptop";
	else if (type == TABLET)
		return "Tablet";
	else if (type == PHONE)
		return "Phone";
	return "Unknown";
}

std::string getDeviceString(const Device& device)
{
	return
		"[ID: " + std::to_string(device.getID()) +
		", Type: " + getDeviceTypeString(device.getType()) +
		", OS: " + device.getOS() +
		", Activated: " + (device.isActive() ? "Yes" : "No") + "]";
}

int test1Device()
{
	bool result = false;

	try
	{
		// Tests Ex2 part 1 - Device

		cout <<
			"*******************\n" <<
			"Test 1 - Device				\n" <<
			"*******************\n" << endl;


		Device device1;
		std::string expected;
		std::string got;

		try
		{
			cout <<
				" \nInitializing Device1 - [ID: 3343, Type: PC, OS: Windows11]: ... \n" << endl;
			device1.init(3343, PC, WINDOWS11);
			expected = "[ID: 3343, Type: PC, OS: Windows11, Activated: Yes]";
			got = getDeviceString(device1);

			if (got != expected)
			{
				cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
				cout << "Expected: " << expected << endl;
				cout << "Got     : " << got << std::endl;
				system("./printMessage 2101");
				std::cout << " \n" << endl;
				return 2101;
			}
		}
		catch (...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2101");
			cout << " \n" << endl;
			return 2101;
		}

		cout <<
			"\nDeactivating Device1: ... \n" << endl;
		cout << "Running Test ... \t";
		device1.deactivate();

		expected = "[ID: 3343, Type: PC, OS: Windows11, Activated: No]";
		got = getDeviceString(device1);

		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{			
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 2102");
			cout << " \n" << endl;
			return 2102;
		}

		cout <<
			"\nActivating Device1: ... \n" << endl;
		cout << "Running Test ... \t";
		device1.activate();

		expected = "[ID: 3343, Type: PC, OS: Windows11, Activated: Yes]";
		got = getDeviceString(device1);

		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 2103");
			cout << " \n" << endl;
			return 2103;
		}
	}
	catch (...)
	{
		std::cerr << "\033[1;31mTest crashed\033[0m\n \n" << endl;
		std::cerr << "\033[1;31mFAILED: The program crashed, check the following things:\n\033[0m\n \n" <<
			"1. Did you delete a pointer twice?\n2. Did you access index out of bounds?\n" << 
			"3. Did you remember to initialize array before accessing it?";
		return 2;
	}

	return 0;

}

int main()
{
	std::cout <<
		"###########################\n" <<
		"Exercise 2 - Social Network\n" <<
		"Part 1 - Device\n" << 
		"###########################\n" << std::endl;

	int testResult = test1Device();

	cout << (testResult == 0 ? "\033[1;32m \n****** Ex2 Part 1 Tests Passed ******\033[0m\n \n" : "\033[1;31mEx2 Part 1 Tests Failed\033[0m\n \n") << endl;

	return testResult ;
}