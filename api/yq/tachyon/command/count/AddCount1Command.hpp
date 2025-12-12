////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddCount¹Command : public CountCommand {
        YQ_OBJECT_DECLARE(AddCount¹Command, CountCommand)
    public:
        AddCount¹Command(const Header&, const Vector1D&);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        unsigned  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddCount¹Command();
        AddCount¹Command(const AddCount¹Command&, const Header&);
        AddCount¹Command(const Header&);

    private:
        Vector1D  m_Δ = ZERO;
        
        AddCount¹Command(const AddCount¹Command&) = delete;
        AddCount¹Command(AddCount¹Command&&) = delete;
        AddCount¹Command& operator=(const AddCount¹Command&) = delete;
        AddCount¹Command& operator=(AddCount¹Command&&) = delete;
    };
}
