////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddSize⁴Command : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize⁴Command, SizeCommand)
    public:
        AddSize⁴Command(const Header&, const Vector4D&);
    
        const Vector4D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        double  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSize⁴Command(const AddSize⁴Command&, const Header&);
        AddSize⁴Command(const Header&);
        ~AddSize⁴Command();

    private:
        Vector4D  m_Δ = ZERO;
        
        AddSize⁴Command(const AddSize⁴Command&) = delete;
        AddSize⁴Command(AddSize⁴Command&&) = delete;
        AddSize⁴Command& operator=(const AddSize⁴Command&) = delete;
        AddSize⁴Command& operator=(AddSize⁴Command&&) = delete;
    };
}
