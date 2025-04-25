////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddScale¹ : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScale¹, ScaleCommand)
    public:
        AddScale¹(const Header&, const Vector1D&);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddScale¹();
        AddScale¹(const AddScale¹&, const Header&);
        AddScale¹(const Header&);

    private:
        Vector1D  m_Δ = ZERO;
        
        AddScale¹(const AddScale¹&) = delete;
        AddScale¹(AddScale¹&&) = delete;
        AddScale¹& operator=(const AddScale¹&) = delete;
        AddScale¹& operator=(AddScale¹&&) = delete;
    };
}
