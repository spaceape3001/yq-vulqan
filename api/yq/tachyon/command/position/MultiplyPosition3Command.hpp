////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyPosition³Command : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPosition³Command, PositionCommand)
    public:
        MultiplyPosition³Command(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPosition³Command(const MultiplyPosition³Command&, const Header&);
        MultiplyPosition³Command(const Header&);
        ~MultiplyPosition³Command();

    private:
        Vector3D  m_δ;
        
        MultiplyPosition³Command(const MultiplyPosition³Command&) = delete;
        MultiplyPosition³Command(MultiplyPosition³Command&&) = delete;
        MultiplyPosition³Command& operator=(const MultiplyPosition³Command&) = delete;
        MultiplyPosition³Command& operator=(MultiplyPosition³Command&&) = delete;
    };
}
