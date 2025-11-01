////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/AABBCommand.hpp>
#include <yq/shape/AxBox3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetAABB³ : public AABBCommand {
        YQ_OBJECT_DECLARE(SetAABB³, AABBCommand)
    public:
        SetAABB³(const Header&, const AxBox3D&);
    
        const AxBox3D&   aabb() const  { return m_aabb; }
        
        static void init_meta();
        
        double  lx() const { return m_aabb.lo.x; }
        double  ly() const { return m_aabb.lo.y; }
        double  lz() const { return m_aabb.lo.z; }
        
        double  hx() const { return m_aabb.hi.x; }
        double  hy() const { return m_aabb.hi.y; }
        double  hz() const { return m_aabb.hi.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetAABB³();
        SetAABB³(const SetAABB³&, const Header&);
    
    private:
        AxBox3D  m_aabb;
        
        SetAABB³(const SetAABB³&) = delete;
        SetAABB³(SetAABB³&&) = delete;
        SetAABB³& operator=(const SetAABB³&) = delete;
        SetAABB³& operator=(SetAABB³&&) = delete;
    };
}
