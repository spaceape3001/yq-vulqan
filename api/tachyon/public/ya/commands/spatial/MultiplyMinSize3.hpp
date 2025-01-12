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
    class MultiplyMinSize³ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSize³, SpatialCommand)
    public:
        MultiplyMinSize³(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSize³(const MultiplyMinSize³&, const Header&);
        MultiplyMinSize³(const Header&);
        ~MultiplyMinSize³();

    private:
        Vector3D  m_δ;
        
        MultiplyMinSize³(const MultiplyMinSize³&) = delete;
        MultiplyMinSize³(MultiplyMinSize³&&) = delete;
        MultiplyMinSize³& operator=(const MultiplyMinSize³&) = delete;
        MultiplyMinSize³& operator=(MultiplyMinSize³&&) = delete;
    };
}
