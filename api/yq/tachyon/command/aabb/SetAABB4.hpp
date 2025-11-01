////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/AABBCommand.hpp>
#include <yq/shape/AxBox4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetAABB⁴ : public AABBCommand {
        YQ_OBJECT_DECLARE(SetAABB⁴, AABBCommand)
    public:
        SetAABB⁴(const Header&, const AxBox4D&);
    
        const AxBox4D&   aabb() const  { return m_aabb; }
        
        static void init_meta();
        
        double  lx() const { return m_aabb.lo.x; }
        double  ly() const { return m_aabb.lo.y; }
        double  lz() const { return m_aabb.lo.z; }
        double  lw() const { return m_aabb.lo.w; }
        
        double  hx() const { return m_aabb.hi.x; }
        double  hy() const { return m_aabb.hi.y; }
        double  hz() const { return m_aabb.hi.z; }
        double  hw() const { return m_aabb.hi.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetAABB⁴();
        SetAABB⁴(const SetAABB⁴&, const Header&);
    
    private:
        AxBox4D  m_aabb;
        
        SetAABB⁴(const SetAABB⁴&) = delete;
        SetAABB⁴(SetAABB⁴&&) = delete;
        SetAABB⁴& operator=(const SetAABB⁴&) = delete;
        SetAABB⁴& operator=(SetAABB⁴&&) = delete;
    };
}
