////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyScale¹Command : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScale¹Command, ScaleCommand)
    public:
        MultiplyScale¹Command(const Header&, const Vector1D&);
    
        const Vector1D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplyScale¹Command();
        MultiplyScale¹Command(const MultiplyScale¹Command&, const Header&);
        MultiplyScale¹Command(const Header&);
    

    private:
        Vector1D  m_δ;
        
        MultiplyScale¹Command(const MultiplyScale¹Command&) = delete;
        MultiplyScale¹Command(MultiplyScale¹Command&&) = delete;
        MultiplyScale¹Command& operator=(const MultiplyScale¹Command&) = delete;
        MultiplyScale¹Command& operator=(MultiplyScale¹Command&&) = delete;
    };
}
