////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMaxSize⁴Command : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize⁴Command, SizeCommand)
    public:
        AddMaxSize⁴Command(const Header&, const Vector4D&);
    
        const Vector4D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        double  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSize⁴Command(const AddMaxSize⁴Command&, const Header&);
        AddMaxSize⁴Command(const Header&);
        ~AddMaxSize⁴Command();

    private:
        Vector4D  m_Δ = ZERO;
        
        AddMaxSize⁴Command(const AddMaxSize⁴Command&) = delete;
        AddMaxSize⁴Command(AddMaxSize⁴Command&&) = delete;
        AddMaxSize⁴Command& operator=(const AddMaxSize⁴Command&) = delete;
        AddMaxSize⁴Command& operator=(AddMaxSize⁴Command&&) = delete;
    };
}
