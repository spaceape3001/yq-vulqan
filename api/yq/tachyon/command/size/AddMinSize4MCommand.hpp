////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/unit/declare.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize⁴MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize⁴MCommand, SizeCommand)
    public:
        AddMinSize⁴MCommand(const Header&, const Size4D&);
    
        const Size4D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }
        Meter  Δz() const { return m_Δ.z; }
        Meter  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSize⁴MCommand(const AddMinSize⁴MCommand&, const Header&);
        AddMinSize⁴MCommand(const Header&);
        ~AddMinSize⁴MCommand();

    private:
        Size4D  m_Δ = ZERO;
        
        AddMinSize⁴MCommand(const AddMinSize⁴MCommand&) = delete;
        AddMinSize⁴MCommand(AddMinSize⁴MCommand&&) = delete;
        AddMinSize⁴MCommand& operator=(const AddMinSize⁴MCommand&) = delete;
        AddMinSize⁴MCommand& operator=(AddMinSize⁴MCommand&&) = delete;
    };
}
