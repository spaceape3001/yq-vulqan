////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyScale¹ : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScale¹, ScaleCommand)
    public:
        MultiplyScale¹(const Header&, const Vector1D&);
    
        const Vector1D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplyScale¹();
        MultiplyScale¹(const MultiplyScale¹&, const Header&);
        MultiplyScale¹(const Header&);
    

    private:
        Vector1D  m_δ;
        
        MultiplyScale¹(const MultiplyScale¹&) = delete;
        MultiplyScale¹(MultiplyScale¹&&) = delete;
        MultiplyScale¹& operator=(const MultiplyScale¹&) = delete;
        MultiplyScale¹& operator=(MultiplyScale¹&&) = delete;
    };
}
