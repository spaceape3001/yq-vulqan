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
    class MultiplySize³ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplySize³, SpatialCommand)
    public:
        MultiplySize³(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySize³(const MultiplySize³&, const Header&);
        MultiplySize³(const Header&);
        ~MultiplySize³();

    private:
        Vector3D  m_δ;
        
        MultiplySize³(const MultiplySize³&) = delete;
        MultiplySize³(MultiplySize³&&) = delete;
        MultiplySize³& operator=(const MultiplySize³&) = delete;
        MultiplySize³& operator=(MultiplySize³&&) = delete;
    };
}
