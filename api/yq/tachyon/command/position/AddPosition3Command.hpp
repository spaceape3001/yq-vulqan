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
    class AddPosition³Command : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition³Command, PositionCommand)
    public:
        AddPosition³Command(const Header&, const Vector3D&Δ);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition³Command(const AddPosition³Command&, const Header&);
        AddPosition³Command(const Header&);
        ~AddPosition³Command();
        
    private:
        Vector3D  m_Δ = ZERO;
        
        AddPosition³Command(const AddPosition³Command&) = delete;
        AddPosition³Command(AddPosition³Command&&) = delete;
        AddPosition³Command& operator=(const AddPosition³Command&) = delete;
        AddPosition³Command& operator=(AddPosition³Command&&) = delete;
    };
}
