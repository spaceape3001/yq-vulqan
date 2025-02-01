////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyScale³ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplyScale³, SpatialCommand)
    public:
        MultiplyScale³(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScale³(const MultiplyScale³&, const Header&);
        MultiplyScale³(const Header&);
        ~MultiplyScale³();

    private:
        Vector3D  m_δ;
        
        MultiplyScale³(const MultiplyScale³&) = delete;
        MultiplyScale³(MultiplyScale³&&) = delete;
        MultiplyScale³& operator=(const MultiplyScale³&) = delete;
        MultiplyScale³& operator=(MultiplyScale³&&) = delete;
    };
}
