#include "monkey.hpp"
namespace Monkey
{
        LoggingDaemon *LoggingDaemon::instance = nullptr;
        LoggingDaemon::LoggingDaemon()
        {
                this->enabledAuth = true;
                this->enabledAction = true;
                this->enabledAdminActions = true;
        }

        LoggingDaemon::~LoggingDaemon()
        {
        }

        LoggingDaemon *LoggingDaemon::getInstance()
        {
                if (instance == nullptr)
                {
                        instance = new LoggingDaemon();
                }
                return instance;
        }

        void LoggingDaemon::destroyDaemon()
        {
                if (instance)
                        delete instance;
                instance = nullptr;
        }

        void LoggingDaemon::logAction(const std::string &action) {}
        void LoggingDaemon::logAuth(User *user, const std::string &action) {}
        void LoggingDaemon::logAdminAction(User *user, const std::string &action) {}

        bool LoggingDaemon::getEnabledAction() { return this->enabledAction; }
        bool LoggingDaemon::getEnabledAuth() { return this->enabledAuth; }
        bool LoggingDaemon::getEnabledAdminAction() { return this->enabledAdminActions; }

        void LoggingDaemon::setEnabledAction(bool value) { this->enabledAction = value; }
        void LoggingDaemon::setEnabledAuth(bool value) { this->enabledAuth = value; }
        void LoggingDaemon::setEnabledAdminAction(bool value) { this->enabledAdminActions = value; }

}
