////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPosition³DCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition³DCommand, PositionCommand)
    public:
        AddPosition³DCommand(const Header&, const Vector3D&Δ);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition³DCommand(const AddPosition³DCommand&, const Header&);
        AddPosition³DCommand(const Header&);
        ~AddPosition³DCommand();
        
    private:
        Vector3D  m_Δ = ZERO;
        
        AddPosition³DCommand(const AddPosition³DCommand&) = delete;
        AddPosition³DCommand(AddPosition³DCommand&&) = delete;
        AddPosition³DCommand& operator=(const AddPosition³DCommand&) = delete;
        AddPosition³DCommand& operator=(AddPosition³DCommand&&) = delete;
    };
}
