////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition¹ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetPosition¹, SpatialCommand)
    public:
        SetPosition¹(const Header&, const Vector1D&);
    
        const Vector1D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPosition¹(const SetPosition¹&, const Header&);
        ~SetPosition¹();

    private:
        Vector1D const  m_position;
        
        SetPosition¹(const SetPosition¹&) = delete;
        SetPosition¹(SetPosition¹&&) = delete;
        SetPosition¹& operator=(const SetPosition¹&) = delete;
        SetPosition¹& operator=(SetPosition¹&&) = delete;
    };
}
