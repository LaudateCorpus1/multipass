/*
 * Copyright (C) 2017 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MULTIPASS_HELP_H
#define MULTIPASS_HELP_H

#include <multipass/cli/command.h>

namespace multipass
{
namespace cmd
{
class Help final : public Command
{
public:
    Help(grpc::Channel& channel, Rpc::Stub& stub, Terminal* term, const std::string& str1, const std::string& str2)
        : Command(channel, stub, term)
    {
        term->cout() << str1 << str2;
    }

    ReturnCode run(ArgParser *parser) override;

    std::string name() const override;
    QString short_help() const override;
    QString description() const override;

private:
    QString command;

    ParseCode parse_args(ArgParser *parser) override;
};
}
}
#endif // MULTIPASS_HELP_H
