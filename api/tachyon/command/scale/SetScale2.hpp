////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class SetScale² : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScale², ScaleCommand)
    public:
        SetScale²(const Header&, const Vector2D&);
    
        const Vector2D&   scale() const  { return m_scale; }
        
        static void init_info();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        SetScale²(const SetScale²&, const Header&);
        ~SetScale²();

    private:
        Vector2D  m_scale;
        
        SetScale²(const SetScale²&) = delete;
        SetScale²(SetScale²&&) = delete;
        SetScale²& operator=(const SetScale²&) = delete;
        SetScale²& operator=(SetScale²&&) = delete;
    };
}
