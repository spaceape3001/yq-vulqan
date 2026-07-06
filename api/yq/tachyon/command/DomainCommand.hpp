////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class DomainCommand : public Command {
        YQ_OBJECT_DECLARE(DomainCommand, Command)
    public:
    
        static void init_meta();

    protected:
        DomainCommand(const Header&);
        DomainCommand(const DomainCommand&, const Header&);
        ~DomainCommand();
        
    private:
        DomainCommand(const DomainCommand&) = delete;
        DomainCommand(DomainCommand&&) = delete;
        DomainCommand& operator=(const DomainCommand&) = delete;
        DomainCommand& operator=(DomainCommand&&) = delete;
    };
}
