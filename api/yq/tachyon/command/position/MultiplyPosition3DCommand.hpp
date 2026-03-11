////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyPosition³DCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPosition³DCommand, PositionCommand)
    public:
        MultiplyPosition³DCommand(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPosition³DCommand(const MultiplyPosition³DCommand&, const Header&);
        MultiplyPosition³DCommand(const Header&);
        ~MultiplyPosition³DCommand();

    private:
        Vector3D  m_δ;
        
        MultiplyPosition³DCommand(const MultiplyPosition³DCommand&) = delete;
        MultiplyPosition³DCommand(MultiplyPosition³DCommand&&) = delete;
        MultiplyPosition³DCommand& operator=(const MultiplyPosition³DCommand&) = delete;
        MultiplyPosition³DCommand& operator=(MultiplyPosition³DCommand&&) = delete;
    };
}
