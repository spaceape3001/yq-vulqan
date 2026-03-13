////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddCount⁴Command : public CountCommand {
        YQ_OBJECT_DECLARE(AddCount⁴Command, CountCommand)
    public:
        AddCount⁴Command(const Header&, const Vector4U&);
    
        const Vector4U&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        unsigned  Δx() const { return m_Δ.x; }
        unsigned  Δy() const { return m_Δ.y; }
        unsigned  Δz() const { return m_Δ.z; }
        unsigned  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddCount⁴Command(const AddCount⁴Command&, const Header&);
        AddCount⁴Command(const Header&);
        ~AddCount⁴Command();

    private:
        Vector4U  m_Δ = ZERO;
        
        AddCount⁴Command(const AddCount⁴Command&) = delete;
        AddCount⁴Command(AddCount⁴Command&&) = delete;
        AddCount⁴Command& operator=(const AddCount⁴Command&) = delete;
        AddCount⁴Command& operator=(AddCount⁴Command&&) = delete;
    };
}
