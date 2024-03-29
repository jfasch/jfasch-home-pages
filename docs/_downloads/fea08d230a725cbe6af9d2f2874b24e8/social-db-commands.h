#pragma once

#include <socialdb.h>

#include <string>
#include <variant>
#include <optional>
#include <tuple>
#include <vector>


class SocialDBCommand
{
public:
    virtual ~SocialDBCommand() {}
    virtual void execute(SocialDB&) = 0;
};

class SocialDBInsertCommand : public SocialDBCommand
{
public:
    SocialDBInsertCommand(
        const std::string& svnr, 
        const std::string& firstname, 
        const std::string& lastname)
    : _svnr(svnr),
      _firstname(firstname),
      _lastname(lastname) {}

    virtual void execute(SocialDB&) override;
    void result() const;

private:
    std::string _svnr;
    std::string _firstname;
    std::string _lastname;

    std::optional<SocialDB::NotInserted> _error;
};

class SocialDBFindCommand : public SocialDBCommand
{
public:
    SocialDBFindCommand(const std::string& svnr) : _svnr(svnr) {}

    virtual void execute(SocialDB&) override;
    SocialDB::Person result() const;

private:
    std::string _svnr;
    std::variant<SocialDB::Person, SocialDB::NotFound> _result;
};

class SocialDBDropCommand : public SocialDBCommand
{
public:
    virtual void execute(SocialDB&) override;
    void result() const {}
};

class SocialDBBulkInsertCommand : public SocialDBCommand
{
public:
    SocialDBBulkInsertCommand() = default;
    SocialDBBulkInsertCommand(std::initializer_list<std::tuple<std::string, std::string, std::string>>);

    void add(const SocialDBInsertCommand&);
    virtual void execute(SocialDB&) override;

private:
    std::vector<SocialDBInsertCommand> _commands;
};
