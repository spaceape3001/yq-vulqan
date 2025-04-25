////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/TachyonCommand.hpp>
#include <variant>

namespace yq::tachyon {
    class RemoveChildCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(RemoveChildCommand, TachyonCommand)
    public:
    
        RemoveChildCommand(const Header&, TachyonSpec);

        const TachyonSpec&   child() const { return m_child; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        static void init_info();
        
    protected:
        RemoveChildCommand(const RemoveChildCommand&, const Header&);
        virtual ~RemoveChildCommand();
    
    private:
        TachyonSpec m_child;
        
        RemoveChildCommand(const RemoveChildCommand&) = delete;
        RemoveChildCommand(RemoveChildCommand&&) = delete;
        RemoveChildCommand& operator=(const RemoveChildCommand&) = delete;
        RemoveChildCommand& operator=(RemoveChildCommand&&) = delete;
    };
}
