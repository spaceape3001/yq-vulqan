////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/TachyonCommand.hpp>
#include <tachyon/typedef/tachyon.hpp>

namespace yq::tachyon {
    class SetParentCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetParentCommand, TachyonCommand)
    public:
        SetParentCommand(const Header&, TachyonSpec);

        const TachyonSpec&   parent() const { return m_parent; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        static void init_info();
        
    protected:
        SetParentCommand(const SetParentCommand&, const Header&);
        virtual ~SetParentCommand();
    
    private:
        TachyonSpec m_parent;
        
        SetParentCommand(const SetParentCommand&) = delete;
        SetParentCommand(SetParentCommand&&) = delete;
        SetParentCommand& operator=(const SetParentCommand&) = delete;
        SetParentCommand& operator=(SetParentCommand&&) = delete;
    };
}
