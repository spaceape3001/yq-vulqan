////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize¹Command : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize¹Command, SizeCommand)
    public:
        AddMinSize¹Command(const Header&, const Vector1D&);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddMinSize¹Command();
        AddMinSize¹Command(const AddMinSize¹Command&, const Header&);
        AddMinSize¹Command(const Header&);

    private:
        Vector1D  m_Δ = ZERO;
        
        AddMinSize¹Command(const AddMinSize¹Command&) = delete;
        AddMinSize¹Command(AddMinSize¹Command&&) = delete;
        AddMinSize¹Command& operator=(const AddMinSize¹Command&) = delete;
        AddMinSize¹Command& operator=(AddMinSize¹Command&&) = delete;
    };
}
