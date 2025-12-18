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
    class SetNormalizeCommand : public ShapeCommand {
        YQ_OBJECT_DECLARE(SetNormalizeCommand, ShapeCommand)
    public:
    
        static void init_meta();
        SetNormalizeCommand(const Header&, Tristate);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        Tristate    normalize() const { return m_normalize; }
        
    protected:
        SetNormalizeCommand(const SetNormalizeCommand&, const Header&);
        ~SetNormalizeCommand();
        
    private:
        Tristate    m_normalize;
    
        SetNormalizeCommand(const SetNormalizeCommand&) = delete;
        SetNormalizeCommand(SetNormalizeCommand&&) = delete;
        SetNormalizeCommand& operator=(const SetNormalizeCommand&) = delete;
        SetNormalizeCommand& operator=(SetNormalizeCommand&&) = delete;
    };
}
