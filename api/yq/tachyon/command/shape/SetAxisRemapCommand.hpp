////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ShapeCommand.hpp>
#include <yq/tachyon/enum/AxisRemap.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetAxisRemapCommand : public ShapeCommand {
        YQ_OBJECT_DECLARE(SetAxisRemapCommand, ShapeCommand)
    public:
    
        static void init_meta();
        SetAxisRemapCommand(const Header&, AxisRemap);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        AxisRemap    axis_remap() const { return m_axisRemap; }
        
    protected:
        SetAxisRemapCommand(const SetAxisRemapCommand&, const Header&);
        ~SetAxisRemapCommand();
        
    private:
        AxisRemap    m_axisRemap;
    
        SetAxisRemapCommand(const SetAxisRemapCommand&) = delete;
        SetAxisRemapCommand(SetAxisRemapCommand&&) = delete;
        SetAxisRemapCommand& operator=(const SetAxisRemapCommand&) = delete;
        SetAxisRemapCommand& operator=(SetAxisRemapCommand&&) = delete;
    };
}
