////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class SetScale⁴DCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScale⁴DCommand, ScaleCommand)
    public:
        SetScale⁴DCommand(const Header&, const Vector4D&);
    
        const Vector4D&   scale() const  { return m_scale; }
        
        static void init_meta();
        
        double  w() const { return m_scale.w; }
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        double  z() const { return m_scale.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetScale⁴DCommand(const Header&);
        SetScale⁴DCommand(const SetScale⁴DCommand&, const Header&);
        ~SetScale⁴DCommand();

    private:
        Vector4D  m_scale = ZERO;
        
        SetScale⁴DCommand(const SetScale⁴DCommand&) = delete;
        SetScale⁴DCommand(SetScale⁴DCommand&&) = delete;
        SetScale⁴DCommand& operator=(const SetScale⁴DCommand&) = delete;
        SetScale⁴DCommand& operator=(SetScale⁴DCommand&&) = delete;
    };
}
