////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize¹ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize¹, SizeCommand)
    public:
        AddMinSize¹(const Header&, const Vector1D&);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddMinSize¹();
        AddMinSize¹(const AddMinSize¹&, const Header&);
        AddMinSize¹(const Header&);

    private:
        Vector1D  m_Δ = ZERO;
        
        AddMinSize¹(const AddMinSize¹&) = delete;
        AddMinSize¹(AddMinSize¹&&) = delete;
        AddMinSize¹& operator=(const AddMinSize¹&) = delete;
        AddMinSize¹& operator=(AddMinSize¹&&) = delete;
    };
}
