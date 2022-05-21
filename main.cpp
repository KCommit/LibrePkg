#include <CommandLine.hpp>
#include <iostream>
#include <map>
#include <string>

class DefaultAction : public cl::Action {
  public:
    DefaultAction() {}
    void execute() override { std::cout << "Test Command" << std::endl; }

  private:
};

int main(int argc, char **argv) {
    cl::CommandLine commandLine(argc, argv);
    cl::Command *defaultCommand = new cl::Command("");
    DefaultAction *defaultAction = new DefaultAction();
    defaultCommand->addAction(defaultAction);
    commandLine.setDefaultCommand(defaultCommand);
    commandLine.execute();
    return 0;
}
