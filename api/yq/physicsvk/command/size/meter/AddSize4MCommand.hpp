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
    class AddSize⁴MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize⁴MCommand, SizeCommand)
    public:
        AddSize⁴MCommand(const Header&, const Size4M&);
    
        const Size4M&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }
        Meter  Δz() const { return m_Δ.z; }
        Meter  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSize⁴MCommand(const AddSize⁴MCommand&, const Header&);
        AddSize⁴MCommand(const Header&);
        ~AddSize⁴MCommand();

    private:
        Size4M  m_Δ = ZERO;
        
        AddSize⁴MCommand(const AddSize⁴MCommand&) = delete;
        AddSize⁴MCommand(AddSize⁴MCommand&&) = delete;
        AddSize⁴MCommand& operator=(const AddSize⁴MCommand&) = delete;
        AddSize⁴MCommand& operator=(AddSize⁴MCommand&&) = delete;
    };
}
