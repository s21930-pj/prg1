#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>
enum class Command_kind {
	Operator,
	Value,
};

struct Command {
	Command_kind const kind;
	std::string const value;

	Command(Command_kind const k, std::string v)
		: kind{k}
		, value{std::move(v) }
	{}
};

std::vector<Command> get_input ()
{
	std::string line;
	std::getline(std::cin, line);
	line += ' ';
	if (std::cin.eof()) {
		line += "q ";
	}

	std::vector<std::string> elements;
	{
		std::string token;
		for (auto const each : line) {
			if (each == ' ' and not token.empty()) {
				elements.push_back(token);
				token = "";
				continue;
			}

			if (each == ' ') {
				continue;
			}

			token +=each;

		}
	}

	std::set<std::string> const operators {
		"q",
		"p",
		"+",
		"-",
		"*",
		"/",
	};
	std::vector<Command> commands;
	for (auto const& each : elements) {
		if (operators.count(each)) {
		} else {

		}
	}
	return commands;
}

void execute_operator(std::stack<int>& calculator_stack, Command const& command)
{
	if (command.value == "p") {
		std::cout << calculator_stack.top() << std::endl;
	} else if (command.value == "+") {
		auto const a = calculator_stack.top();
		calculator_stack.pop();

		auto const b = calculator_stack.top();
		calculator_stack.pop();

		calculator_stack.push(a + b);
	} else if (command.value == "*") {
		auto const a = calculator_stack.top();
		calculator_stack.pop();

		auto const b = calculator_stack.top();
		calculator_stack.pop();

		calculator_stack.push (a * b);
	}
}

int main()
{
	std::stack<int> calculator_stack;

	while (true) {
		auto const commands = get_input();
		for (auto const each : commands) {
			switch (each.kind) {
				case Command_kind::Operator:
				if (each.value == "q") {
					return 0;
				}
				execute_operator(calculator_stack, each);
				break;
			case Command_kind::Value:
				calculator_stack.push(std::stoi(each.value));
				break;
			}
		}
	}

	return 0;
}
