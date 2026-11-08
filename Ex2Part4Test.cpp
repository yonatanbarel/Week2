#include <iostream>
#include <random>

#include "SocialNetwork.h"

using std::cout;
using std::endl;

std::string posts[] = { "Hello world!",
						"Good morning :)",
						"Magshimim forever ***" ,
						"Ekronot is the best...",
						"Happy birthday! Ad 120" };

std::string statusMessages[] =
{ "Feeling sick, need chicken soup... can you bring me some?",
"Which witch watched which watch??? you must tell me!!!",
"Finally got my driver license !!!, when are you getting yours?",
"\"No matter how smart you are, you can never convince someone stupid that they are stupid.\"",
"Have you ever wondered why you can't taste your tongue?" };

// gets a random number between a range of numbers
int getRandomInt(int min, int max)
{
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased

	auto random_integer = uni(rng);
	return random_integer;
}

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

std::string getProfileString(const Profile& profile)
{
	return
		"Owner: " + getUserString(profile.getOwner()) + "\n" +
		profile.getOwner().getUserName() + "'s page:\n" +
		profile.getPage();
}

void allFriends(Profile* profiles[], const int numOfProfiles)
{
	for (unsigned int i = 0; i < numOfProfiles; i++)
	{
		for (unsigned int j = 0; j < numOfProfiles; j++)
		{
			if (j != i)
			{
				profiles[i]->addFriend(profiles[j]->getOwner());
			}
		}
	}
}

void generateRandomPage(Profile& profile)
{
	std::string status = statusMessages[getRandomInt(0, 4)];
	profile.setStatus(status);

	int numberOfPosts = getRandomInt(0, 3);
	std::string post;
	for (unsigned int i = 0; i < numberOfPosts; i++)
	{
		post = posts[getRandomInt(0, 4)];
		profile.addPostToProfilePage(post);
	}
}


bool test4SocialNetwork()
{
	bool result = false;

	try
	{
		// Tests Ex2 part 3 - Profile
		cout <<
			"*************************\n" <<
			"Test 4 - Social Network \n" <<
			"*************************\n" << endl;

		std::string expected;
		std::string got;
		
		Device device1;
		Device device2;
		Device device3;
		Device device4;
		Device device5;
		Device device6;
		Device device7;
		Device device8;
		Device device9;
		Device device10;
		Device device11;
		Device device12;
				
		try
		{
			cout <<
				" \nInitializing 12 Devices: \n" << endl;
				
			device1.init(2123, LAPTOP, WINDOWS11);
			device2.init(3212, PC, UbuntuOS);
			device3.init(1121, TABLET, WINDOWS10);
			device4.init(4134, PHONE, ANDROID);
			device5.init(5522, LAPTOP, MacOS);
			device6.init(5361, PC, WINDOWS7);
			device7.init(6611, PHONE, IOS);
			device8.init(6613, LAPTOP, RedHatOS);
			device9.init(7711, TABLET, WINDOWS11);
			device10.init(8181, TABLET, ANDROID);
			device11.init(8654, LAPTOP, UbuntuOS);
			device12.init(9444, PC, WINDOWS11);
		}
		catch (...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2101");
			cout << " \n" << endl;
			return 2101;
		}
		
		cout << "\033[1;32mOK\033[0m\n \n" << endl;

		User user1;
		User user2;
		User user3;
		User user4;
		User user5;
		User user6;

		try
		{
			cout <<
				"Initializing 6 Users: ... \n" << endl;

			user1.init(123456789, "Gal", 17);
			user2.init(987654321, "Avi", 15);
			user3.init(135792486, "Tom", 12);
			user4.init(123456789, "Nitzan", 12);
			user5.init(111222333, "Shlomo", 14);
			user6.init(222444666, "Rinat", 16);
		}
		catch (...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2201");
			cout << " \n" << endl;
			return 2201;
		}

		cout << "\033[1;32mOK\033[0m\n \n" << endl;

		cout <<
			"Adding 2 devices to each user: ... \n" << endl;

		user1.addDevice(device1);
		user1.addDevice(device2);
		user2.addDevice(device3);
		user2.addDevice(device4);
		user3.addDevice(device5);
		user3.addDevice(device6);
		user4.addDevice(device7);
		user4.addDevice(device8);
		user5.addDevice(device9);
		user5.addDevice(device10);
		user6.addDevice(device11);
		user6.addDevice(device12);

		cout << "\033[1;32mOK\033[0m\n \n" << endl;

		Profile profile1;
		Profile profile2;
		Profile profile3;
		Profile profile4;
		Profile profile5;
		Profile profile6;
		
		try
		{
			cout <<
				"Creating a profile for each user with empty status and posts: ... \n" << endl;
		
			profile1.init(user1);
			profile2.init(user2);
			profile3.init(user3);
			profile4.init(user4);
			profile5.init(user5);
			profile6.init(user6);
		
			std::string expected = "";
			expected += "Owner: [ID: 123456789, Username: Gal, Age: 17, All devices On: Yes]\n";
			expected += "Gal's page:\nStatus: \n*******************\n*******************\n";
			expected += "Owner: [ID: 987654321, Username: Avi, Age: 15, All devices On: Yes]\n";
			expected += "Avi's page:\nStatus: \n*******************\n*******************\n";
			expected += "Owner: [ID: 135792486, Username: Tom, Age: 12, All devices On: Yes]\n";
			expected += "Tom's page:\nStatus: \n*******************\n*******************\n";
			expected += "Owner: [ID: 123456789, Username: Nitzan, Age: 12, All devices On: Yes]\n";
			expected += "Nitzan's page:\nStatus: \n*******************\n*******************\n";
			expected += "Owner: [ID: 111222333, Username: Shlomo, Age: 14, All devices On: Yes]\n";
			expected += "Shlomo's page:\nStatus: \n*******************\n*******************\n";
			expected += "Owner: [ID: 222444666, Username: Rinat, Age: 16, All devices On: Yes]\n";
			expected += "Rinat's page:\nStatus: \n*******************\n*******************\n";
			std::string got =
				getProfileString(profile1) +
				getProfileString(profile2) +
				getProfileString(profile3) +
				getProfileString(profile4) +
				getProfileString(profile5) +
				getProfileString(profile6);
		
			if (got == expected)
			{
				cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
			}
			else
			{
				cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
				cout << "Expected:\n" << expected << endl;
				cout << "Got:\n" << got << endl;
				system("./printMessage 2301");
				cout << " \n" << endl;
				return 2301;
			}
		
		}
		catch (...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2301");
			cout << " \n" << endl;
			return 2301;
		}

		SocialNetwork sn;
		try
		{
			cout << "Creating a social network with minimal age of 13 ... \n" << endl;
			sn.init("Magshimim Network", 13);

		}
		catch (...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2201");
			cout << " \n" << endl;
			return 2401;
		}

		expected = "[Name: Magshimim Network, Minimal Age: 13]";
		got = "[Name: " + sn.getNetworkName();
		got += ", Minimal Age: " + std::to_string(sn.getMinAge()) + "]";


		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected:\n" << expected << endl;
			cout << "Got:\n" << got << endl;
			system("./printMessage 2401");
			cout << " \n" << endl;
			return 2401;
		}

		cout <<
			"\nTrying to add all profiles to social network ... \n" << endl;

		const std::string ADDED_SUCCESSFULLY = "\033[1;33mAdded Successfully\033[0m\n \n";
		const std::string TOO_YOUNG = "\033[1;34mCannot add because user is too young\033[0m\n \n";

		std::cout << "profile1 " <<
			(sn.addProfile(profile1) ? ADDED_SUCCESSFULLY : TOO_YOUNG);
		std::cout << "profile2 " <<
			(sn.addProfile(profile2) ? ADDED_SUCCESSFULLY : TOO_YOUNG);
		std::cout << "profile3 " <<
			(sn.addProfile(profile3) ? ADDED_SUCCESSFULLY : TOO_YOUNG);
		std::cout << "profile4 " <<
			(sn.addProfile(profile4) ? ADDED_SUCCESSFULLY : TOO_YOUNG);
		std::cout << "profile5 " <<
			(sn.addProfile(profile5) ? ADDED_SUCCESSFULLY : TOO_YOUNG);
		std::cout << "profile6 " <<
			(sn.addProfile(profile6) ? ADDED_SUCCESSFULLY : TOO_YOUNG);

		cout <<
			"\nAdding friends (all to all): ... \n" << endl;
		Profile* profiles[] = { (&profile1), (&profile2), &profile3, (&profile4), (&profile5) , (&profile6) };
		allFriends(profiles, 6);

		cout << "\033[1;32mOK\033[0m\n \n" << endl;

		cout <<
			"Printing devices that runs Windows OS: ... \n" << endl;

		// Checks for devices initialized in 152-163, not including device6 because they're 12 years old
		expected = "[2123, Windows11], [1121, Windows10], [7711, Windows11], [9444, Windows11]";
		got = sn.getWindowsDevices();

		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected:\n" << expected << endl;
			cout << "Got:\n" << got << endl;
			system("./printMessage 2402");
			cout << " \n" << endl;
			return 2402;
		}

		cout <<
			"Calling clear for each User object: ... \n" << endl;
		cout << "Running Test ... \t";
			
		try
		{
						
			user1.clear();
			user2.clear();
			user3.clear();
			user4.clear();
			user5.clear();
			user6.clear();
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
			
		cout <<
			"Calling clear for each Profile object: ... \n" << endl;
		cout << "Running Test ... \t";
			
		try
		{
			profile1.clear();
			profile2.clear();
			profile3.clear();
			profile4.clear();
			profile5.clear();
			profile6.clear();
		}
		catch (const std::exception& e)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2307");
			cout << " \n " << endl;
			cout << "Received the following error: " << e.what() << "\n"
				<< " \n " << endl;
			return 2307;
		}
		catch (...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2307");
			cout << " \n " << endl;
			return 2307;
		}
		cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;

		cout <<
			"\nClearing SocialNetwork object: ... \n" << endl;
		cout << "Running Test ... \t";

		try
		{
			sn.clear();
		}
		catch (const std::exception& e)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2403");
			cout << " \n " << endl;
			cout << "Received the following error: " << e.what() << "\n"
				<< " \n " << endl;
			return 2403;
		}
		catch (...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2403");
			cout << " \n " << endl;
			return 2403;
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

std::string goodJob()
{
	std::string result = "";
	result += "  ________                  .___      ____.     ___.    \n";
	result += " /  _____/  ____   ____   __| _/     |    | ____\\_ |__  \n";
	result += "/   \\  ___ /  _ \\ /  _ \\ / __ |      |    |/  _ \\| __ \\ \n";
	result += "\\    \\_\\  (  <_> |  <_> ) /_/ |  /\\__|    (  <_> ) \\_\\ \\ \n";
	result += " \\______  /\\____/ \\____/\\____ |  \\________|\\____/|___  / \n";
	result += "        \\/                   \\/                      \\/  \n";

	return result;
}

int main(int argc, char* argv[])
{
	std::cout <<
		"###########################\n" <<
		"Exercise 2 - Social Network\n" <<
		"###########################\n" << std::endl;

		bool result = test4SocialNetwork();
		if (result == 0)
		{
			cout << goodJob();
		}
		cout << (result == 0 ? "\033[1;32m \n****** Ex2 Part 4 Bonus Tests Passed ******\033[0m\n \n" : "\033[1;31mEx2 Part 4 Bonus Tests Failed\033[0m\n \n") << endl;
		return result;
}
