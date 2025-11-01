////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/RenderedCommand.hpp>
#include <yq/core/Tristate.hpp>

namespace yq::tachyon {
    class SetWireframeCommand : public RenderedCommand {
        YQ_OBJECT_DECLARE(SetWireframeCommand, RenderedCommand)
    public:
        SetWireframeCommand(const Header&, Tristate v);

        Tristate  wireframe() const { return m_wireframe; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        static void init_meta();
        
    protected:
        SetWireframeCommand(const SetWireframeCommand&, const Header&);
        virtual ~SetWireframeCommand();
    
    private:
        Tristate m_wireframe;
        
        SetWireframeCommand(const SetWireframeCommand&) = delete;
        SetWireframeCommand(SetWireframeCommand&&) = delete;
        SetWireframeCommand& operator=(const SetWireframeCommand&) = delete;
        SetWireframeCommand& operator=(SetWireframeCommand&&) = delete;
    };
}
