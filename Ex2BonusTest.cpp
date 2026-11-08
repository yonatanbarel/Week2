#include <iostream>
#include <random>

#include "Profile.h"

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

bool checkAllWordsAreAlikeInStatus(std::string str)
{
	const std::string word = "Magshimim";
	int pos = -1;

	// removes seperators

	while ((pos = str.find('\n')) != std::string::npos)
		str.replace(pos, 1, "");

	while ((pos = str.find(' ')) != std::string::npos)
		str.replace(pos, 1, "");

	while ((pos = str.find('\t')) != std::string::npos)
		str.replace(pos, 1, "");

	// removes all the instances of the word
	while ((pos = str.find(word)) != std::string::npos)
		str.replace(pos, word.length(), "");

	// if any characters left, return false
	if (str.length() != 0)
		return false;

	return true;
}

bool checkWordDoesNotExistInStatus(std::string status, const std::string& word)
{
	return status.find(word) == std::string::npos;
}

int test3Bonus()
{
	// Tests Ex2 part 3 - Profile
	cout <<
		"****************************\n" <<
		"Test 3 Bonus - Word Change				\n" <<
		"****************************\n" << endl;
	try
	{
		Device device1;
		Device device2;

		std::string expected;
		std::string got;

		try
		{
			cout <<
				" \nInitializing 2 Devices: \n" << endl;
				
			device1.init(2123, LAPTOP, WINDOWS11);
			device2.init(3212, PC, UbuntuOS);
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

		try
		{
			cout <<
				"Initializing user1 - [ID = 123456789, Name: Gal, Age: 17] ... \n" << endl;

			user1.init(123456789, "Gal", 17);
		}
		catch (...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2201");
			cout << " \n" << endl;
			return 2201;
		}

		cout << "\033[1;32mOK\033[0m\n \n" << endl;
	
	
		Profile profile1;

		try
		{
			cout <<
				"Creating a profile for user1 with random status and posts ... \n" << endl;

			profile1.init(user1);
			generateRandomPage(profile1);
			std::string got = getProfileString(profile1);
			cout << got << endl;
		}
		catch (...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2301");
			cout << " \n" << endl;
			return 2301;
		}

		cout << "\033[1;32mOK\033[0m\n \n" << endl;

		cout <<
			"Changing all words in the status to \"Magshimim\": ... \n" << endl;
		profile1.changeAllWordsInStatus("Magshimim");
		got = getProfileString(profile1);
		cout << got << endl;

		// cutting the status out of the page
		std::string statusToCheck = profile1.getPage();
		statusToCheck = statusToCheck.substr(8, statusToCheck.length());
		statusToCheck = statusToCheck.substr(0, statusToCheck.find_first_of('\n'));

		// if there is one word that is different from the other return false
		if (checkAllWordsAreAlikeInStatus(statusToCheck) == true)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Got:\n" << got << endl;
			system("./printMessage 2311");
			cout << " \n" << endl;
			return 2311;
		}

		User user2;

		try
		{
			cout <<
				"Initializing user2 - [ID = 111222333, Name: Nitzan, Age: 12] ... \n" << endl;

			user2.init(111222333, "Nitzan", 12);
		}
		catch (...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2201");
			cout << " \n" << endl;
			return 2201;
		}

		cout << "\033[1;32mOK\033[0m\n \n" << endl;

		Profile profile2;

		try
		{
			cout <<
				"Creating a profile for user2 with random status and posts ... \n" << endl;

			profile2.init(user2);
			generateRandomPage(profile2);
			got = getProfileString(profile2);
			cout << got << endl;
		}
		catch (...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			system("./printMessage 2301");
			cout << " \n" << endl;
			return 2301;
		}

		cout << "\033[1;32mOK\033[0m\n \n" << endl;

		std::string word_to_replace = "you";
		std::string replacement = "MMMMMMMMMM";

		cout <<
			"Changing the word \"" << word_to_replace << "\" in the status to \"" << replacement << "\": ... \n" << endl;
		profile2.changeWordInStatus(word_to_replace, replacement);
		got = getProfileString(profile2);
		cout << got << endl;

		// cutting the status out of the page
		statusToCheck = profile2.getPage();
		statusToCheck = statusToCheck.substr(8, statusToCheck.length());
		statusToCheck = statusToCheck.substr(0, statusToCheck.find_first_of('\n'));

		// checks that the word is not in the status
		if (checkWordDoesNotExistInStatus(statusToCheck, word_to_replace) == true)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "The word \"" << word_to_replace << "\" appers in the status" << endl;
			cout << "Got:\n" << got << endl;
			system("./printMessage 2312");
			cout << " \n" << endl;
			return 2312;
		}

		cout <<
			"Calling clear for each User object: ... \n" << endl;
		cout << "Running Test ... \t";
	
		try
		{
				
			user1.clear();
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
	
		cout <<
			"Calling clear for each Profile object: ... \n" << endl;
		cout << "Running Test ... \t";
	
		try
		{
			profile1.clear();
			profile2.clear();
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

	}
	catch (...)
	{
		std::cerr << "Test crashed" << endl;
		std::cout << "FAILED: The program crashed, check the following things:\n" <<
			"1. Did you delete a pointer twice?\n2. Did you accesse index out of bounds?\n" <<
			"3. Did you remember to initialize the lists before using them?";
		return 2;
	}

	return 0;
}

int main()
{
	std::cout <<
		"###########################\n" <<
		"Exercise 2 - Social Network\n" <<
		"Bonus\n" <<
		"###########################\n" << std::endl;

	int BonusResult = test3Bonus();

	cout << (BonusResult == 0 ? "\033[1;32m \n****** Ex2 Part 3 Bonus Tests Passed ******\033[0m\n \n" : "\033[1;31mEx2 Part 3 Bonus Tests Failed\033[0m\n \n") << endl;


	return BonusResult ;
}