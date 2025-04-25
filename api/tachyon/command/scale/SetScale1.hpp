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
    class SetScale¹ : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScale¹, ScaleCommand)
    public:
        SetScale¹(const Header&, const Vector1D&);
    
        const Vector1D&   scale() const  { return m_scale; }
        
        static void init_info();
        
        double  x() const { return m_scale.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetScale¹();
        SetScale¹(const SetScale¹&, const Header&);
    

    private:
        Vector1D  m_scale;
        
        SetScale¹(const SetScale¹&) = delete;
        SetScale¹(SetScale¹&&) = delete;
        SetScale¹& operator=(const SetScale¹&) = delete;
        SetScale¹& operator=(SetScale¹&&) = delete;
    };
}
