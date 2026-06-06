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
    class AddMaxSize⁴MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize⁴MCommand, SizeCommand)
    public:
        AddMaxSize⁴MCommand(const Header&, const Size4M&);
    
        const Size4M&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }
        Meter  Δz() const { return m_Δ.z; }
        Meter  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSize⁴MCommand(const AddMaxSize⁴MCommand&, const Header&);
        AddMaxSize⁴MCommand(const Header&);
        ~AddMaxSize⁴MCommand();

    private:
        Size4M  m_Δ = ZERO;
        
        AddMaxSize⁴MCommand(const AddMaxSize⁴MCommand&) = delete;
        AddMaxSize⁴MCommand(AddMaxSize⁴MCommand&&) = delete;
        AddMaxSize⁴MCommand& operator=(const AddMaxSize⁴MCommand&) = delete;
        AddMaxSize⁴MCommand& operator=(AddMaxSize⁴MCommand&&) = delete;
    };
}
