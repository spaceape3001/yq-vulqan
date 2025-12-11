////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class SetScale²Command : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScale²Command, ScaleCommand)
    public:
        SetScale²Command(const Header&, const Vector2D&);
    
        const Vector2D&   scale() const  { return m_scale; }
        
        static void init_meta();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        SetScale²Command(const SetScale²Command&, const Header&);
        ~SetScale²Command();

    private:
        Vector2D  m_scale;
        
        SetScale²Command(const SetScale²Command&) = delete;
        SetScale²Command(SetScale²Command&&) = delete;
        SetScale²Command& operator=(const SetScale²Command&) = delete;
        SetScale²Command& operator=(SetScale²Command&&) = delete;
    };
}
