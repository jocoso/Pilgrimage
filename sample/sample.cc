#include <iostream>
#include <regex>
#include <string>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

namespace constants 
{
	const std::chrono::seconds nd_pause(3); // Pause between dialogue lines. 
	const char separator = ':'; 
	const string tought_prompt = "Write a though";
	const string tab = "====================";
	
}

struct Player {
	vector<string> commands_known;
} player;

// Prototypes
void wait();
void say(const string& message);
void looped_instruct(string message, string raw_pattern, string on_fail_msg);
bool single_instruct(string message, string raw_pattern);
void focus_command();
void kick_command();


int main() 
{
	const string on_fail("A thought confuses you, you don't react.");
	
	// Introduction
	say("You are awake...");
	say("The sounds are veiled, yet a heartbeat echoes through.");
	say("The image is indistinct, but shadows loom.");
	say("The skin is fragile, yet beneath lies a gentle caress.");
	say("Your tongue may be barren, yet flavour linger.");
	say("Even if your nose is numb, scents still waft.");
	
	// Focus command tutorial
	say("You know you can 'focus', by merely thinking of it.");
	looped_instruct(constants::tought_prompt, R"(\b(focus)\b)", on_fail);
	player.commands_known.push_back("focus");
	focus_command();
	
	// Kick command tutorial
	say("You know you can 'kick' by merely thinking it.");
	looped_instruct(constants::tought_prompt, R"(\b(kick)\b)", on_fail);
	kick_command();
	
	return 0;
}


void kick_command() 
{
	say("You hear a muffled sound and feel a small pressure to your right.");
}

void focus_command()
{

	say("You focus on yourself...");
	cout << "== COMMANDS KNOWN ==" << endl;
	for(string el : player.commands_known) 
	{
		cout << "- " << el << endl;
	}
	
	while(!single_instruct("You can 'leave' wherever you choose", R"(\b(leave)\b)")) 
	{
		cout << "== COMMANDS KNOWN ==" << endl;
		for(string el : player.commands_known) 
		{
			cout << "- " << el << endl;
		}
		cout << constants::tab << endl;
		
	}
	
}

bool single_instruct(string message, string raw_pattern)
{
	std::regex rx_pattern(raw_pattern);
	
	
	cout << message << constants::separator;
	
	string user_input;
	getline(cin, user_input);
	
	
	return regex_search(user_input, rx_pattern) ? true : false;
}

void looped_instruct(string message, string raw_pattern, string on_fail_msg) 
{
	bool goal_completed = false;
	std::regex rx_pattern(raw_pattern);
	
	// As long as the user_input is different to the expected input,
	// keep repeating the prompt.
	do
	{
		cout << message << constants::separator << ' ';
		cout.flush();
		
		string user_input;
		getline(cin, user_input);
		
		if(regex_search(user_input, rx_pattern)) 
		{
			goal_completed = true;
		} else {
			say(on_fail_msg);
		}
	} while(!goal_completed);
}

void say(const string& message)
{
	cout << message << endl;
	wait();
}

void wait()
{
	std::this_thread::sleep_for(constants::nd_pause);
	
}
