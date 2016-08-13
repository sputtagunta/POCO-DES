//
// DES - Discrete Event Simulator
// 

#include "Poco/Util/Application.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/AbstractConfiguration.h"
#include "Poco/AutoPtr.h"
#include "Poco/Runnable.h"
#include "Poco/ThreadPool.h"

#include "common/handle_config.h"
#include "common/event_loop.h"

#include <curl/curl.h>
#include <json/json.h>
#include <iostream>
#include <sstream>


using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::Util::AbstractConfiguration;
using Poco::Util::OptionCallback;
using Poco::AutoPtr;


class DES: public Application {

public:
    DES(): _helpRequested(true) {
    }

protected:
    void initialize(Application& self) {
        // add your own initialization code here
        Application::initialize(self);
    }

    void uninitialize() {
        // add your own uninitialization code here
        Application::uninitialize();
    }

    void reinitialize(Application& self) {
        // add your own reinitialization code here
        Application::reinitialize(self);
    }

    void defineOptions(OptionSet& options) {
        Application::defineOptions(options);

        options.addOption(
            Option("help", "h", "display help information on command line arguments")
                .required(false)
                .repeatable(false)
                .callback(OptionCallback<DES>(this, &DES::handleHelp)));

        options.addOption(
            Option("config", "c", "load configuration data from a path (file or url)")
                .required(false)
                .repeatable(false)
                .argument("path")
                .callback(OptionCallback<DES>(this, &DES::handleConfig)));
    }

    void handleHelp(const std::string& name, const std::string& value) {
        _helpRequested = false;
        displayHelp();
        stopOptionsProcessing();
    }

    void handleConfig(const std::string& name, const std::string& value) {
        this->_config = read_config(value);
        _helpRequested = false;
    }

    void displayHelp() {
        HelpFormatter helpFormatter(options());
        helpFormatter.setCommand(commandName());
        helpFormatter.setUsage("OPTIONS");
        helpFormatter.setHeader("A discrete event simulator that utilizes the POCO framework");
        helpFormatter.format(std::cout);
    }

    int main(const ArgVec& args) {
        if (_helpRequested) {
            displayHelp();
        } else {
            printf("Loading configuration file:\n");
            printf("%s", this->_config.toStyledString().c_str());
            
            event_loop discrete_event_simulation(this->_config);
            Poco::ThreadPool threadpool;

            threadpool.start(discrete_event_simulation);

            threadpool.joinAll();
    

        }

        return Application::EXIT_OK;
    }

private:
    bool _helpRequested;
    Json::Value _config;
};


POCO_APP_MAIN(DES)
