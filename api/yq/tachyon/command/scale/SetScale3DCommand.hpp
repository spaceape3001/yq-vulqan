////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class SetScale³DCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScale³DCommand, ScaleCommand)
    public:
        SetScale³DCommand(const Header&, const Vector3D&);
    
        const Vector3D&   scale() const  { return m_scale; }
        
        static void init_meta();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        double  z() const { return m_scale.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetScale³DCommand(const Header&);
        SetScale³DCommand(const SetScale³DCommand&, const Header&);
        ~SetScale³DCommand();

    private:
        Vector3D  m_scale = ZERO;
        
        SetScale³DCommand(const SetScale³DCommand&) = delete;
        SetScale³DCommand(SetScale³DCommand&&) = delete;
        SetScale³DCommand& operator=(const SetScale³DCommand&) = delete;
        SetScale³DCommand& operator=(SetScale³DCommand&&) = delete;
    };
}
