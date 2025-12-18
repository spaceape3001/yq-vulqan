////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Tristate.hpp>
#include <yq/tachyon/command/ShapeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetAutoCenterCommand : public ShapeCommand {
        YQ_OBJECT_DECLARE(SetAutoCenterCommand, ShapeCommand)
    public:
    
        static void init_meta();
        SetAutoCenterCommand(const Header&, Tristate);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        Tristate    auto_center() const { return m_autoCenter; }
        
    protected:
        SetAutoCenterCommand(const SetAutoCenterCommand&, const Header&);
        ~SetAutoCenterCommand();
        
    private:
        Tristate    m_autoCenter;
    
        SetAutoCenterCommand(const SetAutoCenterCommand&) = delete;
        SetAutoCenterCommand(SetAutoCenterCommand&&) = delete;
        SetAutoCenterCommand& operator=(const SetAutoCenterCommand&) = delete;
        SetAutoCenterCommand& operator=(SetAutoCenterCommand&&) = delete;
    };
}
