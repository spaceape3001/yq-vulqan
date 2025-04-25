////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/AABBCommand.hpp>
#include <yq/shape/AxBox1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetAABB¹ : public AABBCommand {
        YQ_OBJECT_DECLARE(SetAABB¹, AABBCommand)
    public:
        SetAABB¹(const Header&, const AxBox1D&);
    
        const AxBox1D&   aabb() const  { return m_aabb; }
        
        static void init_info();
        
        double  lx() const { return m_aabb.lo.x; }
        double  hx() const { return m_aabb.hi.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetAABB¹();
        SetAABB¹(const SetAABB¹&, const Header&);
    
    private:
        AxBox1D  m_aabb;
        
        SetAABB¹(const SetAABB¹&) = delete;
        SetAABB¹(SetAABB¹&&) = delete;
        SetAABB¹& operator=(const SetAABB¹&) = delete;
        SetAABB¹& operator=(SetAABB¹&&) = delete;
    };
}
