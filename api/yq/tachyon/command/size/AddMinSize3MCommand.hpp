////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/unit/declare.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize³MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize³MCommand, SizeCommand)
    public:
        AddMinSize³MCommand(const Header&, const Size3D&);
    
        const Size3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }
        Meter  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSize³MCommand(const AddMinSize³MCommand&, const Header&);
        AddMinSize³MCommand(const Header&);
        ~AddMinSize³MCommand();

    private:
        Size3D  m_Δ = ZERO;
        
        AddMinSize³MCommand(const AddMinSize³MCommand&) = delete;
        AddMinSize³MCommand(AddMinSize³MCommand&&) = delete;
        AddMinSize³MCommand& operator=(const AddMinSize³MCommand&) = delete;
        AddMinSize³MCommand& operator=(AddMinSize³MCommand&&) = delete;
    };
}
