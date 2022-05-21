#ifndef __COMMANDLINE_HPP
#define __COMMANDLINE_HPP
#include <iostream>
#include <map>
#include <string>
namespace cl {
class Action {
  public:
    virtual void execute(){};
    virtual ~Action(){};
    Action(){};
};

class Flag {};
class Command {
  public:
    Command(std::string description) : description(description) {}
    void addAction(Action *action) { this->action = action; }
    void execute() { action->execute(); }

  private:
    std::string description;
    Action *action;
};

class CommandLine {
  public:
    CommandLine(int argc, char **argv) {}
    void execute() {
        if(defaultCommand != nullptr) {
            defaultCommand->execute();
        }
    }
    void setDefaultCommand(Command *command) { defaultCommand = command; }

  private:
    Command *defaultCommand;
    std::map<std::string, Command *> subCommands;
};
}  // namespace cl
#endif
