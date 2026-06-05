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
    class AddSize⁴CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize⁴CMCommand, SizeCommand)
    public:
        AddSize⁴CMCommand(const Header&, const Size4CM&);
    
        const Size4CM&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        Centimeter  Δy() const { return m_Δ.y; }
        Centimeter  Δz() const { return m_Δ.z; }
        Centimeter  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSize⁴CMCommand(const AddSize⁴CMCommand&, const Header&);
        AddSize⁴CMCommand(const Header&);
        ~AddSize⁴CMCommand();

    private:
        Size4CM  m_Δ = ZERO;
        
        AddSize⁴CMCommand(const AddSize⁴CMCommand&) = delete;
        AddSize⁴CMCommand(AddSize⁴CMCommand&&) = delete;
        AddSize⁴CMCommand& operator=(const AddSize⁴CMCommand&) = delete;
        AddSize⁴CMCommand& operator=(AddSize⁴CMCommand&&) = delete;
    };
}
