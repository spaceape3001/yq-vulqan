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
    class MultiplyPosition³ : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPosition³, PositionCommand)
    public:
        MultiplyPosition³(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPosition³(const MultiplyPosition³&, const Header&);
        MultiplyPosition³(const Header&);
        ~MultiplyPosition³();

    private:
        Vector3D  m_δ;
        
        MultiplyPosition³(const MultiplyPosition³&) = delete;
        MultiplyPosition³(MultiplyPosition³&&) = delete;
        MultiplyPosition³& operator=(const MultiplyPosition³&) = delete;
        MultiplyPosition³& operator=(MultiplyPosition³&&) = delete;
    };
}
