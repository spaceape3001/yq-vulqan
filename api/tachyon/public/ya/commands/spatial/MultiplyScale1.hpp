////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class MultiplyScale¹ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplyScale¹, SpatialCommand)
    public:
        MultiplyScale¹(const Header&, const Vector1D&);
    
        const Vector1D&   scale() const  { return m_scale; }
        
        static void init_info();
        
        double  x() const { return m_scale.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplyScale¹();
        MultiplyScale¹(const MultiplyScale¹&, const Header&);
    

    private:
        Vector1D const  m_scale;
        
        MultiplyScale¹(const MultiplyScale¹&) = delete;
        MultiplyScale¹(MultiplyScale¹&&) = delete;
        MultiplyScale¹& operator=(const MultiplyScale¹&) = delete;
        MultiplyScale¹& operator=(MultiplyScale¹&&) = delete;
    };
}
