////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/AABBCommand.hpp>
#include <yq/shape/AxBox2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetAABB² : public AABBCommand {
        YQ_OBJECT_DECLARE(SetAABB², AABBCommand)
    public:
        SetAABB²(const Header&, const AxBox2D&);
    
        const AxBox2D&   aabb() const  { return m_aabb; }
        
        static void init_info();
        
        double  lx() const { return m_aabb.lo.x; }
        double  ly() const { return m_aabb.lo.y; }
        
        double  hx() const { return m_aabb.hi.x; }
        double  hy() const { return m_aabb.hi.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetAABB²();
        SetAABB²(const SetAABB²&, const Header&);
    
    private:
        AxBox2D  m_aabb;
        
        SetAABB²(const SetAABB²&) = delete;
        SetAABB²(SetAABB²&&) = delete;
        SetAABB²& operator=(const SetAABB²&) = delete;
        SetAABB²& operator=(SetAABB²&&) = delete;
    };
}
