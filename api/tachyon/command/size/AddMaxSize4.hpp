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
    class AddMaxSize⁴ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize⁴, SizeCommand)
    public:
        AddMaxSize⁴(const Header&, const Vector4D&);
    
        const Vector4D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        double  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSize⁴(const AddMaxSize⁴&, const Header&);
        AddMaxSize⁴(const Header&);
        ~AddMaxSize⁴();

    private:
        Vector4D  m_Δ = ZERO;
        
        AddMaxSize⁴(const AddMaxSize⁴&) = delete;
        AddMaxSize⁴(AddMaxSize⁴&&) = delete;
        AddMaxSize⁴& operator=(const AddMaxSize⁴&) = delete;
        AddMaxSize⁴& operator=(AddMaxSize⁴&&) = delete;
    };
}
