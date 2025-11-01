////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize⁴Command : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize⁴Command, SizeCommand)
    public:
        AddMinSize⁴Command(const Header&, const Vector4D&);
    
        const Vector4D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        double  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSize⁴Command(const AddMinSize⁴Command&, const Header&);
        AddMinSize⁴Command(const Header&);
        ~AddMinSize⁴Command();

    private:
        Vector4D  m_Δ = ZERO;
        
        AddMinSize⁴Command(const AddMinSize⁴Command&) = delete;
        AddMinSize⁴Command(AddMinSize⁴Command&&) = delete;
        AddMinSize⁴Command& operator=(const AddMinSize⁴Command&) = delete;
        AddMinSize⁴Command& operator=(AddMinSize⁴Command&&) = delete;
    };
}
