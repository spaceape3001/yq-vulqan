////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddScale¹Command : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScale¹Command, ScaleCommand)
    public:
        AddScale¹Command(const Header&, const Vector1D&);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddScale¹Command();
        AddScale¹Command(const AddScale¹Command&, const Header&);
        AddScale¹Command(const Header&);

    private:
        Vector1D  m_Δ = ZERO;
        
        AddScale¹Command(const AddScale¹Command&) = delete;
        AddScale¹Command(AddScale¹Command&&) = delete;
        AddScale¹Command& operator=(const AddScale¹Command&) = delete;
        AddScale¹Command& operator=(AddScale¹Command&&) = delete;
    };
}
