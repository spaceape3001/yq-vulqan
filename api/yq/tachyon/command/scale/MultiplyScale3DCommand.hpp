////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyScale³DCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScale³DCommand, ScaleCommand)
    public:
        MultiplyScale³DCommand(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScale³DCommand(const MultiplyScale³DCommand&, const Header&);
        MultiplyScale³DCommand(const Header&);
        ~MultiplyScale³DCommand();

    private:
        Vector3D  m_δ;
        
        MultiplyScale³DCommand(const MultiplyScale³DCommand&) = delete;
        MultiplyScale³DCommand(MultiplyScale³DCommand&&) = delete;
        MultiplyScale³DCommand& operator=(const MultiplyScale³DCommand&) = delete;
        MultiplyScale³DCommand& operator=(MultiplyScale³DCommand&&) = delete;
    };
}
