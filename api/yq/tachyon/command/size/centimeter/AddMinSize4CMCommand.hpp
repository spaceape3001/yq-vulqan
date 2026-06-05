////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize⁴CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize⁴CMCommand, SizeCommand)
    public:
        AddMinSize⁴CMCommand(const Header&, const Size4CM&);
    
        const Size4CM&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        Centimeter  Δy() const { return m_Δ.y; }
        Centimeter  Δz() const { return m_Δ.z; }
        Centimeter  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSize⁴CMCommand(const AddMinSize⁴CMCommand&, const Header&);
        AddMinSize⁴CMCommand(const Header&);
        ~AddMinSize⁴CMCommand();

    private:
        Size4CM  m_Δ = ZERO;
        
        AddMinSize⁴CMCommand(const AddMinSize⁴CMCommand&) = delete;
        AddMinSize⁴CMCommand(AddMinSize⁴CMCommand&&) = delete;
        AddMinSize⁴CMCommand& operator=(const AddMinSize⁴CMCommand&) = delete;
        AddMinSize⁴CMCommand& operator=(AddMinSize⁴CMCommand&&) = delete;
    };
}
