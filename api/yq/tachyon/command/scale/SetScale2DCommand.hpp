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
    class SetScale²DCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScale²DCommand, ScaleCommand)
    public:
        SetScale²DCommand(const Header&, const Vector2D&);
    
        const Vector2D&   scale() const  { return m_scale; }
        
        static void init_meta();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        SetScale²DCommand(const SetScale²DCommand&, const Header&);
        ~SetScale²DCommand();

    private:
        Vector2D  m_scale;
        
        SetScale²DCommand(const SetScale²DCommand&) = delete;
        SetScale²DCommand(SetScale²DCommand&&) = delete;
        SetScale²DCommand& operator=(const SetScale²DCommand&) = delete;
        SetScale²DCommand& operator=(SetScale²DCommand&&) = delete;
    };
}
