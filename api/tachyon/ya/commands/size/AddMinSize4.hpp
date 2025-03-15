////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize⁴ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize⁴, SizeCommand)
    public:
        AddMinSize⁴(const Header&, const Vector4D&);
    
        const Vector4D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        double  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSize⁴(const AddMinSize⁴&, const Header&);
        AddMinSize⁴(const Header&);
        ~AddMinSize⁴();

    private:
        Vector4D  m_Δ = ZERO;
        
        AddMinSize⁴(const AddMinSize⁴&) = delete;
        AddMinSize⁴(AddMinSize⁴&&) = delete;
        AddMinSize⁴& operator=(const AddMinSize⁴&) = delete;
        AddMinSize⁴& operator=(AddMinSize⁴&&) = delete;
    };
}
