////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddSize⁴DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize⁴DCommand, SizeCommand)
    public:
        AddSize⁴DCommand(const Header&, const Size4D&);
    
        const Size4D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        double  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSize⁴DCommand(const AddSize⁴DCommand&, const Header&);
        AddSize⁴DCommand(const Header&);
        ~AddSize⁴DCommand();

    private:
        Size4D  m_Δ = ZERO;
        
        AddSize⁴DCommand(const AddSize⁴DCommand&) = delete;
        AddSize⁴DCommand(AddSize⁴DCommand&&) = delete;
        AddSize⁴DCommand& operator=(const AddSize⁴DCommand&) = delete;
        AddSize⁴DCommand& operator=(AddSize⁴DCommand&&) = delete;
    };
}
