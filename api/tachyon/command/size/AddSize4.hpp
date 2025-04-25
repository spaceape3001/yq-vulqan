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
    class AddSize⁴ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize⁴, SizeCommand)
    public:
        AddSize⁴(const Header&, const Vector4D&);
    
        const Vector4D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        double  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSize⁴(const AddSize⁴&, const Header&);
        AddSize⁴(const Header&);
        ~AddSize⁴();

    private:
        Vector4D  m_Δ = ZERO;
        
        AddSize⁴(const AddSize⁴&) = delete;
        AddSize⁴(AddSize⁴&&) = delete;
        AddSize⁴& operator=(const AddSize⁴&) = delete;
        AddSize⁴& operator=(AddSize⁴&&) = delete;
    };
}
