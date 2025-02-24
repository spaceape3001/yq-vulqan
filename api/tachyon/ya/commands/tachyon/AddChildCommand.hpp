////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/TachyonCommand.hpp>
#include <variant>

namespace yq::tachyon {
    class AddChildCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(AddChildCommand, TachyonCommand)
    public:
    
        AddChildCommand(const Header&, TachyonSpec);

        const TachyonSpec&   child() const { return m_child; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        static void init_info();
        
    protected:
        AddChildCommand(const AddChildCommand&, const Header&);
        virtual ~AddChildCommand();
    
    private:
        TachyonSpec m_child;
        
        AddChildCommand(const AddChildCommand&) = delete;
        AddChildCommand(AddChildCommand&&) = delete;
        AddChildCommand& operator=(const AddChildCommand&) = delete;
        AddChildCommand& operator=(AddChildCommand&&) = delete;
    };
}
