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
    class AddMaxSize⁴CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize⁴CMCommand, SizeCommand)
    public:
        AddMaxSize⁴CMCommand(const Header&, const Size4CM&);
    
        const Size4CM&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        Centimeter  Δy() const { return m_Δ.y; }
        Centimeter  Δz() const { return m_Δ.z; }
        Centimeter  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSize⁴CMCommand(const AddMaxSize⁴CMCommand&, const Header&);
        AddMaxSize⁴CMCommand(const Header&);
        ~AddMaxSize⁴CMCommand();

    private:
        Size4CM  m_Δ = ZERO;
        
        AddMaxSize⁴CMCommand(const AddMaxSize⁴CMCommand&) = delete;
        AddMaxSize⁴CMCommand(AddMaxSize⁴CMCommand&&) = delete;
        AddMaxSize⁴CMCommand& operator=(const AddMaxSize⁴CMCommand&) = delete;
        AddMaxSize⁴CMCommand& operator=(AddMaxSize⁴CMCommand&&) = delete;
    };
}
