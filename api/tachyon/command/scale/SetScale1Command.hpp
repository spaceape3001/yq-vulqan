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
    class SetScale¹Command : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScale¹Command, ScaleCommand)
    public:
        SetScale¹Command(const Header&, const Vector1D&);
    
        const Vector1D&   scale() const  { return m_scale; }
        
        static void init_info();
        
        double  x() const { return m_scale.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetScale¹Command();
        SetScale¹Command(const SetScale¹Command&, const Header&);
    

    private:
        Vector1D  m_scale;
        
        SetScale¹Command(const SetScale¹Command&) = delete;
        SetScale¹Command(SetScale¹Command&&) = delete;
        SetScale¹Command& operator=(const SetScale¹Command&) = delete;
        SetScale¹Command& operator=(SetScale¹Command&&) = delete;
    };
}
