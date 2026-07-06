////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/DomainCommand.hpp>
#include <yq/tachyon/typedef/domain.hpp>

namespace yq::tachyon {
    class SetDomainCommand : public DomainCommand {
        YQ_OBJECT_DECLARE(SetDomainCommand, DomainCommand)
    public:
        SetDomainCommand(const Header&, DomainID);

        const DomainID&   domain() const { return m_domain; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        static void init_meta();
        
    protected:
        SetDomainCommand(const SetDomainCommand&, const Header&);
        virtual ~SetDomainCommand();
    
    private:
        DomainID m_domain;
        
        SetDomainCommand(const SetDomainCommand&) = delete;
        SetDomainCommand(SetDomainCommand&&) = delete;
        SetDomainCommand& operator=(const SetDomainCommand&) = delete;
        SetDomainCommand& operator=(SetDomainCommand&&) = delete;
    };
}
