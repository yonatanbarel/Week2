#include <iostream>
#include "User.h"

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

std::string getUserString(const User& user)
{
	return
		"[ID: " + std::to_string(user.getID()) +
		", Username: " + user.getUserName() +
		", Age: " + std::to_string(user.getAge()) +
		", All devices On: " + (user.checkIfDevicesAreOn() ? "Yes" : "No") + "]";
}

std::string getUserDevicesString(User& user)
{
	std::string result = "";
	DevicesList userDevices = user.getDevices();
	DeviceNode* device = userDevices.get_first();
	for (; device != nullptr; device = device->get_next())
	{
		result += getDeviceString(device->get_data());
		result += "\n";
	}
	if (result != "")
	{
		// removes the '\n' at the end of the string
		result = result.substr(0, result.length() - 1);
	}
	return result;
}

int test2User()
{
	bool result = false;

	try
	{
		// Tests Ex2 part 2 - User
		cout <<
			"********************\n" <<
			"Test 2 - User				\n" <<
			"********************\n" << endl;

		Device device1;
		Device device2;
		Device device3;
		Device device4;

		std::string expected;
		std::string got;

		try
		{
			cout <<
				" \nInitializing 4 Devices:\n" <<
					"[ID: 3343, Type: Laptop, OS: Windows11, Activated: Yes] \n" <<
					"[ID: 3212, Type: PC, OS: UbuntuLinux, Activated: Yes] \n" <<
					"[ID: 1121, Type: Tablet, OS: Windows10, Activated: Yes] \n" <<
					"[ID: 4134, Type: Phone, OS: Android, Activated: Yes] \n" << endl;

			device1.init(3343, LAPTOP, WINDOWS11);
			device2.init(3212, PC, UbuntuOS);
			device3.init(1121, TABLET, WINDOWS10);
			device4.init(4134, PHONE, ANDROID);

			expected = "[ID: 3343, Type: Laptop, OS: Windows11, Activated: Yes]\n";
			expected += "[ID: 3212, Type: PC, OS: UbuntuLinux, Activated: Yes]\n";
			expected += "[ID: 1121, Type: Tablet, OS: Windows10, Activated: Yes]\n";
			expected += "[ID: 4134, Type: Phone, OS: Android, Activated: Yes]";
			got =
				getDeviceString(device1) + "\n" +
				getDeviceString(device2) + "\n" +
				getDeviceString(device3) + "\n" +
				getDeviceString(device4);

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

		User user1;
		User user2;
		try
		{
			cout <<
				" \nInitializing 2 Users:\n" <<
				"[ID: 123456789, Username: blinkybill, Age: 17, All devices On: Yes] \n" <<
				"[ID: 987654321, Username: HatichEshMiGilShesh, Age: 15, All devices On: Yes] \n" << endl;

			user1.init(123456789, "blinkybill", 17);
			user2.init(987654321, "HatichEshMiGilShesh", 15);

			expected = "[ID: 123456789, Username: blinkybill, Age: 17, All devices On: Yes]\n";
			expected += "[ID: 987654321, Username: HatichEshMiGilShesh, Age: 15, All devices On: Yes]";

			got =
				getUserString(user1) + "\n" +
				getUserString(user2);

			if (got != expected)
			{
				cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
				cout << "Expected:\n" << expected << endl;
				cout << "Got:\n" << got << endl;
				system("./printMessage 2201");
				cout << " \n" << endl;
				return 2201;
			}
		}
		catch (...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2201");
			cout << " \n" << endl;
			return 2201;
		}

		cout <<
			"\nAdding 2 devices to user1: ... \n" << endl;
		cout << "Running Test ... \t";

		user1.addDevice(device1);
		user1.addDevice(device2);

		expected = "[ID: 3343, Type: Laptop, OS: Windows11, Activated: Yes]\n";
		expected += "[ID: 3212, Type: PC, OS: UbuntuLinux, Activated: Yes]";
		got = getUserDevicesString(user1);

		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected:\n" << expected << endl;
			cout << "Got:\n" << got << endl;
			system("./printMessage 2202");
			cout << " \n" << endl;
			return 2202;
		}

		cout <<
			"\nAdding 2 devices to user2: ... \n" << endl;
		cout << "Running Test ... \t";

		user2.addDevice(device3);
		user2.addDevice(device4);

		expected = "[ID: 1121, Type: Tablet, OS: Windows10, Activated: Yes]\n";
		expected += "[ID: 4134, Type: Phone, OS: Android, Activated: Yes]";
		got = getUserDevicesString(user2);

		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected:\n" << expected << endl;
			cout << "Got:\n" << got << endl;
			system("./printMessage 2203");
			cout << " \n" << endl;
			return 2203;
		}

		cout <<
			"\nChecking if devices are ON for user1: ... \n" << endl;
		cout << "Running Test ... \t";

		expected = "true";
		got = user1.checkIfDevicesAreOn() ? "true" : "false";

		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected:\n" << expected << endl;
			cout << "Got:\n" << got << endl;
			system("./printMessage 2204");
			cout << " \n" << endl;
			return 2204;
		}


		cout <<
			"\nDeactivating a device for user2: ... \n" << endl;
		user2.getDevices().get_first()->get_data().deactivate();
		cout <<
			"Checking if devices are on for user2: ... \n" << endl;
		cout << "Running Test ... \t";

		expected = "false";
		got = user2.checkIfDevicesAreOn() ? "true" : "false";

		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected:\n" << expected << endl;
			cout << "Got:\n" << got << endl;
			system("./printMessage 2205");
			cout << " \n" << endl;
			return 2205;
		}

		try
		{
			cout << "Calling user1.clear()...\n" << endl;
			cout << "Running Test ... \t";
			user1.clear();
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;

			cout << "Calling user2.clear()...\n" << endl;
			cout << "Running Test ... \t";
			user2.clear();
		}
		catch (const std::exception& e)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2206");
			cout << " \n " << endl;
			cout << "Received the following error: " << e.what() << "\n"
				<< " \n " << endl;
			return 2206;
		}
		catch (...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2206");
			cout << " \n " << endl;
			return 2206;
		}
		cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;

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
		"Part 2 - User\n" <<
		"###########################\n" << std::endl;

	int testResult = test2User();
	
	cout << (testResult == 0 ? "\033[1;32m \n****** Ex2 Part 2 Tests Passed ******\033[0m\n \n" : "\033[1;31mEx2 Part 2 Tests Failed\033[0m\n \n") << endl;
	
	return testResult ;

}